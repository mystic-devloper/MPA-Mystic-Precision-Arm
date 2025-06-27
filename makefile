#==============================================================================
# Makefile for the MPA (Mystic Precision Arm) Library
#
# This Makefile supports building the MPA library for various ARM architectures
# and provides cross-compilation capabilities.
#
# Supported Architectures:
#   - ARMv7-A (32-bit): Outputs libmpa32_armv7.a
#   - ARMv8-A (64-bit): Outputs libmpa64_armv8.a
#   - ARMv9-A (64-bit): Outputs libmpa64_armv9.a
#
# Features:
#   - Configurable compiler (Clang or GCC)
#   - Selectable target ARM architecture
#   - Cross-compilation support with configurable toolchain and sysroot
#   - Release and Debug build configurations
#   - Automatic dependency generation for faster incremental builds
#==============================================================================

#------------------------------------------------------------------------------
# Configuration Variables
#------------------------------------------------------------------------------

# Define the preferred compiler.
# Supported compilers:
#   - clang: Clang compiler family suite
#   - gcc: GNU compiler family suite
# Default: clang
COMPILER ?= clang

# Define the C++ compiler based on the chosen compiler suite.
# This variable will be adjusted for cross-compilation if applicable.
ifeq ($(COMPILER), clang)
        CXX = clang++
else ifeq ($(COMPILER), gcc)
        CXX = g++
else
        $(error Invalid COMPILER specified. Supported values: clang, gcc.)
endif

# Define the targeted ARM architecture version.
# Supported architectures:
#   - ARMv9: For 64-bit ARMv9-A
#   - ARMv8: For 64-bit ARMv8-A
#   - ARMv7: For 32-bit ARMv7-A
# Default: ARMv8
TARGET_VERSION ?= ARMv8

# Define the cross-compilation toolchain prefix.
# Examples:
#   - For 64-bit (ARMv9-A or ARMv8-A): `aarch64-linux-gnu`
#   - For 32-bit (ARMv7-A): `arm-linux-gnueabihf`
# Leave empty for native compilation.
# IMPORTANT: Ensure TARGET_VERSION matches the targeted cross-compilation system.
CROSS_COMPILE ?=

# Define the sysroot directory for cross-compilation.
# This is typically the root directory of the target's file system.
# Default: /usr/$(CROSS_COMPILE) (common for many Linux cross-toolchains)
SYSROOT ?= /usr/$(CROSS_COMPILE)

# Adjust CXX for cross-compilation if using GCC.
# For Clang, specific flags are added to COMPILER_FLAGS later.
ifeq ($(CROSS_COMPILE), )
    # No cross-compilation, CXX remains as defined above
else ifeq ($(CXX), g++)
    # For GCC, prefix the compiler with the cross-compile toolchain
    CXX := $(CROSS_COMPILE)-$(CXX)
else ifeq ($(CXX), clang++)
    # For Clang, cross-compilation flags are handled in COMPILER_FLAGS
    # No change to CXX itself here
else
    $(error Invalid CXX for cross-compilation. CXX must be clang++ or g++.)
endif

# Define the archiver tool used to create the static library.
# Default: ar
AR_BASE ?= ar
ifeq ($(CROSS_COMPILE), )
    AR := $(AR_BASE)
else
    AR := $(CROSS_COMPILE)-$(AR_BASE)
endif

# Define the flags for the archiver.
# r: insert or replace files
# c: create the archive
# s: write an object-file index into the archive (like ranlib)
ARFLAGS ?= rcs

# Define the build type of the library.
#   - Release: Optimized for maximum performance.
#   - Debug: Includes debugging symbols and no optimizations.
# Default: Release
BUILD ?= Release

# Define the names of the library artifacts for each architecture.
LIB32_ARMv7_TARGET ?= libmpa32_armv7.a
LIB64_ARMv8_TARGET ?= libmpa64_armv8.a
LIB64_ARMv9_TARGET ?= libmpa64_armv9.a

# Determine the final library name based on the selected TARGET_VERSION.
LIB_TARGET_NAME :=
ifeq ($(TARGET_VERSION), ARMv7)
    LIB_TARGET_NAME := $(LIB32_ARMv7_TARGET)
else ifeq ($(TARGET_VERSION), ARMv8)
    LIB_TARGET_NAME := $(LIB64_ARMv8_TARGET)
else ifeq ($(TARGET_VERSION), ARMv9)
    LIB_TARGET_NAME := $(LIB64_ARMv9_TARGET)
else
    $(error Invalid TARGET_VERSION specified. Supported values: ARMv7, ARMv8, ARMv9)
endif

# Define the output directory for the compiled library artifact.
# Default: lib
LIB_OUTPUT_DIR ?= lib

# Define the output directory for intermediate object files.
# Default: obj
OBJ_OUTPUT_DIR ?= obj

# Full path to the final library target archive.
ARCHIVE_TARGET := $(LIB_OUTPUT_DIR)/$(LIB_TARGET_NAME)

#------------------------------------------------------------------------------
# Source and Object File Definitions
#------------------------------------------------------------------------------

# Define source files based on the target architecture version.
SRCS_BASE := $(wildcard src/mpa/*.cpp)

SRCS :=
ifeq ($(TARGET_VERSION), ARMv9)
        SRCS := $(SRCS_BASE) $(wildcard src/mpa64/*.cpp)
else ifeq ($(TARGET_VERSION), ARMv8)
        SRCS := $(SRCS_BASE) $(wildcard src/mpa64/*.cpp)
else ifeq ($(TARGET_VERSION), ARMv7)
        SRCS := $(SRCS_BASE) $(wildcard src/mpa32/*.cpp)
else
        $(error Invalid TARGET_VERSION for source file selection. This should not happen if TARGET_VERSION is validated above.)
endif

# Generate a list of object file paths from source files.
# The `patsubst` function transforms 'src/dir/file.cpp' to 'obj/dir/file.o'.
OBJS := $(patsubst src/%.cpp,$(OBJ_OUTPUT_DIR)/%.o,$(SRCS))

#------------------------------------------------------------------------------
# Compiler Flags
#------------------------------------------------------------------------------

# Set up architecture-specific flags.
TARGET_VERSION_FLAG :=
ifeq ($(TARGET_VERSION), ARMv9)
  TARGET_VERSION_FLAG := -march=armv9-a
else ifeq ($(TARGET_VERSION), ARMv8)
  TARGET_VERSION_FLAG := -march=armv8-a
else ifeq ($(TARGET_VERSION), ARMv7)
  TARGET_VERSION_FLAG := -march=armv7-a
else
        $(error Invalid TARGET_VERSION for compiler flags. This should not happen.)
endif

# Base compiler flags applicable to both Release and Debug builds.
# -std=c++17: Use C++17 standard.
# -Wall -Wextra -pedantic: Enable extensive warnings and strict standard compliance.
# -fPIC: Generate Position-Independent Code, required for shared libraries.
# -mfpu=neon -mfloat-abi=hard: Specific ARM ABI settings for floating point.
# -Iinclude: Add the 'include' directory to the include path.
# -MMD -MP: Generate dependency files (.d) to track header dependencies.
COMPILER_FLAGS_BASE := \
                        -std=c++17 \
                        -Wall -Wextra -pedantic \
                        -fPIC \
                        $(TARGET_VERSION_FLAG) \
                        -mfpu=neon \
                        -mfloat-abi=hard \
                        -Iinclude \
                        -MMD -MP

# Define specific flags based on the BUILD type.
COMPILER_FLAGS :=
ifeq ($(BUILD), Release)
        COMPILER_FLAGS := $(COMPILER_FLAGS_BASE) -O3 -DNDEBUG
        # -O3: Aggressive optimization for performance.
        # -DNDEBUG: Define NDEBUG to disable assert statements.
else ifeq ($(BUILD), Debug)
        COMPILER_FLAGS := $(COMPILER_FLAGS_BASE) -O0 -g -DDEBUG
        # -O0: No optimization.
        # -g: Include debugging information.
        # -DDEBUG: Define DEBUG for conditional compilation of debug-specific code.
else
        $(error Invalid BUILD specified. Supported values: Release, Debug.)
endif

# Add cross-compilation specific flags for Clang if CROSS_COMPILE is set.
# GCC handles cross-compilation via the CXX prefix, as defined above.
ifeq ($(CROSS_COMPILE), )
    # No cross-compilation, no extra flags needed
else ifeq ($(COMPILER), clang)
    COMPILER_FLAGS := $(COMPILER_FLAGS) --target=$(CROSS_COMPILE) --sysroot=$(SYSROOT)
endif

#------------------------------------------------------------------------------
# Linker Flags (if creating an executable, not strictly for a static lib)
#------------------------------------------------------------------------------

# Linker flags. For a static library, these are typically not used in the archiving step.
# They would be used by an application linking against this static library.
# Common examples,
# -pthread: Link with POSIX threads library.
# -lm: Link with the math library.
LDFLAGS ?=

#------------------------------------------------------------------------------
# Phony Targets
#------------------------------------------------------------------------------

.PHONY: all clean library

# The default target. Builds the static library.
all: library

# Target to build the static library.
library: $(ARCHIVE_TARGET)

#------------------------------------------------------------------------------
# Build Rules
#------------------------------------------------------------------------------

# Rule to create output directories if they do not exist.
# The '|' makes these order-only prerequisites, meaning the rule will run
# only if the directories don't exist, but changes to them won't trigger rebuilds.
$(LIB_OUTPUT_DIR) $(OBJ_OUTPUT_DIR):
        @echo "Creating directory: $@"
        mkdir -p $@

# Rule to compile each source file into an object file.
# The '| $(OBJ_OUTPUT_DIR)' ensures the base object directory exists.
# `mkdir -p $(dir $@)` creates any necessary subdirectories (e.g., obj/mpa64).
$(OBJ_OUTPUT_DIR)/%.o: src/%.cpp | $(OBJ_OUTPUT_DIR)
        @mkdir -p $(dir $@)
        @echo "Compiling $< to $@"
        $(CXX) $(COMPILER_FLAGS) -c $< -o $@

# Rule to archive all object files into the static library.
# The '| $(LIB_OUTPUT_DIR)' ensures the library output directory exists.
# `rcs`: Replace existing members, create if doesn't exist, create a symbol table.
$(ARCHIVE_TARGET): $(OBJS) | $(LIB_OUTPUT_DIR)
        @echo "Archiving $(notdir $^) into $(notdir $@)"
        $(AR) $(ARFLAGS) $@ $^

# Include automatically generated dependency files.
# These files track header changes and ensure recompilation when headers change.
-include $(OBJS:.o=.d)

#------------------------------------------------------------------------------
# Clean Target
#------------------------------------------------------------------------------

# Remove all generated build artifacts (object files and the final library).
clean:
        @echo "Cleaning up build artifacts..."
        rm -rf $(OBJ_OUTPUT_DIR) $(LIB_OUTPUT_DIR)


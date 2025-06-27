# How to Use the Examples

---

Welcome to the `tests` directory! This guide will walk you through compiling and running the test programs using either **Clang** or **GCC/G++**.

---

## Prerequisites
* Download and setup your prefered compiler (e.g. `clang` or `gcc/g++`)
* Download and setup `googletest` (a.k.a `gtest`)
* Download the library source code zip and unzip it into a folder (for example `mpa-tests` if only desires `tests`)

## Quick Start: Compiling an Example

Compiling a test is straightforward. You'll need to specify your chosen compiler, the source files, and a name for your executable output, and some linker args.

---

### For Clang Users:

```bash
clang++ [YOUR_TEST_FILE].cpp ../src/[TEST_SOURCE_CODE].cpp -o [YOUR_OUTPUT_NAME] -I../include -I[YOUR_USR_INCLUDE_DIR] -L[YOUR_USR_LIB_DIR] -lgtest -lgtest_main -pthread
```

### For GCC/G++ Users:

```bash

g++ [YOUR_TEST_FILE].cpp ../src/[TEST_SOURCE_CODE].cpp -o [YOUR_OUTPUT_NAME] -I../include -I[YOUR_USR_INCLUDE_DIR] -L[YOUR_USR_LIB_DIR] -lgtest -lgtest_main -pthread
```

---

### Run executable via:

```bash
./[YOUR_OUTPUT_NAME]
```

---

## Understanding the command
Let's break down each part of the compilation command:
* `clang++` or `g++`: These are your C++ compilers. Choose the one you have installed and prefer.
* `[YOUR_TEST_FILE].cpp`: This is the specific test file you want to compile. For instance, if you want to compile an example named `basic_test.cpp`, you'd replace `[YOUR_EXAMPLE_FILE].cpp` with `basic_test.cpp`.
* `../src/[TEST_SOURCE_CODE]`: The orignal code on which you want to run the tests. For instance, if you want to test `/src/mpa/basic_usage.cpp`, you'd replace `[TEST_SOURCE_CODE]` with `mpa/basic_usage.cpp`.
* `-o [YOUR_OUTPUT_NAME]`: The `-o` flag specifies the name of the executable file that will be created after successful compilation. You can name it anything you like, such as `my_program`, `test_app`, or `demo`.
* `-I../include`: This flag tells the compiler to look for header files (e.g., `.h` or `.hpp` files) in the `../include` directory (one level up from the `examples` directory, then into the `include` folder). This is essential because the examples might use headers from the main project's include path.
* `[YOUR_USR_INCLUDE_DIR]`: The path to to usr include directory where `gtest` include folder resides. Common format is `/usr/include`.
* `[YOUR_USR_LIB_DIR]`: The path to to usr lib directory where `libgtest.so` and other gtest lib files resides. Common format is `/usr/local/lib`.
* `-lgtest -lgtest-main`: Linking flags to link against `gtest` and `gtest main`.
* `-pthread`: Use posix threads.
---

## Example Usage
Let's say you want to compile an test file called `hello_world_test.cpp` that tests `src/mpa/hello_world.cpp` and name the executable `hello`:

---

### For Clang Users:

```bash
clang++ hello_world_test.cpp ../src/mpa/hello_world.cpp -o hello -I../include -I/usr/include -L/usr/local/lib -lgtest -lgtest-main -pthread
```

### For GCC/G++ Users:
```bash
g++ hello_world_test.cpp ../src/mpa/hello_world.cpp -o hello -I../include -I/usr/include -L/usr/local/lib -lgtest -lgtest-main -pthread
```

---

After compilation, you can run your executable:

### Run executable via:

```bash
./hello
```

---

Feel free to explore the different test files and experiment with them. If you encounter any issues, **double-check** your file paths and ensure `gtest` is setup correctly and included.

If problem presists feel free to open a **discussion**.

**Happy Coding!**

---
***mystic-devloper***

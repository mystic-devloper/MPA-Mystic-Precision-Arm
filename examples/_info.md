# How to Use the Examples

---

Welcome to the `examples` directory! This guide will walk you through compiling and running the example programs using either **Clang** or **GCC/G++**.

---

## Prerequisites
* Download and setup your prefered compiler (e.g. `clang` or 

## Quick Start: Compiling an Example

Compiling an example is straightforward. You'll need to specify your chosen compiler, the source files, and a name for your executable output. Remember to always include `example_function.cpp`.

---

### For Clang Users:

```bash
clang++ example_function.cpp [YOUR_EXAMPLE_FILE].cpp -o [YOUR_OUTPUT_NAME] -I../include
```

### For GCC/G++ Users:

```bash
g++ example_function.cpp [YOUR_EXAMPLE_FILE].cpp -o [YOUR_OUTPUT_NAME] -I../include
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
* `example_function.cpp`: This file is **crucial**! Many examples rely on common utility function or setup code defined within `example_function.cpp`. Always include it in your compilation command.
* `[YOUR_EXAMPLE_FILE].cpp`: This is the specific example source file you want to compile. For instance, if you want to compile an example named `basic_usage.cpp`, you'd replace `[YOUR_EXAMPLE_FILE].cpp` with `basic_usage.cpp`.
* `-o [YOUR_OUTPUT_NAME]`: The `-o` flag specifies the name of the executable file that will be created after successful compilation. You can name it anything you like, such as `my_program`, `test_app`, or `demo`.
* `-I../include`: This flag tells the compiler to look for header files (e.g., `.h` or `.hpp` files) in the `../include` directory (one level up from the `examples` directory, then into the `include` folder). This is essential because the examples might use headers from the main project's include path.

---

## Example Usage
Let's say you want to compile an example file called `hello_world_example.cpp` and name the executable `hello`:

---

### For Clang Users:

```bash
clang++ example_function.cpp hello_world_example.cpp -o hello -I../include
```

### For GCC/G++ Users:
```bash
g++ example_function.cpp hello_world_example.cpp -o hello -I../include
```

---

After compilation, you can run your executable:

### Run executable via:

```bash
./hello
```

---

Feel free to explore the different example files and experiment with them. If you encounter any issues, **double-check** your file paths and ensure `example_function.cpp` is included.

If problem presists feel free to open a **discussion**.

**Happy Coding!**

---
***mystic-devloper***

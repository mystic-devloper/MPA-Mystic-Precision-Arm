# Mystic-Precision-Arm (MPA)

## 🌟 Overview

Mystic-Precision-Arm (MPA) is a cutting-edge, multiple-precision lightweight math library meticulously crafted for ARM processors. Designed with efficiency and versatility in mind, MPA empowers developers to perform high-precision arithmetic operations on resource-constrained ARM devices, opening up a myriad of possibilities across various applications.

Whether you're working on cryptographic algorithms, scientific simulations, or embedded systems requiring enhanced numerical accuracy, MPA provides the robust and optimized mathematical foundation you need.

## ✨ Features

* **Multiple Precision Arithmetic:** Go beyond standard fixed-precision limits. MPA supports arbitrary-precision integers and floating-point numbers, allowing you to achieve the exact level of precision your application demands.
* **Lightweight Design:** Optimized for ARM architecture, MPA boasts a minimal footprint and efficient performance, making it ideal for embedded systems and other memory-sensitive environments.
* **High Performance:** Leveraging the ARM instruction set, MPA is engineered for speed, ensuring your high-precision computations are executed quickly and efficiently.
* **Versatile Applications:** Suitable for a wide range of uses, including:
    * Cryptography (e.g., RSA, ECC)
    * Scientific Computing
    * Financial Applications
    * Embedded Systems
    * Digital Signal Processing
    * Games and Graphics
* **Easy to Integrate:** Designed with developer experience in mind, MPA offers a clean and intuitive API for seamless integration into your ARM projects.

## 🚀 Getting Started

### Prerequisites

To build and use MPA, you will need:

* An ARM-compatible toolchain (e.g., GCC for ARM, Clang)
* Make (or your preferred build system)

### Building MPA

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/mystic-devloper/MPA-Mystic-Precision-Arm.git
    cd MPA-Mystic-Precision-Arm
    ```
2.  **Build the library:**
    First make sure and see in makefile that you are building for correct OS bits.
    ```bash
    make
    ```
    This will compile the library and generate the necessary artifacts (e.g., `libmpa.a` for 64 bits and `libmpa32.a` for 32 bits).

## Important Note
This library is native for 64 bits but also has extensive support for 32 bits.
Classes or types such as mpa_int_t, mpa_float_t, etc are 64 bits.
and mpa32_int_t, mpa32_int_t, etc are 32 bits.

## Contributions
This project welcomes contributions and if you are interested feel free to contribute!

## LICENCE
This project is under MIT Open Source Licence. For full information read LICENCE.

## Contributors
* Mystic-Devloper

  ... Waiting for more! Come on!

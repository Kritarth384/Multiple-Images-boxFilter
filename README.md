# Multiple Images BoxFilter

This project provides a C++ program to apply a box filter to multiple PGM images using CUDA and NPP. The program takes an input directory containing PGM images, applies a box filter to each image, and saves the filtered images in a specified output directory.

## Requirements

- C++17 compatible compiler (e.g., g++)
- NVIDIA CUDA Toolkit
- OpenCV library
- Make

## Building the Program

To compile the program, use the provided `Makefile`. The Makefile will handle the compilation process using `g++`, CUDA, and the necessary OpenCV flags.


### Steps to Build:

1. Open a terminal.
2. Navigate to the directory containing the `Makefile` and the source code.
3. Run the following command to compile the program:

   ```sh
   make clean build
4. Then run the final command.

   ```sh
   make run
   



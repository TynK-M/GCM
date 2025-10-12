# GCM

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Overview

**GCM** is a C library created primarily for study purposes.  
It is **not intended to be optimal, production-ready, or universally integrated**.  
If, for any reason, you decide to use it and encounter issues, please [open an issue](https://github.com/TynK-M/GCM/issues).

## Philosophy & Disclaimer

This library is meant for learning and experimentation in matrix manipulation and basic linear algebra in C.  
It may lack optimizations, broad compatibility, or advanced error handling common in mature libraries.

**If you find any problem, or have suggestions or improvements, please open an issue.**

## Features

- Matrix structure and basic operations (addition, pretty-printing, allocation)
- Simple, readable code for educational use
- 100% C codebase

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`, `clang`, or MSVC)

### Building

Compile manually:

```sh
gcc main.c -o gcm 
```

*(Replace `main.c` with your actual source file; see below for structure.)*

### Usage

After building, run the executable:

```sh
./gcm
```

## Project Structure

```
.
├── GCM/
|   └── matrices/      # Matrix-related headers and source files  |       └── matrices.h
├── .gitignore
├── LICENSE
└── README.md
```

## Contributing

Contributing is not open right know, but feel free to fork the repository and do what you want.

## License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## Contact

For questions or support, [open an issue](https://github.com/TynK-M/GCM/issues).
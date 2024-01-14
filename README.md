<p align="center">
  <img src="https://github.com/vvaucoul/Hephaistos/assets/66129673/925850fc-6e1f-4401-8025-149995fb520d" width="100%">
</p>

# Hephaistos

A comprehensive library for the **[KronOS](https://github.com/vvaucoul/KronOS)** kernel.

## Prerequisites

To use or contribute to Hephaistos, the following tools are required:

- **GCC**: The GNU Compiler Collection.
- **CLANG**: A compiler front-end for C, C++, Objective-C, and Objective-C++.
- **KVM**: Kernel-based Virtual Machine for virtualization.
- **QEMU**: An open-source hardware virtualization tool.

## Building

Hephaistos is integrated with the **[KronOS](https://github.com/vvaucoul/KronOS)** build system, utilizing a custom setup to streamline the process. Building Hephaistos is seamlessly handled as part of the KronOS compilation. Follow these steps to build Hephaistos along with KronOS:

1. Clone the KronOS repository: `git clone --recursive [KronOS Repository URL](https://github.com/vvaucoul/KronOS)`
2. Navigate to the KronOS directory: `cd KronOS`
3. Build KronOS: `make`
4. Build Verification: Upon completion, verify that Hephaistos libraries and modules are compiled and integrated as expected.

## Customizing the Build

Hephaistos allows for certain customizations such as enabling/disabling specific modules. Refer to the KronOS and Hephaistos configuration files for more information on how to customize your build.

## Optional Tools

These tools are not mandatory but can enhance the development experience:

- **CCACHE**: A compiler cache that can speed up recompilation.
- **GNU XORRISO**: A tool to create, modify, and extract from ISO 9660 filesystem images.

## Project Structure

The project is structured into multiple parts:

- **Library**: The main component, Hephaistos.
- **Data Transfer**: Charon, a submodule focused on efficient data transfer.

## Hephaistos Library

The Hephaistos library contains several submodules, each focusing on specific kernel functionalities. Below is a brief description of each submodule:

| Submodule  | Description                                             |
|------------|---------------------------------------------------------|
| algorithms | Implements common algorithms like B+ Trees, B Trees, Hash Tables, Lists, Queues, RB Trees, and Sorting algorithms. |
| assert     | Provides functions for asserting conditions.            |
| bit        | Contains functions for bit manipulation.                |
| convert    | Provides functions for data type conversions.           |
| cpu        | Contains functions for CPU interactions.                |
| ctype      | Provides functions for character classification.        |
| errno      | Defines error codes.                                    |
| macros     | Contains useful macros.                                 |
| memory     | Provides functions for memory management.               |
| stdarg     | Functions for manipulating function arguments.          |
| stdbool    | Defines the boolean data type.                          |
| stddef     | Defines common data types and macros.                   |
| stdio      | Provides Input/Output functions.                        |
| string     | Functions for string manipulation.                      |
| time       | Functions for time manipulation.                        |


## Contributing

If you're interested in contributing to Hephaistos, please check out our [Contribution Guide](CONTRIBUTING.md) for more information.

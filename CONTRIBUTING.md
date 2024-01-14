# Contributing to Hephaistos

I am delighted that you are interested in contributing to Hephaistos! This document provides guidelines for contributions to the project. Whether you're submitting a bug report, proposing a new feature, or submitting a code change, your contribution is highly valued and appreciated.

## How to Contribute

1. **Fork the repository**: start by forking the repository on GitHub. This will create a copy of the repository in your own GitHub account.
2. **Clone the repository**: clone the repository to your local machine

```bash
git clone https://github.com/[YourUsername]/Hephaistos.git
cd Hephaistos
```

3. **Create a branch**: create a new branch to work on. It is recommended to name your branch after the issue you are working on.

```bash
git branch feature/my-new-feature
git checkout feature/my-new-feature
```

or

```bash
git branch bugfix/my-bug-fix
git checkout bugfix/my-bug-fix
```

1. **Make changes**: Implement your feature or fix and commit your changes with clear and concise commit messages. Be sure to follow the [Code Style](#code-style) guidelines.
2. **Test Your Changes**: Ensure your changes do not break existing functionality and that they meet the project's coding standards. (See [Testing](#testing) and [Code Style](#code-style))
3. **Pull Request**: Push your branch to your fork and open a pull request against the main Hephaistos repository. Provide a clear description of your changes and their purpose.

## Testing

Hephaistos uses the ([KronOS](https://github.com/vvaucoul/KronOS)) build system, which includes a testing framework. Tests are located in the `tests` directory. You can add new tests to the existing test files or create new test files. Tests are automatically run when building the project.

## Code Style

Hephaistos follows the [Linux Kernel Coding Style](https://www.kernel.org/doc/html/v4.10/process/coding-style.html).

## Reporting Issues

If you find a bug or have a suggestion for a new feature, please use the GitHub issue tracker. Before creating a new issue, check if it has already been reported or fixed in the main branch.

## Coding Guidelines

**Code Style**: Follow the established code style of the project.</br>
**Documentation**: Add comments and documentation to your code as needed.</br>
**Testing**: Add tests for new features and ensure that your changes do not break existing tests.</br>

## Community and Conduct

I aim to build a welcoming and inclusive community. Please adhere to our Code of Conduct in all your interactions with the project.

## License

By contributing to Hephaistos, you agree that your contributions will be licensed under its [MIT License](LICENSE).

## Questions and Support

If you have any questions or need help, feel free to reach out to me or use the community channels.

</br>

---

</br>

*Thank you for contributing to Hephaistos, and I look forward to seeing your contributions!*
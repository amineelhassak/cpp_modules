# 🚀 C++ Modules - Complete Learning Journey

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)]()

> A comprehensive collection of C++ modules covering fundamental to advanced concepts in modern C++ programming.

## 📚 Table of Contents

- [Overview](#overview)
- [Modules Overview](#modules-overview)
- [Getting Started](#getting-started)
- [Module Details](#module-details)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This repository contains a complete set of C++ modules designed to teach and demonstrate various concepts in C++ programming, from basic syntax and memory management to advanced topics like templates, containers, and algorithms. Each module focuses on specific concepts and includes practical examples and exercises.

## 📋 Modules Overview

| Module | Topic | Status | Description |
|--------|-------|--------|-------------|
| **cpp00** | Basic Syntax & I/O | ✅ Complete | Variables, namespaces, basic I/O operations |
| **cpp01** | Memory Management | ✅ Complete | `new`/`delete`, references, function overloading |
| **cpp02** | Classes & Operators | ✅ Complete | Orthodox canonical form, operator overloading |
| **cpp03** | Inheritance | ✅ Complete | Class inheritance, virtual functions |
| **cpp04** | Polymorphism | ✅ Complete | Abstract classes, interfaces, virtual methods |
| **cpp05** | Exceptions | ✅ Complete | Exception handling, try-catch blocks |
| **cpp06** | Type Casting | ✅ Complete | `static_cast`, `dynamic_cast`, type conversions |
| **cpp07** | Templates | ✅ Complete | Function templates, class templates |
| **cpp08** | STL Containers | ✅ Complete | Standard Template Library containers |
| **cpp09** | Algorithms | ✅ Complete | STL algorithms, advanced data structures |

## 🚀 Getting Started

### Prerequisites

- **Compiler**: GCC 7.3+ or Clang 6.0+
- **Make**: GNU Make 4.0+
- **OS**: Linux, macOS, or Windows (with WSL)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/cpp_modules.git
   cd cpp_modules
   ```

2. **Navigate to any module**
   ```bash
   cd cpp00/ex00
   ```

3. **Compile and run**
   ```bash
   make
   ./program_name
   ```

## 📖 Module Details

### 🎯 cpp00 - Basic Syntax & I/O
**Learning Objectives**: Basic C++ syntax, variables, namespaces, and I/O operations.

**Key Concepts**:
- Variable declarations and types
- Namespace usage (`std`)
- Basic input/output with `iostream`
- String manipulation
- Time functions (`time`, `localtime`)

**Exercises**:
- `ex00`: Megaphone program (string manipulation)
- `ex01`: PhoneBook class (basic class implementation)
- `ex02`: Account class (static members)

### 🧠 cpp01 - Memory Management
**Learning Objectives**: Dynamic memory allocation, references, and function overloading.

**Key Concepts**:
- `new` and `delete` operators
- References vs pointers
- Function overloading
- Default parameters
- Access specifiers

**Exercises**:
- `ex00`: Zombie class with memory allocation
- `ex01`: Zombie horde creation
- `ex02`: Pointers to member functions
- `ex03`: Weapon class with references
- `ex04`: File handling
- `ex05`: Harl class with function pointers
- `ex06`: Harl filter program

### 🏗️ cpp02 - Classes & Operators
**Learning Objectives**: Orthodox canonical form and operator overloading.

**Key Concepts**:
- Orthodox canonical form
- Copy constructor and assignment operator
- Operator overloading
- Fixed-point arithmetic
- IEEE 754 representation

**Exercises**:
- `ex00`: Fixed-point class (basic)
- `ex01`: Fixed-point arithmetic operations
- `ex02`: Fixed-point comparisons
- `ex03`: Point-in-triangle algorithm (BSP)

### 🔗 cpp03 - Inheritance
**Learning Objectives**: Class inheritance and virtual functions.

**Key Concepts**:
- Public, protected, and private inheritance
- Virtual functions
- Method overriding
- Base and derived classes

**Exercises**:
- `ex00`: ClapTrap class
- `ex01`: ScavTrap inheritance
- `ex02`: FragTrap inheritance
- `ex03`: DiamondTrap (multiple inheritance)

### 🎭 cpp04 - Polymorphism
**Learning Objectives**: Abstract classes, interfaces, and polymorphic behavior.

**Key Concepts**:
- Abstract classes
- Pure virtual functions
- Interfaces
- Polymorphism
- Virtual destructors

**Exercises**:
- `ex00`: Animal hierarchy with virtual functions
- `ex01`: Brain class with deep copying
- `ex02`: WrongAnimal demonstration
- `ex03`: Materia system (abstract classes)

### ⚠️ cpp05 - Exceptions
**Learning Objectives**: Exception handling and error management.

**Key Concepts**:
- Try-catch blocks
- Exception classes
- Custom exceptions
- Exception safety

**Exercises**:
- `ex00`: Bureaucrat class with exceptions
- `ex01`: Form class with validation
- `ex02`: Presidential forms hierarchy
- `ex03`: Intern class with form creation

### 🔄 cpp06 - Type Casting
**Learning Objectives**: C++ casting operators and type conversions.

**Key Concepts**:
- `static_cast`
- `dynamic_cast`
- `const_cast`
- `reinterpret_cast`
- Serialization

**Exercises**:
- `ex00`: ScalarConverter (type conversion)
- `ex01`: Serializer (data serialization)
- `ex02`: Base class identification

### 📝 cpp07 - Templates
**Learning Objectives**: Function and class templates.

**Key Concepts**:
- Function templates
- Class templates
- Template specialization
- Generic programming

**Exercises**:
- `ex00`: Template functions
- `ex01`: Template iterator
- `ex02`: Template array class

### 📦 cpp08 - STL Containers
**Learning Objectives**: Standard Template Library containers and algorithms.

**Key Concepts**:
- `std::vector`, `std::list`, `std::deque`
- `std::stack`, `std::queue`
- Container adapters
- Iterators
- Algorithms

**Exercises**:
- `ex00`: `easyfind` template function
- `ex01`: Span class
- `ex02`: MutantStack (custom container)

### ⚡ cpp09 - Algorithms
**Learning Objectives**: Advanced algorithms and data structures.

**Key Concepts**:
- Bitcoin exchange algorithm
- Reverse Polish Notation (RPN)
- Merge-insert sort
- Performance optimization

**Exercises**:
- `ex00`: BitcoinExchange (file processing)
- `ex01`: RPN Calculator
- `ex02`: PmergeMe (sorting algorithm)

## ✨ Features

- **Comprehensive Coverage**: From basic syntax to advanced algorithms
- **Practical Examples**: Each module includes working code examples
- **Progressive Learning**: Concepts build upon previous modules
- **Modern C++**: Uses contemporary C++ features and best practices
- **Well-Documented**: Detailed explanations and comments
- **Makefile Support**: Easy compilation and testing

## 🛠️ Technologies Used

- **Language**: C++98/03/11/14/17
- **Build System**: GNU Make
- **Compiler**: GCC/Clang
- **Version Control**: Git
- **Documentation**: Markdown

## 📁 Project Structure

```
cpp_modules/
├── cpp00/          # Basic syntax & I/O
│   ├── ex00/       # Megaphone
│   ├── ex01/       # PhoneBook
│   └── ex02/       # Account
├── cpp01/          # Memory management
│   ├── ex00/       # Zombie
│   ├── ex01/       # Zombie horde
│   ├── ex02/       # Pointers to members
│   ├── ex03/       # Weapon & Human
│   ├── ex04/       # File handling
│   ├── ex05/       # Harl
│   └── ex06/       # Harl filter
├── cpp02/          # Classes & operators
│   ├── ex00/       # Fixed-point basics
│   ├── ex01/       # Fixed-point arithmetic
│   ├── ex02/       # Fixed-point comparisons
│   └── ex03/       # BSP algorithm
├── cpp03/          # Inheritance
│   ├── ex00/       # ClapTrap
│   ├── ex01/       # ScavTrap
│   ├── ex02/       # FragTrap
│   └── ex03/       # DiamondTrap
├── cpp04/          # Polymorphism
│   ├── ex00/       # Animal hierarchy
│   ├── ex01/       # Brain class
│   ├── ex02/       # WrongAnimal
│   └── ex03/       # Materia system
├── cpp05/          # Exceptions
│   ├── ex00/       # Bureaucrat
│   ├── ex01/       # Form
│   ├── ex02/       # Presidential forms
│   └── ex03/       # Intern
├── cpp06/          # Type casting
│   ├── ex00/       # ScalarConverter
│   ├── ex01/       # Serializer
│   └── ex02/       # Base identification
├── cpp07/          # Templates
│   ├── ex00/       # Template functions
│   ├── ex01/       # Template iterator
│   └── ex02/       # Template array
├── cpp08/          # STL containers
│   ├── ex00/       # easyfind
│   ├── ex01/       # Span
│   └── ex02/       # MutantStack
└── cpp09/          # Algorithms
    ├── ex00/       # BitcoinExchange
    ├── ex01/       # RPN Calculator
    └── ex02/       # PmergeMe
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### How to Contribute

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **42 School**: For the comprehensive C++ curriculum
- **C++ Community**: For continuous improvements and best practices
- **STL Documentation**: For detailed container and algorithm references

---

<div align="center">

**Made with ❤️ for C++ enthusiasts**

[![GitHub stars](https://img.shields.io/github/stars/yourusername/cpp_modules?style=social)](https://github.com/yourusername/cpp_modules/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/cpp_modules?style=social)](https://github.com/yourusername/cpp_modules/network/members)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/cpp_modules)](https://github.com/yourusername/cpp_modules/issues)

</div> 
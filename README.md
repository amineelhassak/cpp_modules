# 🚀 C++ Modules - Complete Learning Journey

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)]()
[![Build](https://img.shields.io/badge/Build-Passing-success.svg)]()
[![Version](https://img.shields.io/badge/Version-1.0.0-blue.svg)]()

<div align="center">

# 🧠 C++ Learning Modules

> A comprehensive collection of C++ modules covering fundamental to advanced concepts in modern C++ programming.

**From basic syntax to advanced algorithms - Master C++ step by step!**

[![GitHub stars](https://img.shields.io/github/stars/yourusername/cpp_modules?style=social)](https://github.com/yourusername/cpp_modules/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/cpp_modules?style=social)](https://github.com/yourusername/cpp_modules/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/cpp_modules)](https://github.com/yourusername/cpp_modules/issues)

</div>

---

## 📚 Table of Contents

- [🎯 Overview](#-overview)
- [📋 Modules Overview](#-modules-overview)
- [🚀 Getting Started](#-getting-started)
- [📖 Module Details](#-module-details)
- [✨ Features](#-features)
- [🛠️ Technologies Used](#️-technologies-used)
- [📁 Project Structure](#-project-structure)
- [🎓 Learning Path](#-learning-path)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

## 🎯 Overview

This repository contains a **complete set of C++ modules** designed to teach and demonstrate various concepts in C++ programming, from basic syntax and memory management to advanced topics like templates, containers, and algorithms. Each module focuses on specific concepts and includes practical examples and exercises.

### 🎓 What You'll Learn

- **Fundamentals**: Variables, functions, classes, and basic I/O
- **Memory Management**: Dynamic allocation, references, and pointers
- **Object-Oriented Programming**: Inheritance, polymorphism, and encapsulation
- **Advanced Concepts**: Templates, STL, exceptions, and type casting
- **Algorithms**: Data structures, sorting, and optimization techniques

## 📋 Modules Overview

| Module | Topic | Status | Difficulty | Description |
|--------|-------|--------|------------|-------------|
| **[cpp00](#-cpp00---basic-syntax--io)** | Basic Syntax & I/O | ✅ Complete | 🟢 Beginner | Variables, namespaces, basic I/O operations |
| **[cpp01](#-cpp01---memory-management)** | Memory Management | ✅ Complete | 🟡 Intermediate | `new`/`delete`, references, function overloading |
| **[cpp02](#-cpp02---classes--operators)** | Classes & Operators | ✅ Complete | 🟡 Intermediate | Orthodox canonical form, operator overloading |
| **[cpp03](#-cpp03---inheritance)** | Inheritance | ✅ Complete | 🟡 Intermediate | Class inheritance, virtual functions |
| **[cpp04](#-cpp04---polymorphism)** | Polymorphism | ✅ Complete | 🟡 Intermediate | Abstract classes, interfaces, virtual methods |
| **[cpp05](#-cpp05---exceptions)** | Exceptions | ✅ Complete | 🟡 Intermediate | Exception handling, try-catch blocks |
| **[cpp06](#-cpp06---type-casting)** | Type Casting | ✅ Complete | 🟠 Advanced | `static_cast`, `dynamic_cast`, type conversions |
| **[cpp07](#-cpp07---templates)** | Templates | ✅ Complete | 🟠 Advanced | Function templates, class templates |
| **[cpp08](#-cpp08---stl-containers)** | STL Containers | ✅ Complete | 🟠 Advanced | Standard Template Library containers |
| **[cpp09](#-cpp09---algorithms)** | Algorithms | ✅ Complete | 🔴 Expert | STL algorithms, advanced data structures |

## 🚀 Getting Started

### Prerequisites

- **Compiler**: GCC 7.3+ or Clang 6.0+
- **Make**: GNU Make 4.0+
- **OS**: Linux, macOS, or Windows (with WSL)
- **Git**: For version control

### 🛠️ Installation

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

### 🧪 Testing

Each module includes comprehensive tests:

```bash
# Run all tests for a module
make test

# Run specific exercise
cd cpp00/ex00
make test
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

**Difficulty**: 🟢 Beginner

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

**Difficulty**: 🟡 Intermediate

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

**Difficulty**: 🟡 Intermediate

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

**Difficulty**: 🟡 Intermediate

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

**Difficulty**: 🟡 Intermediate

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

**Difficulty**: 🟡 Intermediate

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

**Difficulty**: 🟠 Advanced

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

**Difficulty**: 🟠 Advanced

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

**Difficulty**: 🟠 Advanced

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

**Difficulty**: 🔴 Expert

## ✨ Features

- **🎯 Comprehensive Coverage**: From basic syntax to advanced algorithms
- **💻 Practical Examples**: Each module includes working code examples
- **📈 Progressive Learning**: Concepts build upon previous modules
- **🚀 Modern C++**: Uses contemporary C++ features and best practices
- **📚 Well-Documented**: Detailed explanations and comments
- **🔧 Makefile Support**: Easy compilation and testing
- **🧪 Testing Framework**: Comprehensive test suites for each module
- **📖 Code Examples**: Real-world applications and use cases

## 🛠️ Technologies Used

### Programming Languages
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C++98](https://img.shields.io/badge/C++98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C++11](https://img.shields.io/badge/C++11-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C++14](https://img.shields.io/badge/C++14-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C++17](https://img.shields.io/badge/C++17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

### Build Tools
![Make](https://img.shields.io/badge/Make-000000?style=for-the-badge&logo=gnu&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-000000?style=for-the-badge&logo=gnu&logoColor=white)
![Clang](https://img.shields.io/badge/Clang-000000?style=for-the-badge&logo=llvm&logoColor=white)

### Development Tools
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![VS Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Vim](https://img.shields.io/badge/Vim-019733?style=for-the-badge&logo=vim&logoColor=white)

## 📁 Project Structure

```
cpp_modules/
├── 📁 cpp00/          # Basic syntax & I/O
│   ├── 📁 ex00/       # Megaphone
│   ├── 📁 ex01/       # PhoneBook
│   └── 📁 ex02/       # Account
├── 📁 cpp01/          # Memory management
│   ├── 📁 ex00/       # Zombie
│   ├── 📁 ex01/       # Zombie horde
│   ├── 📁 ex02/       # Pointers to members
│   ├── 📁 ex03/       # Weapon class
│   ├── 📁 ex04/       # File handling
│   ├── 📁 ex05/       # Harl class
│   └── 📁 ex06/       # Harl filter
├── 📁 cpp02/          # Classes & operators
│   ├── 📁 ex00/       # Fixed-point (basic)
│   ├── 📁 ex01/       # Fixed-point arithmetic
│   ├── 📁 ex02/       # Fixed-point comparisons
│   └── 📁 ex03/       # BSP algorithm
├── 📁 cpp03/          # Inheritance
│   ├── 📁 ex00/       # ClapTrap
│   ├── 📁 ex01/       # ScavTrap
│   ├── 📁 ex02/       # FragTrap
│   └── 📁 ex03/       # DiamondTrap
├── 📁 cpp04/          # Polymorphism
│   ├── 📁 ex00/       # Animal hierarchy
│   ├── 📁 ex01/       # Brain class
│   ├── 📁 ex02/       # WrongAnimal
│   └── 📁 ex03/       # Materia system
├── 📁 cpp05/          # Exceptions
│   ├── 📁 ex00/       # Bureaucrat
│   ├── 📁 ex01/       # Form class
│   ├── 📁 ex02/       # Presidential forms
│   └── 📁 ex03/       # Intern class
├── 📁 cpp06/          # Type casting
│   ├── 📁 ex00/       # ScalarConverter
│   ├── 📁 ex01/       # Serializer
│   └── 📁 ex02/       # Base identification
├── 📁 cpp07/          # Templates
│   ├── 📁 ex00/       # Template functions
│   ├── 📁 ex01/       # Template iterator
│   └── 📁 ex02/       # Template array
├── 📁 cpp08/          # STL containers
│   ├── 📁 ex00/       # easyfind
│   ├── 📁 ex01/       # Span class
│   └── 📁 ex02/       # MutantStack
├── 📁 cpp09/          # Algorithms
│   ├── 📁 ex00/       # BitcoinExchange
│   ├── 📁 ex01/       # RPN Calculator
│   └── 📁 ex02/       # PmergeMe
├── 📄 README.md       # This file
└── 📄 LICENSE         # MIT License
```

## 🎓 Learning Path

### Beginner Level (🟢)
1. **cpp00**: Start with basic syntax and I/O operations
2. **cpp01**: Learn memory management fundamentals

### Intermediate Level (🟡)
3. **cpp02**: Master classes and operator overloading
4. **cpp03**: Understand inheritance concepts
5. **cpp04**: Explore polymorphism
6. **cpp05**: Handle exceptions properly

### Advanced Level (🟠)
7. **cpp06**: Master type casting techniques
8. **cpp07**: Learn template programming
9. **cpp08**: Use STL containers effectively

### Expert Level (🔴)
10. **cpp09**: Implement advanced algorithms

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

### How to Contribute

1. **Fork the repository**
   ```bash
   git clone https://github.com/yourusername/cpp_modules.git
   ```

2. **Create your feature branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

3. **Commit your changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```

4. **Push to the branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

5. **Open a Pull Request**

### Contribution Guidelines

- Follow the existing code style
- Add tests for new features
- Update documentation as needed
- Ensure all tests pass before submitting

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

<div align="center">

**Made with ❤️ and lots of ☕**

*Master C++ programming with this comprehensive learning journey!*

[![GitHub stars](https://img.shields.io/github/stars/yourusername/cpp_modules?style=social)](https://github.com/yourusername/cpp_modules/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/cpp_modules?style=social)](https://github.com/yourusername/cpp_modules/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/cpp_modules)](https://github.com/yourusername/cpp_modules/issues)

**Last updated: December 2024**

</div> 
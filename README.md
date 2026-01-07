# Mastering Object-Oriented Programming: Building a Robust Movie Database System in C++

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C++-11-blue.svg)](https://en.cppreference.com/w/cpp/11)
[![License](https://img.shields.io/badge/License-Academic-green.svg)](LICENSE)

## ?? Project Overview

An academic project demonstrating fundamental Object-Oriented Programming (OOP) concepts in C++ through a comprehensive movie database management system. The system manages 20 carefully curated movies from various languages and time periods, showcasing proper software engineering practices.

### ?? Key Features

- ? **Complete OOP Implementation** - Classes, objects, encapsulation, abstraction
- ? **20 Diverse Movies** - From 8 languages spanning 1967-2024
- ? **Search & Filter** - Top-rated, by language, latest releases
- ? **Professional Output** - Formatted tables with visual star ratings
- ? **Well-Documented** - Comprehensive comments and documentation
- ? **Cross-Platform** - Works on Windows, Linux, and macOS

## ?? Quick Start

### Compilation

**Windows (easiest):**
```bash
compile_and_run.bat
```

**Linux/Mac:**
```bash
make
./MovieDatabase
```

**Any platform with g++:**
```bash
g++ -std=c++11 -o MovieDatabase main.cpp Movie.cpp MovieDatabase.cpp
./MovieDatabase
```

**Using CMake:**
```bash
mkdir build && cd build
cmake ..
cmake --build .
./MovieDatabase
```

## ?? Project Requirements

This project fulfills the following academic requirements:

- [x] Array of 20 movies with complete information
- [x] Movie attributes: name, id, year, language, rating (1-5)
- [x] Display top-rated movies
- [x] Filter movies by language (French)
- [x] Show latest movie releases
- [x] Implement Movie class using OOP principles
- [x] Demonstrate encapsulation and abstraction

## ??? System Architecture

### Classes

#### Movie Class
Encapsulates individual movie information:
- **Private Members**: name, id, year, language, rating
- **Public Methods**: Getters, setters, display, validation
- **Features**: Input validation, const correctness

#### MovieDatabase Class
Manages collection of movies:
- **Storage**: Fixed array of 20 Movie objects
- **Operations**: Add, search, filter, display
- **Algorithms**: Linear search for top-rated, language filter, latest movies

## ?? Project Structure

```
Mastering-OOP-Movie-Database-CPP/
?
??? Movie.h                      # Movie class declaration
??? Movie.cpp                    # Movie class implementation
??? MovieDatabase.h              # Database class declaration
??? MovieDatabase.cpp            # Database implementation
??? main.cpp                     # Main program
?
??? README.md                    # This file
??? CMakeLists.txt              # CMake build configuration
??? Makefile                    # Make build file
??? compile_and_run.bat         # Windows quick build
??? .gitignore                  # Git ignore rules
?
??? docs/                       # Additional documentation
    ??? PROJECT_DOCUMENTATION.txt
    ??? PRESENTATION_GUIDE.md
    ??? QUICK_REFERENCE.txt
    ??? VISUAL_DIAGRAMS.txt
    ??? BUILD_INSTRUCTIONS.txt
```

## ?? Movie Database

The system includes 20 critically acclaimed films:

| Language | Count | Notable Films |
|----------|-------|---------------|
| English | 11 | The Shawshank Redemption, Oppenheimer, Inception |
| French | 5 | Amélie, La Haine, Intouchables |
| Korean | 1 | Parasite (Oscar Best Picture) |
| Japanese | 1 | Spirited Away |
| Italian | 1 | Cinema Paradiso |
| Spanish | 1 | Pan's Labyrinth |
| Portuguese | 1 | City of God |

**Time Span**: 1967 (Le Samouraï) to 2024 (Dune: Part Two)

## ?? Technologies & Concepts

### C++ Features Used
- Classes and Objects
- Encapsulation (private/public)
- Const correctness
- Constructor overloading
- Member functions
- Arrays and loops

### OOP Principles Demonstrated
1. **Encapsulation** - Data hiding with controlled access
2. **Abstraction** - Complex operations behind simple interfaces
3. **Composition** - MovieDatabase contains Movie objects
4. **Information Hiding** - Implementation details concealed

## ?? Sample Output

```
****************************************************************************************************
**          MASTERING OBJECT-ORIENTED PROGRAMMING                                                 **
**          Building a Robust Movie Database System in C++                                        **
****************************************************************************************************

====================================================================================================
                           COMPLETE MOVIE DATABASE
====================================================================================================
ID    Movie Name                                      Year  Language       Rating
----------------------------------------------------------------------------------------------------
1     The Shawshank Redemption                        1994  English        ????? (5/5)
2     The Godfather                                   1972  English        ????? (5/5)
...
```

## ?? Learning Outcomes

- Understanding class design and implementation
- Practicing encapsulation and data hiding
- Implementing search and filter algorithms
- Professional code organization
- Documentation best practices

## ?? Build Requirements

- **Compiler**: g++ with C++11 support or MSVC
- **Optional**: CMake 3.10+, Make utility
- **Tested on**: Windows 10/11, Ubuntu 20.04+, macOS

## ?? Documentation

- **[Quick Reference](QUICK_REFERENCE.txt)** - Fast lookup guide
- **[Build Instructions](BUILD_INSTRUCTIONS.txt)** - Detailed compilation guide
- **[Project Documentation](PROJECT_DOCUMENTATION.txt)** - Technical details
- **[Presentation Guide](PRESENTATION_GUIDE.md)** - How to present this project
- **[Visual Diagrams](VISUAL_DIAGRAMS.txt)** - Class diagrams and flowcharts

## ????? Author

**Academic Project**  
Demonstrating C++ OOP Principles

## ?? License

This is an academic project for educational purposes.

## ?? Contributing

This is an academic project. If you're using it for learning:
1. Fork the repository
2. Understand the code thoroughly
3. Modify it to make it your own
4. Add your unique features

## ? Acknowledgments

- Movies selected based on critical acclaim and cultural significance
- Inspired by real-world database systems
- Built with educational clarity in mind

---

**Made with ?? for learning C++ and OOP**

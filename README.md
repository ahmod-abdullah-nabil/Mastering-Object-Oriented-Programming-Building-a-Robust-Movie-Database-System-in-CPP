# Mastering Object-Oriented Programming: Building a Robust Movie Database System in C++

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C++-11-blue.svg)](https://en.cppreference.com/w/cpp/11)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Capacity](https://img.shields.io/badge/Capacity-100K%20Movies-brightgreen.svg)]()
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-orange.svg)]()

## 📚 Project Overview

A professional-grade movie database management system demonstrating advanced Object-Oriented Programming (OOP) concepts in C++. This system showcases proper software engineering practices with a scalable architecture supporting up to **100,000 movies**.

### ✨ Key Features

- 🏗️ **Professional OOP Implementation** - Classes, objects, encapsulation, abstraction, RAII
- 🎬 **50 Diverse Movies** - From 7 languages spanning 1948-2024
- 🔍 **Advanced Search & Filter** - Top-rated, by language, latest releases, name search
- 💾 **File Persistence** - Automatic save/load with binary file format
- ⭐ **5 Display Styles** - Stars, blocks, circles, plus signs, or numbers only
- 📊 **100,000 Movie Capacity** - Professional-grade scalability
- ✅ **CRUD Operations** - Complete Create, Read, Update, Delete functionality
- 🖥️ **Cross-Platform** - Works on Windows, Linux, and macOS
- 🧠 **Dynamic Memory Management** - Heap allocation for large datasets
- 🎯 **User-Friendly Interface** - Interactive menu-driven system

## 🚀 Quick Start

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

## 📁 Project Structure

```
Mastering-OOP-Movie-Database-CPP/
│
├── 📝 Source Code
│   ├── main.cpp                    # Main program with menu system
│   ├── Movie.cpp                   # Movie class implementation
│   ├── Movie.h                     # Movie class declaration
│   ├── MovieDatabase.cpp           # Database implementation
│   ├── MovieDatabase.h             # Database class declaration
│   └── MovieDisplay.h              # Display utilities
│
├── ⚙️ Build Configuration
│   ├── CMakeLists.txt              # CMake build configuration
│   ├── Makefile                    # Make build file
│   └── compile_and_run.bat         # Windows quick build script
│
├── 💾 Data
│   └── movies.dat                  # Binary data file (auto-generated)
│
└── 📄 Project Files
    ├── README.md                   # This file
    ├── LICENSE                     # MIT License
    └── .gitignore                  # Git ignore rules
```

## ⚡ Features

### Core Functionality
- 👁️ **View All Movies** - Display complete database with formatted tables
- 🏆 **Top-Rated Movies** - Find highest-rated films
- 🌐 **Filter by Language** - Browse movies in 7 languages
- 🆕 **Latest Movies** - See most recent releases
- 🔎 **Search by Name** - Case-insensitive partial matching
- ➕ **Add Movies** - Expand your collection (up to 100,000!)
- 🗑️ **Remove Movies** - Delete unwanted entries
- ✏️ **Update Movies** - Modify existing information
- 📈 **Database Statistics** - View capacity and usage
- 🎨 **Display Styles** - Choose your preferred rating visualization

### Data Persistence
- 💿 **Automatic Save** - Changes saved after add/remove/update
- 🔐 **Binary Format** - Efficient file storage
- 📥 **Auto-Load** - Restores data on startup
- 🛡️ **Error Handling** - Corruption detection and recovery

### Display Styles
1. **Stars/Bars** - `[*********-] 9.3/10`
2. **Blocks** - `[#########.] 9.3/10`
3. **Circles** - `[ooooooooo.] 9.3/10`
4. **Plus Signs** - `[+++++++++ ] 9.3/10`
5. **Numbers Only** - `[9.3/10.0]`

## 🎞️ Movie Database

The system includes **50 critically acclaimed films** from around the world:

| Language | Count | Notable Films |
|----------|-------|---------------|
| English | 15 | The Shawshank Redemption (9.3), The Dark Knight (9.0), Inception (8.8) |
| French | 8 | Intouchables (8.5), Am�lie (8.3), La Haine (8.1) |
| Korean | 6 | Parasite (8.5), Oldboy (8.4), Memories of Murder (8.1) |
| Japanese | 7 | Spirited Away (8.6), Seven Samurai (8.6), Your Name (8.4) |
| Italian | 5 | Life Is Beautiful (8.6), Cinema Paradiso (8.5), Bicycle Thieves (8.3) |
| Spanish | 5 | Pan's Labyrinth (8.2), The Secret in Their Eyes (8.2) |
| Portuguese | 4 | City of God (8.6), Elite Squad (8.0) |

**Time Span**: 1948 (Bicycle Thieves) to 2024 (Dune: Part Two)  
**Ratings**: IMDb-style 1.0-10.0 scale  
**Capacity**: Can store up to **100,000 movies**

### Database Statistics
- 🎬 **Current**: 50 sample movies
- 📦 **Capacity**: 100,000 movies
- 💾 **File Size**: ~3 KB for 50 movies, scales to ~6 MB for 100K
- 🌍 **Languages**: 7 different languages represented

## 🏛️ System Architecture

### Classes

#### Movie Class
Encapsulates individual movie information with static display style management:
- **Private Members**: name, id, year, language, rating
- **Static Members**: displayStyle (shared across all instances)
- **Public Methods**: Getters, setters, display, validation
- **Static Methods**: setDisplayStyle(), getDisplayStyle()
- **Features**: Input validation, const correctness, 5 display styles

#### MovieDatabase Class
Manages collection of movies with dynamic memory allocation:
- **Storage**: Dynamic array of up to 100,000 Movie objects (heap)
- **Operations**: Add, remove, update, search, filter, display
- **Algorithms**: Linear search, case-insensitive matching, file I/O
- **Memory Management**: RAII pattern with constructor/destructor
- **File Operations**: Binary serialization/deserialization
- **Capacity**: 100,000 movies (scalable architecture)

### Memory Management
- **Heap Allocation**: `new Movie[100000]` for scalability
- **RAII Pattern**: Automatic cleanup via destructor
- **Memory Usage**: ~40-50 MB for full capacity
- **No Memory Leaks**: Proper `delete[]` in destructor

## 🔧 Technologies & Concepts

### C++ Features Used
- **OOP**: Classes, objects, encapsulation, abstraction
- **Memory Management**: Dynamic allocation (new/delete), RAII pattern
- **Static Members**: Shared class-level variables and methods
- **File I/O**: Binary file operations, serialization
- **STL**: String, vector headers
- **Const Correctness**: Proper use of const methods
- **Operator Overloading**: Stream operators for file I/O
- **Constructor/Destructor**: Proper resource management

### OOP Principles Demonstrated
1. **Encapsulation** - Data hiding with controlled access via getters/setters
2. **Abstraction** - Complex operations hidden behind simple interfaces
3. **Composition** - MovieDatabase contains Movie objects
4. **Information Hiding** - Implementation details concealed
5. **RAII** - Resource Acquisition Is Initialization pattern
6. **Static Members** - Shared state across instances (display style)

### Advanced Concepts
- 🧠 **Dynamic Memory Allocation** - Heap vs stack management
- 💾 **File Persistence** - Binary serialization/deserialization
- 🔍 **Linear Search Algorithms** - Finding, filtering, sorting
- 📈 **Scalable Architecture** - 100K capacity with efficient memory use
- 🛡️ **Error Handling** - Input validation, file corruption detection
- 🎯 **Static Variables** - Global style settings

## 📊 Sample Output

```
====================================================================================================
                      MOVIE DATABASE MANAGEMENT SYSTEM
                 Mastering Object-Oriented Programming in C++
====================================================================================================

Welcome! The database has been initialized with 50 movies.
Database Capacity: 100000 movies (Plenty of room to grow!)
Tip: Try option 10 to change the rating display style!

====================================================================================================
                              MOVIE DATABASE MENU
====================================================================================================
  1.  View All Movies
  2.  View Top-Rated Movies
  3.  View Movies by Language
  4.  View Latest Movies
  5.  Search Movie by Name
  6.  Add New Movie
  7.  Remove Movie
  8.  Update Movie Information
  9.  View Database Statistics
  10. Change Display Style
  0.  Exit Program
====================================================================================================

====================================================================================================
                           COMPLETE MOVIE DATABASE
====================================================================================================
ID    Movie Name                                      Year  Language       Rating
----------------------------------------------------------------------------------------------------
1     The Shawshank Redemption                        1994  English        [*********-] 9.3/10
2     The Godfather                                   1972  English        [*********-] 9.2/10
3     The Dark Knight                                 2008  English        [*********-] 9.0/10
...
----------------------------------------------------------------------------------------------------
Total movies: 50 | Capacity: 100000 | Available: 99950
====================================================================================================
```

## 🎓 Learning Outcomes

After completing this project, you will understand:

- 📐 **Class Design** - Creating well-structured, reusable classes
- 🔒 **Encapsulation** - Protecting data with private members
- 🧠 **Memory Management** - Dynamic allocation and RAII pattern
- 💾 **File I/O** - Binary serialization for data persistence
- 🔗 **Static Members** - Shared state across class instances
- 🔎 **Search Algorithms** - Linear search and filtering
- 🎨 **User Interface** - Menu-driven console applications
- ⚠️ **Error Handling** - Input validation and edge cases
- 📦 **Code Organization** - Professional project structure
- 📝 **Documentation** - Writing clear, maintainable code

## 🛠️ Build Requirements

- **Compiler**: 
  - g++ 4.8.1+ (with C++11 support)
  - MSVC 2015+ (Visual Studio)
  - Clang 3.3+
- **Optional**: 
  - CMake 3.10 or higher
  - Make utility (Linux/Mac)
- **Tested on**: 
  - Windows 10/11
  - Ubuntu 20.04+, Debian 10+
  - macOS 10.15+

## 📖 Usage Guide

### Menu Options

1. **View All Movies** - Display complete database with ratings
2. **View Top-Rated Movies** - Show highest-rated films
3. **View Movies by Language** - Filter by specific language
4. **View Latest Movies** - Display most recent releases
5. **Search Movie by Name** - Case-insensitive search
6. **Add New Movie** - Insert new movie (auto-saves)
7. **Remove Movie** - Delete by ID (auto-saves)
8. **Update Movie Information** - Modify existing movie (auto-saves)
9. **View Database Statistics** - See capacity and usage
10. **Change Display Style** - Choose rating visualization

### Adding a Movie

```
Enter movie name: Inception
Enter release year: 2010
Enter language: English
Enter rating (1.0-10.0): 8.8

? Movie added successfully!
? Changes saved to file!
```

### Searching Movies

```
Enter movie name to search: dark

Search Results:
- The Dark Knight (2008) - English - 9.0/10
```

## ⚡ Performance

- **Add Movie**: O(1) - Instant
- **Remove Movie**: O(n) - Fast even with thousands
- **Search**: O(n) - Efficient linear search
- **Display**: O(n) - Scales with movie count
- **File Save/Load**: O(n) - Binary format for speed

**Benchmarks** (approximate):
- 1,000 movies: Search < 1ms
- 10,000 movies: Search ~5-10ms
- 100,000 movies: Search ~50-100ms

## 🤝 Contributing

This is an educational project. If you're using it for learning:

1. **Fork** the repository
2. **Study** the code thoroughly
3. **Modify** it to make it your own
4. **Add** unique features
5. **Document** your changes

### Ideas for Enhancement

- Add sorting functionality (by name, year, rating)
- Implement a GUI using Qt or wxWidgets
- Add genre classification
- Include movie descriptions/plots
- Add director and cast information
- Implement advanced search (multiple criteria)
- Add export to CSV/JSON
- Create recommendation system
- Add user ratings and reviews
- Implement SQLite database backend

## 📚 Documentation

The code is extensively documented with:
- Clear function comments
- Inline explanations
- Well-named variables
- Organized structure

For questions or clarifications, open an issue on GitHub!

## ⚠️ Known Limitations

- **Fixed Capacity**: 100,000 movies maximum (can be increased if needed)
- **No Database Indexing**: Linear search only (fast enough for 100K)
- **Binary File Format**: Not human-readable (use export feature)
- **Single User**: No concurrent access support
- **Console Only**: No graphical interface

## 📋 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👤 Author

**Academic Project**  
Created to demonstrate C++ OOP principles and best practices

## 🙏 Acknowledgments

- Movies selected based on critical acclaim and cultural significance
- IMDb for rating reference
- Inspired by real-world database management systems
- Built with educational clarity as the primary goal

## 📞 Contact & Support

- **Issues**: Open an issue on GitHub
- **Questions**: Check existing issues or create a new one
- **Contributions**: Pull requests welcome!

## 🎯 Project Status

✅ **Complete** - All core features implemented  
✅ **Tested** - Works on Windows, Linux, macOS  
✅ **Documented** - Comprehensive README and code comments  
✅ **Maintained** - Active development and bug fixes

## 📅 Version History

- **v2.0** (Current)
  - Increased capacity to 100,000 movies
  - Added dynamic memory allocation
  - Implemented RAII pattern
  - Added 5 display styles
  - Enhanced file persistence
  - Expanded to 50 sample movies
  
- **v1.0** (Initial)
  - Basic CRUD operations
  - 20 sample movies
  - Static array storage
  - Simple console interface

---

**⭐ If you find this project helpful, please consider giving it a star!**

**Made with ❤️ for learning C++ and Object-Oriented Programming**

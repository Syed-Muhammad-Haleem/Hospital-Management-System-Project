Hospital Management System

* Developed a comprehensive **Hospital Management System** using **C++**, **Object-Oriented Programming (OOP)**, and **File Handling**.
* Designed as a console-based application to simulate real-world hospital operations.
* Implemented a modular architecture with separate user roles:

  * **Admin**
  * **Receptionist**
  * **Doctor**
  * **Accountant**
* Created a secure login system with role-based access to different modules.
* Implemented patient registration and record management.
* Developed doctor management functionalities, including adding, updating, searching, and deleting doctor records.
* Built an appointment management system for scheduling and maintaining patient appointments.
* Added prescription management to allow doctors to generate and maintain patient prescriptions.
* Implemented billing and invoice generation for patient payments and medical services.
* Used **file handling** to permanently store and retrieve hospital data, ensuring information persists between program executions.
* Applied core **Object-Oriented Programming** concepts, including:

  * Encapsulation
  * Inheritance
  * Polymorphism
  * Abstraction
* Organized the project into multiple classes and source files for improved readability and maintainability.
* Used the **Standard Template Library (STL)**, including vectors and strings, where appropriate.
* Implemented menu-driven navigation to provide a simple and user-friendly console interface.
* Focused on modular programming practices to simplify debugging, testing, and future enhancements.
* Strengthened practical knowledge of C++ programming by solving a real-world management problem.
* Demonstrated software design principles through reusable and well-structured code.
* Built the project as both an academic learning experience and a portfolio project to showcase programming skills.
* Future enhancements may include:

  * Database integration (MySQL/SQLite)
  * Graphical User Interface (GUI)
  * Password encryption
  * Advanced search and filtering
  * Report generation
  * Online appointment booking
  * Improved security and scalability



# VERSION(v2) Hospital Management System

## Project Structure

The project has been reorganized into a cleaner and more maintainable structure.

```text
Hospital-Management-System/
├── build/          # Compiled object files and executable
├── data/           # CSV data files
├── include/        # Header files (optional)
├── src/
│   ├── admin/
│   ├── models/
│   ├── services/
│   ├── utils/
│   └── main.cpp
├── Makefile
├── Makefile.win
└── README.md
```

## Building the Project (Linux)

### Remove Previous Build

Before creating a fresh build, remove the old build files:

```bash
make clean
```

This command deletes the `build/` directory and all previously compiled object files.

### Create a Fresh Build

Compile the project by running:

```bash
make
```

The Makefile will:

* Compile only the required source files.
* Store object (`.o`) files inside the `build/` directory.
* Generate the executable:

```text
build/hospital
```

### Run the Application

After the build completes successfully, run the application with:

```bash
./build/hospital
```

## Incremental Builds

After the initial build, you do **not** need to run `make clean` every time.

Simply run:

```bash
make
```

The Makefile recompiles only the files that have changed, making subsequent builds much faster.

Run `make clean` only when you want a completely fresh build.

## Windows Compatibility

This project was originally developed using Windows-specific libraries and console commands, including:

* `#include <conio.h>`
* `system("cls")`

To make the project compatible with Linux, the following changes were made:

* Removed the dependency on `conio.h`.
* Replaced:

```cpp
system("cls");
```

with:

```cpp
system("clear");
```

### Building on Windows

If you want to compile and run this project on Windows again, restore the original Windows-specific console code:

Replace:

```cpp
system("clear");
```

with:

```cpp
system("cls");
```

If your project requires console functions provided by `conio.h` (such as `getch()`), restore:

```cpp
#include <conio.h>
```

Then build the project using your preferred Windows C++ compiler (such as MinGW, Dev-C++, Code::Blocks, or Visual Studio with the appropriate project configuration).

The included `Makefile.win` can be used with MinGW's `mingw32-make` if your environment supports it.

Example:

```bash
mingw32-make -f Makefile.win
```

or

```bash
make -f Makefile.win
```

depending on your MinGW installation.

## Requirements

### Linux

* g++
* GNU Make

Install them on Ubuntu:

```bash
sudo apt update
sudo apt install build-essential
```

## Author

Shahid Abbas

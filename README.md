# 📦 MyContainer Project

---

## 📚 Project Description

This project implements a generic container class named `MyContainer` 
along with multiple advanced iterators that allow traversing the container's elements 
in various unique orders:

- **AscendingIterator** – iterates in ascending (sorted) order.
- **DescendingIterator** – iterates in descending (reverse sorted) order.
- **SideCrossIterator** – iterates alternating from the smallest and largest elements.
- **ReverseIterator** – iterates in reverse insertion order.
- **OrderIterator** – iterates in the original insertion order.
- **MiddleOutIterator** – starts from the middle and alternates outward.

The project includes comprehensive unit tests covering all functionalities and iterators, exception handling for invalid operations, and memory management verification.

---

## 📂 Project Structure
/
├── Iterator/ # Folder containing all iterator classes
│ ├── AscendingOrder.h
│ ├── DescendingOrder.h
│ ├── SideCrossOrder.h
│ ├── ReverseOrder.h
│ ├── Order.h
│ └── MiddleOutOrder.h
├── MyContainer.h # Main generic container header
├── Main.cpp # Demo and example usage main file
├── Test.cpp # Unit tests with doctest framework
├── Makefile # Makefile for building, testing, and running
└── README.md # This documentation file


---

## 🛠️ How to Build and Run

### Requirements:

- C++17 compatible compiler (e.g., g++)
- `valgrind` installed for memory leak checks (optional but recommended)

---

### Makefile Commands:

| Command         | Description                                   |
| --------------- | ---------------------------------------------|
| `make Main`     | Builds and runs the demonstration executable (`Main.cpp`) |
| `make test`     | Builds and runs the unit tests (`Test.cpp`) using doctest |
| `make valgrind` | Runs memory leak checks on the demo executable with `valgrind` |
| `make clean`    | Removes all compiled binaries and temporary files |

---

### Usage Examples:

```bash
# Build and run the demo
make Main

# Build and run all unit tests
make test

# Run memory leak detection using valgrind
make valgrind

# Clean build artifacts and executables
make clean

---

### Makefile Commands:

✅ What is Tested?

    Creating containers with default and custom template types (e.g., int, std::string).

    Adding and removing elements, including exception throwing when removing non-existent elements.

    Iterator traversals verifying element order for each iterator type.

    Exception throwing when incrementing iterators past the end (overflow).

    Behavior of all iterators on empty containers.

    Memory management tested via valgrind to ensure no leaks.



👩‍💻 Author  
Eden Hassin  
Edenhassin@gmail.com  
Project completed: May-June 2025






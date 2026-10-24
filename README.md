# Simple Food Ordering System (C++)

A console-based food ordering application written in **modern C++ (C++17)**. Users can browse a categorized menu, add multiple items to a cart, choose quantities, and receive an itemized receipt.

## Features

- Categorized menu: pizza, burgers, sandwiches, rolls, and biryani
- Add multiple items to one order
- Combine repeated selections of the same item
- Quantity and menu-input validation
- Itemized receipt with per-item amounts and grand total
- Portable standard C++ (no `conio.h`, `iostream.h`, `goto`, or Windows-only screen commands)

## Requirements

- A C++ compiler with C++17 support, such as GCC/G++ or Clang
- Windows, Linux, or macOS terminal

## Build and run

### Windows (MinGW-w64 / MSYS2)

Open a terminal in this project folder:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o food_ordering.exe
./food_ordering.exe
```

In Windows Command Prompt, run:

```bat
food_ordering.exe
```

### Linux / macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o food_ordering
./food_ordering
```

## How to use

1. Enter your name.
2. Select a menu item by its number.
3. Enter the quantity.
4. Continue adding items, or choose checkout.
5. Review the receipt and total.

Choose `0` from the menu to check out immediately.

## Project structure

```text
simple-food-ordering-cpp/
├── main.cpp
├── README.md
└── .gitignore
```

## Concepts demonstrated

- Structures (`struct`) and standard-library containers (`std::vector`)
- Functions and modular program organization
- Loops, conditionals, and input validation
- Formatted console output
- Basic cart and billing logic

## Notes

- Prices are sample values for a learning project and can be edited in the menu definition in `main.cpp`.
- This is a local console application. It does not process real payments, store orders in a database, or connect to a delivery service.

# ft_printf

## 📘 Project Overview

**ft_printf** is a 42 School project that requires you to re-implement the C standard library function `printf()`.  
The goal is to gain a deep understanding of variadic functions, formatted output, and string manipulation in C.

---

## 🧠 Learning Objectives

- Implement a simplified version of the standard `printf`.
- Learn how to handle **variable argument lists** (`stdarg.h`).
- Parse and process **format specifiers**.
- Improve understanding of **modular programming** and **memory management**.
- Strengthen debugging and testing skills.

---

## ⚙️ Mandatory Conversion Specifiers

| Specifier | Description |
|------------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%%` | Prints a percent sign |

---

## 🧩 Bonus Part (Optional)

If the mandatory part works perfectly, you may implement the following:

- Flags: `-`, `0`, `.`, `#`, `+`, and (space)
- Field width and precision handling
- Combination of multiple flags

---

## 🧰 Usage

### 🔨 Compilation

Use the Makefile to build the static library:

```bash
make        # Compile libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild everything

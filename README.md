# Custom printf Implementation

This custom printf implementation is a personalized version of the standard `printf` function in C. It is designed to format and print text with various specifiers, providing functionality similar to the standard `printf` but with custom modifications and added features.

## Files Overview

1. **`main.c`**: Contains the main entry point and demonstrates the usage of the custom printf function.

2. **`main.h`**: Header file defining function prototypes, flags, and data structures used throughout the custom printf implementation.

3. **`printf.c`**: Defines the `_printf` function, which is the core of the custom printf functionality. It processes the format string and calls appropriate handlers for each specifier.

4. **`functions.c` and functions2.c** : These files contain handler functions for various specifiers such as `%c`, `%s`, `%i`, `%d`, `%u`, `%o`, `%x`, `%X`, `%p`, `%S`, `%r`, and `%R`.

5. **`utils.c`**: Contains utility functions used by the handler functions, including functions for determining if a character is printable and for appending hexadecimal codes for non-printable characters.

6. **`writ_handlers.c`**: Implements functions for handling writing characters, numbers, and pointers.

7. **`get_flags.c`, `get_precision.c`, `get_size.c`, `get_width.c`**: These files contain functions that extract flags, precision, size, and width from the format string, respectively.

8. **`handle_print.c`**: Contains the `handle_print` function, which determines the appropriate handler for each specifier and calls it accordingly.

9. **`int_functions1.c`**: Contains additional handler functions for specifiers `%i` and `%d`.

## Contributions

- **Second Contributor**: Contributed to `get-flags.c`, `get_precision.c`, and `int_functions1.c`, enhancing flag extraction, precision determination, and handling for `%i` and `%d` specifiers.

- **12 hours ago**: Updated the `non_printable` handling in `functions.c`, `functions2.c`, and `utils.c`.

- **29 minutes ago**: Made updates to various files for better handling of `%i` and `%d` specifiers.

## Build and Run

To build the custom printf program, compile the source files and link them into an executable, for example:

```bash
gcc main.c printf.c functions.c functions2.c utils.c writ_handlers.c get_flags.c get_precision.c get_size.c get_width.c handle_print.c int_functions1.c -o custom_printf


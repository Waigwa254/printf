#include "main.h"

/**
*print_unsigned - prints unsigned integers
*@types: are the list of arguments passed
*@buffer: the array to handle print
*@flags: calculates active flags
*@width: the Get width
*@precision: the precisions specification
*@size: size specifier.
*Return: returns the no. of characters printed
*/
int print_unsigned(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int
	);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUM IN OCTAL */

/**
*print_octal - prints unsigned ints in octal notations
*@types: are the list of arguments passed
*@buffer: the array to handle print
*@flags: calculates active flags
*@width: the Get width
*@precision: the precisions specification
*@size: size specifier.
*Return: returns the no. of characters printed
*/
int print_octal(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN HEXADECIMAL */
/**
*print_hexadcml - prints unsigned ints in hexadecimal notations
*@types: are the list of arguments passed
*@buffer: the array to handle print
*@flags: calculates active flags
*@width: the Get width
*@precision: the precisions specification
*@size: size specifier.
*Return: returns the no. of characters printed
*/
int print_hexadcml(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRINT uNSIGNED INT IN UPPER HEXADECIMAL */

/**
*print_hexadcml_upper - prints unsigned ints in upper hexadecimal notations
*@types: are the list of arguments passed
*@buffer: the array to handle print
*@flags: calculates active flags
*@width: the Get width
*@precision: the precisions specification
*@size: size specifier.
*Return: returns the no. of characters printed
*/
int print_hexadcml_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINT HEXADCML IN LOWER OR UPPER */

/**
*print_hexa - Prints a hexadecimal number in lower or upper
*@types: Lists of arguments
*@map_to: Array of values to map the number to
*@buffer: buffer array to handle print
*@flags: calculates active flags
*@flag_ch: calculates active flags
*@width: get width
*@precision: precision specification
*@size: size specifier
*@size: size specification
*Return: number of chars printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}

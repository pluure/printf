#include "main.h"
/*** UNSIGNED NUMBER ***/
/**
 * print_unsigned - A function to prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer
 * @flags: number of active flags
 * @width: width
 * @precision: specification
 * @size: Size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}

/*** UNSIGNED NUMBER IN OCTAL ***/
/**
 * print_octal - A function that prints an unsigned number
 * @types: Lists of arguments
 * @buffer: Buffer
 * @flags: active flags
 * @width: width
 * @precision: specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
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
/******UNSIGNED NUMBER IN HEXADECIMAL ******/
/**
 * print_hexadecimal - a function that pints an unsigned number
 * @types: List of argument types
 * @buffer: Buffer
 * @flags: total active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/** UNSIGNED NUMBER IN UPPER HEXADECIMAL**/
/**
 * print_hexa_upper - a function that prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer
 * @flags: total active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - a function that Prints a hexadecimal number
 * @types: List of arguments
 * @map_to: Array of values for mapping
 * @buffer: Buffer
 * @flags:  Total active flags
 * @flag_ch: Total active flags
 * @width: width
 * @precision: Precision
 * @size: Size for specifier
 * @size: Size for specification
 * Return: Number of chars printed
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


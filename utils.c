#include "main.h"

/**
 * is_printable - determines if is printable
 * @c: Char to be determined.
 * Return: 1 if c is printable, else 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/****** HEXA CODE ******/
/**
 * append_hexa_code - Add ascci in hexadecimal code
 * @buffer: chars.
 * @i: Index
 * @ascii_code: ASSCI CODE.
 * Return: Always three
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**** PRINTS DIGITS ****/
/**
 * is_digit - Confirms if char is a digit
 * @c: Char
 * Return: 1 if c is a digit, else 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - a function to convert num size.
 * @num: Num.
 * @size: Size
 * Return: value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - a function to convert unsigned size.
 * @num: Num
 * @size: size
 * Return: value of num to be casted.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}


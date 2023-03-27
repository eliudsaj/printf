#include "main.h"

/**
 * print_unsigned - Prints unsigned number
 * @types: arguments
 * @buffer: buffer array that handles print
 * @flags: active flags
 * @width: width
 * @precision: specifies presicion
 * @size: specifies size
 * Return: No of chars
 *
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

/**
 * print_octal - Prints unsigned number octal
 * @types: arguments
 * @buffer: Buffer array that handles print
 * @flags: active flags
 * @width: width
 * @precision: specifies presicion
 * @size: specifies size
 * Return: No of chars
 *
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

/**
 * print_hexadecimal - Prints unsigned number hexa
 * @types: arguments
 * @buffer: Buffer array that  handles print
 * @flags:  active flags
 * @width: width
 * @precision: specifies presicion
 * @size: specifies size
 * Return: No of chars
 *
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints unsigned number upper hexa
 * @types: arguments
 * @buffer: Buffer array that handles print
 * @flags: active flags
 * @width: width
 * @precision: specifies presicion
 * @size: Specifies size
 * Return: No of chars
 *
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexa lower/upper
 * @types: arguments
 * @map_to: value array
 * @buffer: Buffer array that handles print
 * @flags:  active flags
 * @flag_ch: Calculates active flags
 * @width: width
 * @precision: specifies presicion
 * @size: specifies size
 * Return: No of chars
 *
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


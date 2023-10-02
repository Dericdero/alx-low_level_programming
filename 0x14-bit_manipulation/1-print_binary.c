#include <stdio.h>
#include "main.h"

/**
 * print_binary- print a binnary representation of a number
 * @n: binary number
 * Return- binary number
 */

void print_binary(unsigned long int n)
{
unsigned long int num = 1UL << (sizeof(unsigned long int) * 8 - 1);

int leading_zeros = 1;

while (num > 0)
{

  if (n & num)
{
putchar('1');
leading_zeros = 0;
}
else
{
if (!leading_zeros)
putchar('0');
}
num >>= 1;
}

if (leading_zeros)
putchar('0');
}

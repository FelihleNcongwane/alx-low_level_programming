#ifndef _MAIN_H_
#define _MAIN_H_

int _putchar(char c);
unsigned int convertBinaryToUnsignedInt(const char *binary);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int get_endianness(void);
unsigned long int power(unsigned int base, unsigned int power);

#endif

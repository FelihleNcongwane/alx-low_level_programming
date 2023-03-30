#include <stdio.h>

int main(void)

{
	int n;
	int *p;

	n = 98;
	p = &n;

	printf("value of n is: %d\n", n);
	printf("Address of 'n' is: %p\n", &n);
	printf("value of 'p' is: %p\n", p);
	*p = 400;
	printf("value of n is: %d\n", n);
	printf("Address of pointer p is: %p\n", &p);

	return (0);

}

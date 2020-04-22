#include <iostream>
#include <ctime>

int summsqr(int size, int *mass)
{
	int k=0;
	__asm__
	(
		"mov $0, %%rdi\n\t"
		"cycle:\n\t"
			"mov (%%rsi), %%eax\n\t"
			"mul %%eax\n\t"
			"mov %%rax, %%rbx\n\t"
			"add %%rbx, %%rdi\n\t"
			"add $4, %%rsi\n\t"
		"loop cycle\n\t"
		:"=D"(k)
		:"c"(size), "S"(mass)
	);
	return k;
}
int main()
{
	int size = 12;
	int *mass = (int*) calloc(size, sizeof(int));
	srand(time(NULL));
	for (int i=0; i<size; i++)
	{
		mass[i] = rand()%10;
		printf("%d ", mass[i]);
	}
	printf("\n%d\n", summsqr(size,mass));
	return 0;
}
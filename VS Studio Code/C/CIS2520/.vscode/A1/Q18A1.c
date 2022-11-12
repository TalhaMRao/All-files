/* Program: Finding real roots of nonlinear
equation using the Newton-Raphson Method
Co-Author:
Date: */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
/* f(x). */
#define f(x) x *log2(x)
/* g(x) = f’(x). */
#define g(x) (1 + log(x)) / 0.693147
int main()
{
	float x0, x1, f0, f1, g0, e, N;
	int step = 1, MaxIterations;
	/* Inputs */
	printf("\n Enter N for which x lg x should equal N:\n");
	scanf("%f", &N);
	e = 1;		// error is 1.
	x0 = N / 2; // initializing x0.
	printf("Enter maximum iteration:\n");
	scanf("%d", &MaxIterations);
	/* Implementing Newton Raphson Method */
	printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	do
	{
		g0 = g(x0);
		f0 = f(x0) - N;
		if (g0 == 0.0)
		{
			printf("Mathematical Error.");
			exit(0);
		}
		x1 = x0 - f0 / g0;
		printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, x1, f1);
		x0 = x1;
		step = step + 1;
		if (step > N)
		{
			printf("Not Convergent.");
			exit(0);
		}
		f1 = f(x1);
	} while (fabs(f1 - N) > e);
	printf("\nRoot is: %f", x1);
	getch();
	return 0;
}

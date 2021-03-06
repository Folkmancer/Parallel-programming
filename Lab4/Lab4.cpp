// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <omp.h>
using namespace std;

double InFunction(double x)
{
	//return 4.0 / (1.0 + (x * x));
	return 1/(x-1);
}

int main()
{
	double a, b, x, result, h, integral;
	int k, ibeg, iend, MyProc, p, n;
	//double start, end;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	cout << "Input n: ";
	cin >> n;
	result = 0;
	h = (b - a) / n;
	omp_set_num_threads(4);
	p = omp_get_num_threads();
	//start = omp_get_wtime();
#pragma omp parallel private(MyProc, ibeg, iend, k, x) reduction(+:result)
	{
		MyProc = omp_get_thread_num();
		k = (n - 1) / p + 1;
		ibeg = MyProc * k + 1;
		iend = (MyProc + 1) * k;
		if (ibeg > n) iend = ibeg - 1;
		else if (iend > n) iend = n;
		/*
		for (int i = ibeg; i <= iend; i++)
		{
			x = h * (i - 0.5);
			result += InFunction(x);
		}*/
		
		for (int i = MyProc; i < n; i += p)
		{
			x = h * (i - 0.5);
			result += InFunction(x);
		}
	}
	//end = omp_get_wtime();
	integral = h * result;
	printf("The value of the integral is: %lf \n", integral);
	return 0;
}
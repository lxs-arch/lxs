#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
double add(double a, double b) {
	double Add = a + b;
	return Add;
}
double sub(double a, double b) {
	double Sub = a - b;
	return Sub;
}
double mul(double a, double b) {
	double Mul = a * b;
	return Mul;
}
double div(double a, double b) {
	double Div = a / b;
	return Div;
}
int main(void) {
	double a, b;
	char c;
	scanf("%lf %c %lf", &a, &c, &b);
	if (c == '+') {
		double ret = add(a, b);
		printf("%.4f+%.4f=%.4lf",a,b,ret);
		return 0;
	}
	else if (c == '-') {
		double ret = sub(a, b);
		printf("%.4f-%.4f=%.4lf",a,b,ret);
		return 0;
	}
	else if (c == '*') {
		double ret = mul(a, b);
		printf("%.4f*%.4f=%.4lf",a,b,ret);
		return 0;
	}
	else if (c == '/'){
		if (b != 0) {
			double ret = div(a, b);
			printf("%.4f/%.4f=%.4lf",a,b,ret);
		}
        else printf("Wrong!Division by zero!");
			return 0;
	}
    else printf("Invalid operation!");
	return 0;
}

#include<iostream>
int add(int x, int y) {
	int z = x + y;
	return z;
}
double add(double x, double y) {
	float z = x + y;
	return z;
}
int main() {
	int sum1 = add(2, 3);
	double sum2 = add(2.3, 5.4);
	std::cout << sum1 << std::endl << sum2 << std::endl;
	return 0;
}
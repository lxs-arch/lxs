#include<iostream>
class Box {
public:
	float L;
	float B;
	float H;
	float get(void);
	void set(double l, double b, double h);

};
float Box::get() {
	return L* B* H;
}
void Box::set(double l, double b, double h) {
	L = l;
	B = b;
	H = h;
}
int main() {
	Box box1;
	Box box2;
	box1.B = 2;
	box1.H = 3;
	box1.L = 4;
	float v;
	v = box1.B * box1.H * box1.L;
	std::cout << "box1的体积是：" << v << std::endl;
	box2.set(5, 6, 7);
	v = box2.get();
	std::cout << "box2的体积是：" << v << std::endl;



}
#include<iostream>
#include<string>
class School {
public:
	std::string motto="校训";
	void people();
	void locate();
};
class Scyz : public School {
public:
	void age();
};
class Hrbcu : public School {
public:
	void city();
};
void School::locate() {
	std::cout << "在中国" << std::endl;
}
void School::people() {
	std::cout << "有很多人" << std::endl;
}
void Scyz::age() {
	std::cout << "一百多岁" << std::endl;
}
void Hrbcu::city() {
	std::cout << "在哈尔滨" << std::endl;
}

int main() {
	Scyz scyz;
	Hrbcu hrbcu;
	std::cout << scyz.motto << std::endl;
	std::cout << hrbcu.motto << std::endl;
	scyz.age();
	hrbcu.city();
	return 0;
}
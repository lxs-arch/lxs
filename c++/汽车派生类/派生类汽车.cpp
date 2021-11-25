#include<iostream> 
using namespace std;
class vehicle {
protected:
	int wheels;
	float weight;
public:
	vehicle(int wheels, float weight);
	int get_wheels();
	float get_weight();
	void show();
};
class car :public vehicle {
public:
	int passenger;
	car(int wheels, float weight, int passengers);
	int get_passenger();
	void show();
};
class truck :public vehicle {
public:
	float load;
	truck(int wheels, float weight, float loads);
	float get_load();
	void show();
};
vehicle::vehicle(int wheels, float weight) {
	vehicle::wheels = wheels;
	vehicle::weight = weight;
}
int vehicle::get_wheels() {
	return wheels;
}
float vehicle::get_weight() {
	return weight;
}
void vehicle::show() {
	cout << "车轮" << wheels << "个" << endl;
	cout << "车重" << weight << "公斤" << endl;
}
car::car(int wheels, float weight, int passengers) :vehicle(wheels, weight) {
	passenger = passengers;
}
int car::get_passenger() {
	return passenger;
}
void car::show() {
	vehicle::show();
	cout << "人数" << passenger << "个" << endl;
}
truck::truck(int wheels, float weight, float loads) :vehicle(wheels, weight) {
	load = loads;
}
float truck::get_load() {
	return load;
}
void truck::show() {
	vehicle::show();
	cout << "载重" << load << "公斤" << endl;
}
int main() {
	car car1(4, 2000, 5);
	truck truck1(4, 8000, 32000);
	car1.show();
	truck1.show();
}




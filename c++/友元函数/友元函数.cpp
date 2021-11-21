#include<iostream>
#include<string>
using namespace std;
class School {
public:
	string locate;
	
private:
	string Name="王";
	friend void  knownname(School stu);
};

void  knownname(School stu) {
	cout << stu.Name << endl;
}
int main() {
	School stu;
	

	knownname(stu);
	return 0;
}
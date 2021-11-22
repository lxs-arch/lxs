#include <iostream>
using namespace std;
void maxmin(int x, int y, int z, int* max, int* min) {
	*max = (x > y ? x : y) > z ? (x > y ? x : y) : z;
	*min = (x < y ? x : y) < z ? (x < y ? x : y) : z;
}
int main() {
	int x, y, z, max, min;
	cin >> x >> y >> z;
	maxmin(x, y, z, &max, &min);
	cout << "max=" << max << " " << "min=" << min << endl;
	return 0;
}
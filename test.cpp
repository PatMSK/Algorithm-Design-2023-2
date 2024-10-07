#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int x, y, z;
	cin >> y;
	vector<int> vec;
	while (y--) {
		cin >> z;
		vec.push_back(z);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < 7; i++) {
		cout << vec[i] << " ";
	}
}
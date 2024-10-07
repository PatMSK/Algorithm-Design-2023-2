#include <iostream>

using namespace std;

int table[1001][1001];

int main(){
	int r, c;
	char tmp;
	cin >> r >> c;
    int m = 0;

	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>tmp;
			if (tmp == '1') table[i][j] = min(table[i-1][j], min(table[i-1][j-1], table[i][j-1])) + 1;
            else table[i][j] = 0;
            m = max(m, table[i][j]);
		}
	}

	cout << m;
}
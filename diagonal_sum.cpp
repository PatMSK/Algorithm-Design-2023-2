#include <iostream>

using namespace std;
int table[1001][1001];

int main() {
    int n, x;
    int m = -2e9;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (i == 0 or j == 0) table[i][j] = x;
            else table[i][j] = max(table[i-1][j-1] + x, x);
            
            if (table[i][j] > m) m = table[i][j];
        }
    }

    cout << m;
}
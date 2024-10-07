#include <iostream>

using namespace std;
int table[501][501];

int main() {
    int n, m, x;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (i == 0 and j == 0) table[i][j] = x;
            else if (i == 0 and j > 0) table[i][j] = table[i][j-1] + x;
            else if (i > 0 and j == 0) table[i][j] = table[i-1][j]  + x;
            else table[i][j] = max(table[i-1][j] + x, max(table[i][j-1] + x, table[i-1][j-1] + (2*x)));
        }
    }

    cout << table[n-1][m-1];
}
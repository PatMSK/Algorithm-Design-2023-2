#include <iostream>
int table[1000][1000];

using namespace std;
int main() {
    int n, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tmp;
            if (i == 1 and j == 1) table[i][j] = tmp;
            else if (j == 1) table[i][j] = table[i-1][j] + tmp;
            else if (j == i) table[i][j] = table[i-1][j-1] + tmp;
            else {
                table[i][j] = std::max(table[i-1][j-1], table[i-1][j]) + tmp;
            }
        }
    }
    int mx = -2e9;
    for (int i = 1; i <= n; i++) {
        mx = std::max(mx, table[n][i]);
    }

    cout << mx;
}
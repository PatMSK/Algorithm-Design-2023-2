#include <iostream>

using namespace std;

int table[1001][1001];

int main() {
    int n, x;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x == -1) table[i][j] = 1000001;
            else table[i][j] = x;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
            }
        }
    }

    int ans = -2e9;
    bool check = true;
    for (int j = 2; j <= n; j++) {
        if (table[1][j] >= 1000001) {
            cout << -1;
            check = false;
            break;
        }
        ans = max(ans, table[1][j]);
    }

    if (check) cout << ans;


}
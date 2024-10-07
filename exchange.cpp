#include <iostream>

using namespace std;


int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        int table[501][501];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> x;
                table[i][j] = x;
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    table[i][j] = max(table[i][j], table[i][k] * table[k][j]);
                }
            }
        }

        bool check = true;
        for (int i = 1; i <= n; i++) {
            if (table[i][i] > 1) check = false;
        }
        if (check) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    
}
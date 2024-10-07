#include <iostream>

using namespace std;



int main() {
    int n, m, tmp;
    cin >> n >> m;
    int coin[n];
    for (int i = n; i >= 1;i--) {
        cin >> tmp;
        coin[i] = tmp;
    }

    int table[30][30] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) table[i][j] = j;
            else {
                if (j < coin[i]) table[i][j] = table[i-1][j];
                else table[i][j] = min(table[i-1][j], table[i][j - coin[i]] + 1);
            }
            
        }
    }

   cout << table[n][m];
}
#include <iostream>

using namespace std;

int main() {
    int table[1001][1001] = {0};
    int n, m, k, tmp;
    int x1, x2, y1, y2;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)  {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (i == 0 and j == 0) table[i][j] = tmp;
            else if (j == 0 and i > 0) table[i][j] = table[i-1][m-1] + tmp;
            else table[i][j] = table[i][j-1] + tmp;
        }
    }

    while(k--) {
        cin >> x1 >> x2 >> y1 >> y2;
        int ans = 0;
        if ((x1 == x2) and (y1 == y2) and (x1 == y1)) ans = table[x1][x2];
        else if (x1 == 0 and x2 == 0 and y1 == n-1 and y2 == m-1) ans = table[y1][y2];
        else if (x2 == 0) {
            for (int i = x1; i <= y1; i++) {
                if (i == 0) {
                    ans += table[i][y2];
                }
                else {
                    ans += table[i][y2] - table[i-1][m-1];
                }
            }
        }
        else if (x2 > 0){
            for (int i = x1; i <= y1; i++) {
                ans += table[i][y2] - table[i][x2-1];
            }
        }

        cout << ans << "\n";
    }
}
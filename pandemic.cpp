#include <iostream>
#include <queue>


using namespace std;

int table[501][501];

int main() {
    int r, c, t, x;
    queue<pair<int, int> > q;
    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> x;
            if (x == 1) q.push(make_pair(i, j));
            table[i][j] = x;
        }
    }


    while (t--) {
        int num = q.size();
        while (num--) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row + 1 <= r) {
                if (table[row + 1][col] == 0) {
                    table[row + 1][col] = 1;
                    q.push(make_pair(row+1, col));
                }
            }

            if (col + 1 <= c) {
                if (table[row][col + 1] == 0) {
                    table[row][col + 1] = 1;
                    q.push(make_pair(row, col + 1));
                }
            }

            if (col - 1 >= 1) {
                if (table[row][col - 1] == 0) {
                    table[row][col - 1] = 1;
                    q.push(make_pair(row, col - 1));
                }
            }

            if (row - 1 >= 1) {
                if (table[row - 1][col] == 0) {
                    table[row - 1][col] = 1;
                    q.push(make_pair(row - 1, col));
                }
            }
        
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (table[i][j] == 1) ans++;
        }
    }

    cout << ans;


}
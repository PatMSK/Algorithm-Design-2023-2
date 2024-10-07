#include <iostream>

using namespace std;
int table[21][21];
int res = -2e9;
int used[100];
int tail[21];

void travel(int i, int final, int sum, int step, int over) {
    if (i == final) {
        res = max(res, sum);
        return ;
    }

    if (sum + over < res) return ;

    if (step == final - 1) {
        travel(final, final, sum + table[i][final], step + 1, over - table[i][final]);
        return ;
    }

    for (int j = 2; j < final; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            travel(j, final, sum + table[i][j], step + 1, over - table[i][j]);
            used[j] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> table[i][j];
            tail[j] = max(tail[j], table[i][j]);
        }
    }
    int overload = 0;
    for (int i = 1; i <= n; i++) {
        overload += tail[i];
    }

    used[1] = 1;
    travel(1, n, 0, 1, overload);
    cout << res;

   
}
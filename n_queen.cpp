#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> table(12);
int used[12];
int ans = 0;

bool check(int s, int col) {
    for (int i = 0; i < s; i++) {
        if (abs(i - s) == abs(table[i] - col)) return false;
    }
    return true;
}

void n_queen(int step, vector<int> &table, int total) {
    if (step < total) {
        for (int i = 0; i < total; i++) {
            if (used[i] == 0 and check(step, i)) {
                used[i] = 1;
                table[step] = i;
                n_queen(step + 1, table, total);
                used[i] = 0;
            }
        }
    }
    else {
        ans++;
    }
}

int main() {
    int n;
    cin >> n;
    n_queen(0, table, n);
    cout << ans;

}
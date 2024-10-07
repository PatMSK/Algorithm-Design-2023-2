#include <iostream>

using namespace std;
int coin[21] = {0};

int recur(int i, int r) {
    if (i == 0) return 2e9;
    if (coin[i] == r) return 1;
    if (coin[i] > r) return recur(i-1, r);
    return min(recur(i, r - coin[i]) + 1, recur(i-1, r));
}

int main() {
    int n, m, tmp;
    cin >> n >> m;

    for (int i = n; i > 0;i--) {
        cin >> tmp;
        coin[i] = tmp;
    }

    int res = recur(n, m);
    cout << res;
}
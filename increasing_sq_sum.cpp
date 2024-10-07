#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void solve(int prev, int sum, int total) {
    if (sum == total) {
        ans++;
        return ;
    }

    for (int i = 1; i <= total; i++) {
        if (sum + i <= total and i >= prev) {
            solve(i, sum + i, total);
        }
    }
}

int main() {
    int n;
    cin >> n;
    solve(0, 0, n);
    cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int sum[101];
int n;

int ans = 2e9;

void search(int remain, int i, int s, int total, int N, vector<int> &a) {
    if (remain == 0) {
        ans = min(ans, abs(total - s));
        return ;
    }

    if (total - (s + sum[N] - sum[N - remain]) >= ans) return ;
    if ((s + sum[remain]) - total >= ans) return ;
    if (N - i - 1< remain) return ;
    if (i > N) return ;

    search(remain - 1, i + 1, s + a[i], total, N, a);
    search(remain, i + 1, s, total, N, a);
}



int main() {
    int  m, k, tmp;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // a.push_back(0);
    sort(a.begin(), a.end());
    sum[1] = a[1];
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    search(m, 1, 0, k, n, a);
    cout << ans;


}
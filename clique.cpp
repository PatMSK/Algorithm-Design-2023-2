
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int power[51];
int f[51][51];
int visited[51];
int overload[51];
int ans = -2e9;

bool check(int x, int ar[], int pick) {
    for (int i = 0; i < pick; i++) {
        if (f[ar[i]][x] == 0) return false;
        if (f[x][ar[i]] == 0) return false;
        if (ar[i] == x) return false;
    }
    return true;
}

void recur(int x, int total, int step, int sum, int arr[]) {
    if (step == total - 1) {
        ans = max(ans, sum);
        return ;
    }
    if (sum + overload[total] - overload[x] < ans) return ;
    for (int i = 1; i <= total; i++) {
        if (visited[i] == 0 && check(i, arr, step)) {
            visited[i] = 1;
            arr[step] = i;
            recur(i, total, step + 1,sum + power[i], arr);
            arr[step] = 0;
            visited[i] = 0;
        }
    }

    ans = max(ans, sum);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); 
    int n;
    cin >> n;
    overload[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
        overload[i] = overload[i-1] + power[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> f[i][j];
        }
    }
    int a[51];
    recur(0, n, 0, 0, a);
    cout << ans;
} 
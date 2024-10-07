#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int ans[100001];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; i++) {
        cin >> vec[i];
    }

    double res = 0.0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        ans[i] = vec[i];
        res += ans[i];
    }
    for (int i = n; i < m; i++) {
        ans[i] = ans[i - n] + vec[i];
        res += ans[i];
    }



    cout << fixed << setprecision(3) << res / m;
}
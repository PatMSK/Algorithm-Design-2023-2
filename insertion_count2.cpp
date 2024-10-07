#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, tmp, q;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v[i] = tmp;
    }


    for (int i = 0; i < m; i++) {
        cin >> q;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] > q) ans += 1;
            if (v[j] == q) {
                cout << ans << "\n";
                break;
            } 
        }
    }


}
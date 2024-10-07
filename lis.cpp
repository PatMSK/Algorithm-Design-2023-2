#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> v(n+1), s(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        v[i] = tmp;
        s[i] = tmp;
    }

    sort(s.begin() + 1, s.end());
    int table[1001][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i] == v[j]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }

    cout << table[n][n];
}
#include <iostream>

using namespace std;

int table[10001];

int main() {
    int n, k, x;
    cin >> n >> k;
    int s[11];
    for (int i = 1; i <= k; i++) {
        cin >> x;
        s[i] = x;
    }
    table[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (s[j] <= i)  table[i] = (table[i] + table[i - s[j]]) % 1000003;
        }
    }

    cout << table[n];
}
#include <iostream>

using namespace std;

int table[100001];

int main() {
    int n, k, x, b;
    int m = 32717;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> table[i];
    }
    for (int i = k + 1; i <= n; i++) {
        cin >> x;
        int res = 0;
        for (int j = 1; j <= x; j++) {
            cin >> b;
            if (i - b > 0) table[i] = ((table[i] % m) + (table[i-b] % m)) % m;
        }   
        
    }

    for (int i = 1; i <= n; i++) {
        cout << table[i] << " ";
    }
}
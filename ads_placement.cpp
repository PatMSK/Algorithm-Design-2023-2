#include <iostream>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    int table[10001];
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (i == 0 or i == 1) table[i] = tmp;
        else if (i == 2) table[i] = table[i-2] + tmp;
        else if (i >= 3) table[i] = max(table[i-2], table[i-3]) + tmp;

        if (table[i] > m) m = table[i];
    }

    cout << m;
}
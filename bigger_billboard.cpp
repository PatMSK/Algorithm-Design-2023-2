#include <iostream>

using namespace std;
int table[10001] ={0};

int main() {
    int n, x;
    int m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (i == 0 or i == 1 or i == 2) table[i] = x;
        else if (i == 3) table[i] = table[i-3] + x;
        else if (i == 4) table[i] = max(table[i-3], table[i-4]) + x;
        else if (i > 4) table[i] = max(table[i-3], max(table[i-4], table[i-5])) + x;

        if (table[i] > m) m = table[i];
    }

    cout << m;
}
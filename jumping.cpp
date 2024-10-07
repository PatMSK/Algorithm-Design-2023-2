#include <iostream>

using namespace std;
int main() {
    int n, tmp;
    cin >> n;
    int table[n];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (i == 0) table[i] = tmp;
        else if (i == 1) table[i] = table[i-1] + tmp;
        else if (i == 2) table[i] = max(table[i-2], table[i-1]) + tmp;
        else table[i] = max(table[i-3], max(table[i-2], table[i-1])) + tmp;
    }

    cout << table[n-1];


}
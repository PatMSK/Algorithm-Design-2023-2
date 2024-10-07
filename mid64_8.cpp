#include <iostream>

using namespace std;
int table[101];

int main() {
    int n, tmp;
    cin >> n;
    int p[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        p[i] = tmp;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            table[i] = max(table[i], table[i-j] + p[j]);
        }
    }


    cout << table[n];
}
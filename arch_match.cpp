#include <iostream>

using namespace std;

int table[501][501];
int a[501];

int main() {
    int n, tmp;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        a[i] = tmp;
        table[i][i] = 0;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 1; i <= n - k;i++) {
                int o = (a[i] * a[i+k]) + table[i+1][i+k-1];
                for (int c = i; c < i+k; c++) {
                    o = max(o, table[i][c] + table[c+1][i+k]);
                }
                table[i][i+k] = o;
        }
    }


    cout << table[1][n];



}
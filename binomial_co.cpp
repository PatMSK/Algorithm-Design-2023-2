#include <iostream>

using namespace std;
int table[30][30] = {0};

int recur(int l, int r) {
    if ((l == r) or (r == 0)) return 1;

    if (table[l][r] != 0) return table[l][r];

    int res = recur(l-1, r-1) + recur(l-1, r);
    table[l][r] = res;
    return res; 
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << recur(n ,k);
}
#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int table[1001][1001];

int recur(int l, int r) {
    if (l+1 == r) {
        table[l][r] = max(a[l], a[r]);
        return table[l][r];
    }

    if (table[l][r] > 0) return table[l][r];

    int con1 = max(a[l], a[r]) + recur(l+1, r-1);
    int con2 = max(a[l], a[l+1]) + recur(l+2, r);
    int con3 = max(a[r], a[r-1]) + recur(l, r-2);

    table[l][r] = max(con1, max(con2, con3));
    return table[l][r];
    
    
}


int main() {
    int n, tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[i] = tmp;
    }

    int res = recur(0, n-1);
    cout << res;


}
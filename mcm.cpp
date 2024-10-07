#include <iostream>

using namespace std;
int table[99][99] = {0};

int recur(int m[], int l , int r) {
    if (l == r) {
        return 0;
    }

    if (table[l][r] > 0) return table[l][r];
    int min_res = 2e9;

    for (int i = l; i < r; i++) {
        int res = recur(m, l, i) + recur(m, i+1, r) + (m[l-1] * m[i] * m[r]);
        min_res = std::min(res, min_res);
    }

    table[l][r] = min_res;
    return min_res;
}

int main() {
    int n, tmp;    
    cin >> n;
    n++;
    int mat[n];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mat[i] = tmp;  
    }

    cout << recur(mat, 1, n - 1);
    

}
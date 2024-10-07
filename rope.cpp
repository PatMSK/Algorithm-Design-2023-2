#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int recur(vector<int> i, int remain, int x) {
    int res = 0;
    if (remain - x < 0) return -2e9;
    if (remain - x == 0) return 1;
    if (x == i[2]) {
        res = std::max(recur(i, remain - x,i[2]), std::max(recur(i, remain - x,i[1]), recur(i, remain - x,i[0]))) + 1;
    }
    if (x == i[1]) {
        res = std::max(recur(i, remain - x,i[1]), recur(i, remain - x, i[0])) + 1;
    }
    if (x == i[0]) {
        res = recur(i, remain - x, i[0]) + 1;
    }
    return res;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> inx;
    inx[0] = a; inx[1] = b; inx[2] = c;
    sort(inx.begin(), inx.end());
    cout << recur(inx, n, inx[2]);
    
}
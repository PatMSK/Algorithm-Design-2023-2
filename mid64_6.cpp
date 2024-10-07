#include <iostream>

using namespace std;


int recur(int x, int remain, int dis[], int idx_remain, int idx, int total) {
    if (idx == total) {
        if (remain != 0) return 0;
    }
    if (remain == 0) {
        //call display(dis[])
        return 0;
    }
    if (remain < 0) return 0;
    int height = remain - idx_remain + 1;
    for (int i = 1; i <= height; i++) {
        dis[idx] = i;
        recur(i, remain-i, dis, idx_remain-1, idx+1, total);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int h = m - n + 1;
    int a[n];
    for (int i = 1; i <= h; i++) {
        a[0] = i;
        recur(i, m-i, a, n-1, 1, n);
    }
    
}
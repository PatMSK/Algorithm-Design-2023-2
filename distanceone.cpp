#include <iostream>

using namespace std;
int c = 0;

void recur(int num, int count, int dis, int idx, int N) {
    if (idx == N) {
        c++;
        return ;
    }
    if (num == 1) recur(0, 1, dis, idx + 1, N);
    if (num == 0) {
        if (count >= dis or count == 0) {
            recur(0, count, dis, idx + 1, N);
            recur(1, 0, dis, idx + 1, N);
        }
        else if (count >= 1) recur(0, count + 1, dis, idx + 1, N);
        
    }
}


int main() {
    int n, k;
    cin >> n >> k;
    recur(1, 0, k-1, 1, n);
    recur(0, 0, k-1, 1, n);
    cout << c%100000007;
}
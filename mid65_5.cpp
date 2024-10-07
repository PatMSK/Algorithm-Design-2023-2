#include <iostream>

using namespace std;

int B[101];

int main() {
    int n, p, q, k;
    cin >> n >> p >> q >> k;

    for (int i = 1 ; i <= n; i++) {
        if (i <= k) B[i] = 0;
        else {
            B[i] = B[i - p] + B[i - q] + 1;
        }
    }

    cout << B[n];
}


#include <iostream>
#include <vector>

using namespace std;

int c[701][701];

int main() {
    int n, m, a, b, r;
    
    cin >> n >> r;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = 20000000;
        }
    }
    c[1][2] = r;
    c[2][1] = r;
    for (int i = 3; i <= n; i++) {
        cin >> m;
        while (m--) {
            cin >> a >> b;
            c[a][i] = b;
            c[i][a] = b;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
        if (k >= 3) cout << c[1][2] << " ";
    }
    

    
}
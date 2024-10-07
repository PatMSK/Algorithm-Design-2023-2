#include <iostream>

using namespace std;
int table[501][501] = {0};



int main() {
    string x, y;
    cin >> x >> y;
    x = 'H' + x;
    y = 'H' + y;
    for(int i = 1; i <= x.length() - 1; i++) {
        for (int j = 1; j <= y.length() - 1;j++) {
            if (x[i] == y[j]) table[i][j] = table[i-1][j-1] + 1;
            else table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }


    cout << table[x.length()-1][y.length()-1];

}
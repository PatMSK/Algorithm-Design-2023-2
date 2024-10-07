#include <iostream>
#include <vector>

using namespace std;
int table[101];
int w[101][101];
vector<pair<int, int> > edges(101);

int main() {
    int n, e, s, a, b, c;
    cin >> n >> e >> s;
    table[s] = 0;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        w[a][b] = c;
        edges.push_back(make_pair(a, b));
    }

    for (int i = 0; i < n; i++) {
        if (i != s) table[i] = 2e9;
    }

    bool check = true;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            int a = e.first;
            int b = e.second;
            if (table[b] > table[a] + w[a][b]) table[b] = table[a] + w[a][b];
        }
        
    }

    for (auto e : edges) {
            int a = e.first;
            int b = e.second;
            if (table[b] > table[a] + w[a][b]) check = false;
        }

    if (check) {
        for (int i = 0; i < n; i++) {
            cout << table[i] << " ";
        }
    }
    else {
        cout << -1;
    }
}
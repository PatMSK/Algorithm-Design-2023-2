#include <iostream>
#include <vector>

using namespace std;

vector<int> start(5001);
int cost[5001][5001];
int table[5001];
vector<pair<int, int> > edges;

int main() {
    int n, m, k, finish, s;
    cin >> n >> m >> k;
    cin >> finish;

    for (int i = 1; i <= k; i++) {
        cin >> s;
        start[i] = s;
    }

    for (int i = 0; i < n; i++) {
        table[i] = 2e9;
    }

    table[finish] = 0;

    int a, b, w;
    while (m--) {
        cin >> a >> b >> w;
        cost[b][a] = w;
        edges.push_back(make_pair(b,a));
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto edge : edges) {
                int f = edge.first;
                int l = edge.second;
                if (table[l] > table[f] + cost[f][l]) table[l] = table[f] + cost[f][l];
            }
        }
    }


    int ans = 2e9;
    for (int i = 1; i <=k; i++) {
        ans = min(ans, table[start[i]]);
    }

    
    cout << ans;

}

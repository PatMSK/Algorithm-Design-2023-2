#include <iostream>
#include <set>
#include <vector>

using namespace std;

int table[1001][1001];
int cost[1001];
int taken[1001];
vector<vector<int> > vec(1001);

int main() {
    int n, num, x, j;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        j = i + 1;
        num = n - i - 1;
        while (num--) {
            cin >> x;
            table[i][j] = x;
            table[j][i] = x;
            vec[i].push_back(j);
            vec[j].push_back(i);
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        cost[i] = 2e9;
    }

    set<pair<int, int> > s;
    //insert (cost[u], u)
    s.insert(make_pair(0, 0));
    cost[0] = 0;
    while (!s.empty()) {
        auto it = s.begin();
        int cur = (*it).second;
        taken[cur] = 1;
        s.erase(it);
        for (auto adj : vec[cur]) {
            if (cost[adj] > table[cur][adj] && taken[adj] == 0) {
                if (s.find(make_pair(cost[adj], adj)) != s.end()) {
                    s.erase(make_pair(cost[adj], adj));
                }
                cost[adj] = table[cur][adj];
                s.insert(make_pair(cost[adj], adj));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cost[i];
    }

    cout << ans;


}
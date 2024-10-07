#include <iostream>
#include <vector>
#include <set>

using namespace std;
int w[701][701];
int cost[701];
vector<vector<int> > vec(701);

int main() {
    int n, p, a, b;
    cin >> n >> w[1][2];
    w[2][1] = w[1][2];
    vec[1].push_back(2);
    vec[2].push_back(1);
    cost[1] = 0;
    cost[2] = 2e9;
    int next = 2;
    for (int i = 1; i <= n-2; i++) {
        cin >> p;
        next++;
        cost[next] = 2e9;
        while (p--) {
            cin >> a >> b;
            w[a][next] = b;
            w[next][a] = b;
            vec[a].push_back(next);
            vec[next].push_back(a);
        }

        //dijk (t, u)
        int ans = 2e9;
        set<pair<int, int> > s;
        s.insert(make_pair(0, 1));
        while (!s.empty()) {
            auto it = s.begin();
            int t = (*it).first;
            int cur = (*it).second;
            s.erase(it);
            if (cur == 2) {
                ans = min(ans, cost[2]);
                continue;
            }
            for (auto adj : vec[cur]) {
                if (cost[adj] > t + w[cur][adj]) {
                    if (s.find(make_pair(cost[adj] ,adj)) != s.end()) {
                        s.erase(make_pair(cost[adj] ,adj));
                    }
                    cost[adj] = t + w[cur][adj];
                    s.insert(make_pair(cost[adj] ,adj));
                }
                else if (cost[adj] == t + w[cur][adj]) {
                   if (s.find(make_pair(cost[adj] ,adj)) == s.end()) {
                        s.insert(make_pair(cost[adj] ,adj));
                    }
                }
            }
        }

        cout << cost[2] << " ";

    }
}
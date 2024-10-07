#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int start[10001];
int c[10001];
int dis[10001];
vector<vector<int> > vec(10001);

int main() {
    int n, m, k, x, tmp, a, b;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> start[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
         dis[i] = 2e9;
    }


    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }


    // t, node
        set<pair<int, int> > s;
        for (int i = 0; i < k; i++) {
            s.insert(make_pair(c[start[i]], start[i]));
            dis[start[i]] = c[start[i]];
        }
        while (!s.empty()) {
            auto it = s.begin();
            int t = (*it).first;
            int cur = (*it).second;
            s.erase(it);
            for (auto adj : vec[cur]) {
                if (dis[adj] > t + c[adj]) {
                    if (s.find(make_pair(dis[adj] , adj)) != s.end()) s.erase(make_pair(dis[adj] , adj));
                    dis[adj] = t + c[adj];
                    s.insert(make_pair(dis[adj] , adj));
                    // cout << dis[adj] << adj << "|";
                }
            }
        }

    int ans = -2e9;
    for (int i = 0; i < n; i++) {
        ans = max(ans ,dis[i]);
    }

    cout << ans;

}
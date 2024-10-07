#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > vec(1001);


int main() {
    int n, e, k, a, b;
    cin >> n >> e >> k;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        vec[b].push_back(a);
        vec[a].push_back(b);
    }

    int ans = -2e9;
    int dis[1001];
    int count = -2e9;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        dis[i] = -1;
    }

    //bfs
    for (int i = 0; i < n; i++) {
        q.push(i);
        dis[i] = 0;
        count = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto adj : vec[cur]) {
                if (dis[adj] == -1) {
                    dis[adj] = dis[cur] + 1;
                    if (dis[adj] < k) {
                        q.push(adj);
                        count++;
                    }
                    else if (dis[adj] == k) {
                        count++;
                    }
                }
            }
        }
        ans = max(ans, count);

        for (int j = 0; j < n; j++) {
            dis[j] = -1;
        }
    }

    cout << ans;




}
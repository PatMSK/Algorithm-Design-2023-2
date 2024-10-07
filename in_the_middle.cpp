#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > vec(250001);
int dis[4][250001];


void bfs(int node, int idx) {
    int ans = 2e9;
    queue<int> q;
    q.push(node);
    dis[idx][node] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto adj : vec[cur]) {
            if (dis[idx][adj] == -1) {
                dis[idx][adj] = dis[idx][cur] + 1;
                q.push(adj);
            }
        }
    }
            
}

int main() {
    int n, e, x;
    int t1, t2, t3;
    int result = 2e9;
    cin >> n;
    cin >> t1 >> t2 >> t3;
    for (int i = 1; i <= n; i++) {
        cin >> e;
        while (e--) {
            cin >> x;
            vec[i].push_back(x);
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = -1;
        }
    }

    bfs(t1, 1);
    bfs(t2, 2);
    bfs(t3, 3);
    

    for (int i = 1; i <= n; i++) {
        int ans1 = dis[1][i];
        int ans2 = dis[2][i];
        int ans3 = dis[3][i];
        if (ans1 == -1 || ans2 == -1 || ans3 == -1) continue;
        
        int r = max(ans1, max(ans2, ans3));
        result = min(result, r);
    }

    // for (int i = 1; i <= 3; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (j != n) cout << dis[i][j] << " ";
    //         else cout << dis[i][j] << "\n";
    //     }
    // }

    cout << result;
}
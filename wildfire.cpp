#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int table[5001];
int day[5001];
int visited[5001];
vector<vector<int> > vec(5001);


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, k, b, d, x, y;
    cin >> n >> m >> k;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> b;
        table[i] = b;
        ans += b;
    }

    for (int i = 1; i <= k; i++) {
        cin >> d;
        day[i] = d;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
    }

    queue<int> q;
    for (int i = 1; i <= k; i++) {
        ans -= table[day[i]];
        table[day[i]] = 0;
        q.push(day[i]);
        while (!q.empty()) {
            if (visited[q.front()] == 1) {
                q.pop();
                continue;
            }
            int cur = q.front();
            q.pop();
            visited[cur] = 1;
            for (auto adj : vec[cur]) {
                if (visited[adj] == 0) {
                    q.push(adj);
                    ans -= table[adj];
                    table[adj] = 0;
                }
            }
        }
        cout << ans << " ";
    }

    

}
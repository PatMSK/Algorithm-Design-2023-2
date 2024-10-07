#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > vec(1001);
int visited[1001];
int c = 0;
queue<int> q;
int distance[1001];

void bfs(int node, int K) {
    visited[node] = 1;
    q.push(node);
    distance[node] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int adj : vec[node]) {
            if (visited[adj] == 0) {
                q.push(adj);
                distance[adj] = distance[cur] + 1;
            }

            if (distance[adj] == K) {
                c++;
                return ;
            }
        }
    }
}

int main() {
    int n, e, k, a, b;
    cin >> n >> e >> k;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    bfs(0, k);
    cout << c;

}
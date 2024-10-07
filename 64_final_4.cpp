#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > edges(10);
int visited[10];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto e : edges[x]) {
            if (visited[e] == 0) {
                visited[e] = 1;
                q.push(e);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    edges[1].push_back(2);
    edges[1].push_back(3);
    edges[1].push_back(4);
    edges[2].push_back(1);
    edges[2].push_back(3);
    edges[2].push_back(4);
    edges[3].push_back(1);
    edges[3].push_back(2);
    edges[3].push_back(4);
    edges[3].push_back(5);
    edges[4].push_back(1);
    edges[4].push_back(2);
    edges[4].push_back(3);
    edges[5].push_back(3);

    bfs(n);

    // for (int i = 1; i <= 5; i++) {
    //     for (auto e : edges[i]) {
    //         cout << e << " ";
    //     }
    // }
}
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > vec(200001);
int visited[200001];
int num, one_edge, two_edge;

void dfs(int node) {
    num++;
    visited[node] = 1;
    if (vec[node].size() == 1) one_edge++;
    if (vec[node].size() == 2) two_edge++;
    for (auto e : vec[node]) {
        if (visited[e] == 0) dfs(e);
    }

}

bool check(int node) {
    num = 0, one_edge = 0, two_edge = 0;
    dfs(node);
    return (num == 1 || (one_edge == 2 && two_edge == num - 2));
}

int main() {
    int v, e, x, y;
    cin >> v >> e;

    if (e == 0) {
        cout << v;
        return 0;
    }
    
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0) {
            if (check(i) == true) ans += 1;
        }
    }

    cout << ans;

}
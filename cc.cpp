#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int visited[10001];
map<int, vector<int> > mp;

void dfs_cc(int a) {
    visited[a] = 1;
    for (auto e : mp[a]) {
        if (visited[e] == 0) dfs_cc(e);
    }
}

int cc(int E) {
    int cc_num = 0;
    for (int i = 1; i <= E; i++) {
        if (visited[i] == 0) {
            cc_num += 1;
            dfs_cc(i);
        }
    }
    return cc_num;
}



int main() {
    int v, e, x, y;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    cout << cc(v);


}
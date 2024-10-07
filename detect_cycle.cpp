#include <iostream>
#include <map>
#include <vector>

using namespace std;

int v[1001];
map<int, vector<int> > mp;

bool dfs(int ver, int parent) {
    v[ver] = 1;
    for (auto e : mp[ver]) {
        if (v[e] == 0) {
            if (dfs(e, ver)) return true;
        }
        else if (e != parent) return true;
    }
    return false;
}

bool detect_cycle(int ver) {
    
    for (int i = 0; i < ver; i++) {
        if (v[i] == 0) {
            if (dfs(i, -1)) return true;
        }
    }
    return false;
}



int main() {
    int t, n, e, x, y;
    cin >> t;
    while (t--) {
        
        cin >> n >> e;
        if (e == 0) cout << "NO" << '\n';
        else {
            for (int i = 0; i < e; i++) {
                cin >> x >> y;
                mp[x].push_back(y);
                mp[y].push_back(x);
                
            }
            if (detect_cycle(n)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        mp.clear();

        for (int i = 0; i < n; i++) v[i] = 0;
    }
}
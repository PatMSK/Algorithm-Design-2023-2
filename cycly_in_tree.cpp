#include <iostream>
#include <map>
#include <vector>

using namespace std;

int visited[100001];
map<int, vector<int> > mp;
map<int, int> dis;
int ans;


void dfs(int x, int parent, int c) {
    visited[x] = 1;
    dis[x] = c;
    for (auto e : mp[x]) {
        if (visited[e] == 0) {
            dfs(e, x, c+1);
        }
        else if (e != parent) {
            cout << c - dis[e] + 1;
            exit(0);
        }
    }


}


int main() {
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    dis[0] = 0;
    dfs(0, -1, 1);
    
}
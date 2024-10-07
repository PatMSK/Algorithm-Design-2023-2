#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int deg[1001];
vector<vector<int> > point(1001);


int main() {
    int n, m, x;
    queue<int> zero_deg;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m == 0) {
            zero_deg.push(i);
        }
        else {
            deg[i] += m;
            while (m--) {
                cin >> x;
                point[x].push_back(i);
            }
        }
    }

    vector<int> ans;
    int node;

    while (!zero_deg.empty()) {
        node = zero_deg.front();
        zero_deg.pop();
        for (int e : point[node]) {
            deg[e]--;
            if (deg[e] == 0) zero_deg.push(e);
        }
        ans.push_back(node);
    }


    for (auto e : ans) {
        cout << e << " ";
    }



}
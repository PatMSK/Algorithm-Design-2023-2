#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > pre(1001);
int in_deg[1001];
int in_check[1001];


int main() {
    int n, e, a, b, x;
    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        cin >> a >> b;
        pre[a].push_back(b);
        in_deg[b]++;
    }

    for (int i = 1; i <= 5; i++) {
        for (int k = 1; k <= n; k++) {
            in_check[k] = in_deg[k];
        }

        bool check = true;
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (in_check[x] == 0) {
                in_check[x] = -1;
                for (auto e : pre[x]) {
                    in_check[e]--;
                }
            }
            else check = false;
        }

        if (check) cout << "SUCCESS" << "\n";
        else cout << "FAIL" << "\n";
        
    }


}
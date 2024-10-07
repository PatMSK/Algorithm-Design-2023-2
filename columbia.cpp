#include <iostream>
#include <set>

using namespace std;

int table[1001][1001];
int ans[1001][1001];
int cost[1001][1001];

int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> table[i][j];
            cost[i][j] = 2e9;
            ans[i][j] = 2e9;
        }
    }

    int t1[4] = {1, -1, 0, 0};
    int t2[4] = {0, 0, 1, -1};


    set<pair<int, pair<int, int> > > s;
    s.insert(make_pair(0, make_pair(1, 1)));
    while (!s.empty()) {
        auto it = s.begin();
        int cur_x = (*it).second.first;
        int cur_y = (*it).second.second;
        int fee = (*it).first;
        s.erase(it);
        if (cur_x < 1 || cur_x > r || cur_y < 1 || cur_y > c) continue;
        ans[cur_x][cur_y] = min(ans[cur_x][cur_y], fee);

        for (int k = 0; k < 4; k++) {
            int next_x = cur_x + t1[k];
            int next_y = cur_y + t2[k];
            if (cost[next_x][next_y] > fee + table[next_x][next_y]) {
                if (s.find(make_pair(cost[next_x][next_y], make_pair(next_x, next_y))) != s.end()) {
                    s.erase(make_pair(cost[next_x][next_y], make_pair(next_x, next_y)));
                }
                cost[next_x][next_y] = fee + table[next_x][next_y];
                s.insert(make_pair(cost[next_x][next_y], make_pair(next_x, next_y)));
                
            }           
        }

    }


    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (j < c) cout << ans[i][j] << " ";
            else cout << ans[i][j] << "\n";
        }
    }


}
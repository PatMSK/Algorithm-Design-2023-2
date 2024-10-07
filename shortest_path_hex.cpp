#include <iostream>
#include <set>

using namespace std;

int cost[301][301];
int table[301][301];
int visited[301][301];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int odd1[] = {-1, -1 , 1, 1};
    int odd2[] = {-1, 0, -1, 0};
    int even1[] = {-1, -1, 1, 1};
    int even2[] = {0, 1, 0, 1};
    int r, c, a1, a2, b1, b2;
    cin >> r >> c;
    cin >> a1 >> b1 >> a2 >> b2;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> cost[j][i];
            table[j][i] = 2e9;
        }
    }

    set<pair<int, pair<int, int> > > s;
    s.insert(make_pair(cost[a1][b1], make_pair(a1, b1)));
    int ans = 2e9;
    while (!s.empty()) {
        auto it = s.begin();
        int dis = (*it).first;
        int x = (*it).second.first;
        int y = (*it).second.second;
        s.erase(it);
        // cout << x << y << " ";
        if (x > r || x < 1 || y > c || y < 1) continue;
        if (x == a2 && y == b2) {
            ans = min(ans, dis);
            // cout << ans << " ";
            continue;
        }

        if (x % 2 == 1) {
            for (int i = 0; i < 4; i++) {
                int nx = x + odd1[i];
                int ny = y + odd2[i];
                if (table[nx][ny] > dis + cost[nx][ny]) {
                    if (s.find(make_pair(table[nx][ny], make_pair(nx, ny))) != s.end()) s.erase(make_pair(table[nx][ny], make_pair(nx, ny)));
                    table[nx][ny] = dis + cost[nx][ny];
                    // cout << table[nx][ny] << nx << ny << " ";
                    s.insert(make_pair(table[nx][ny], make_pair(nx, ny)));
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                int nx = x + even1[i];
                int ny = y + even2[i];
                if (table[nx][ny] > dis + cost[nx][ny]) {
                    if (s.find(make_pair(table[nx][ny], make_pair(nx, ny))) != s.end()) s.erase(make_pair(table[nx][ny], make_pair(nx, ny)));
                    table[nx][ny] = dis + cost[nx][ny];
                    // cout << table[nx][ny] << nx << ny << " ";
                    s.insert(make_pair(table[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }

    cout << ans;

}
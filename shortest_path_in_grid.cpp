#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char table[101][101];
int visited[101][101];

int main() {
    int r, c;
    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j<= c; j++) {
            cin >> table[i][j];
        }
    }

    int t1[4] = {-1, 1, 0, 0};
    int t2[4] = {0, 0, 1, -1};

    // ((a, b), dis)
    queue<pair<pair<int,int>, int> > q;
    int ans = 2e9;
    q.push(make_pair(make_pair(1,1), 0));
    visited[1][1] = 1;
    while(!q.empty()) {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        if (cur_x > r || cur_y > c || cur_x < 1 || cur_y < 1) {
            continue;
        }
        if (cur_x == r && cur_y == c) {
            ans = min(ans, dis);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + t1[i];
            int next_y = cur_y + t2[i];
            if (visited[next_x][next_y] == 0 && table[next_x][next_y] == '.') {
                visited[next_x][next_y] = 1;
                q.push(make_pair(make_pair(next_x, next_y), dis+1));
            }
        }
    }

    if (ans == 2e9) cout << -1;
    else cout << ans;
    


}
#include <iostream>
#include <queue>

using namespace std;

int table[1001][1001];
int visited[1001][1001];

int ans = 2e9;

int main() {
    int n, x, y, a, b;
    cin >> n >> a >> b;


    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        table[y][x] = 1;
    }

    int t1[4] = {1,-1,0,0};
    int t2[4] = {0,0,1,-1};
    int next_x = 0, next_y = 0;

    // ((x,y), holed)
    visited[b][a] = 1;
    queue<pair<pair<int, int> , int> > q;
    q.push(make_pair(make_pair(b,a), 0));
    while(!q.empty()) {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int holed = q.front().second;
        // visited[cur_y][cur_x] = 1;
        q.pop();
        if (cur_x == 1 or cur_x == 1000 or cur_y == 1000 or cur_y == 1) {
            ans = min(ans, holed);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            next_x = cur_x + t1[i];
            next_y = cur_y + t2[i];
            if (visited[next_y][next_x] == 0) {
                visited[next_y][next_x] = 1;
                if (table[next_y][next_x] == 1) q.push(make_pair(make_pair(next_y,next_x), holed + 1));
                else q.push(make_pair(make_pair(next_y,next_x), holed));
            }
        }
    }

   
    cout << ans;

}
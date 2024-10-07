#include <iostream>
#include <vector>
#include <set>
#include <queue>

using ull = unsigned long long;
using namespace std;
ull cost[2001];
int taken[2001];
ull vec[2001];

int main() {
    ull n, x;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        vec[i] = x;
        cost[i] = 0;
    }

    set<pair<ull, ull> > s;
    s.insert(make_pair(0, 0));
    cost[vec[0]] = 0;
    while(!s.empty()) {
        auto it = s.end();
        it--;
        int cur = (*it).second;
        taken[cur] = 1;
        s.erase(it);
        for (int adj = 0; adj < n; adj++) {
            if (cost[adj] < (vec[adj] ^ vec[cur]) && taken[adj] == 0) {
                if (s.find(make_pair(cost[adj], adj)) != s.end()) {
                    s.erase(make_pair(cost[adj], adj));
                }
                cost[adj] = (vec[adj] ^ vec[cur]);
                s.insert(make_pair(cost[adj], adj));
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cost[i];
    }

    cout << ans;
}
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

float weight[100001];
float price[100001];
vector<pair<float, float> > summary;

double recur(float remain, int idx) {
    if (remain > summary[idx].second) return summary[idx].first + recur(remain - summary[idx].second, idx + 1);
    return (remain / summary[idx].second) * summary[idx].first;
}

int main() {
    float w, x;
    int n;
    vector<pair<float, pair<float, float> > > items;
    cin >> w >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 1; i <= n; i++) {
        items.push_back(make_pair((price[i] / weight[i]), make_pair(price[i], weight[i])));
    }

    sort(items.begin(), items.end());

    for (int i = n; i >= 1; i--) {
        float p = items[i].second.first;
        float we = items[i].second.second;
        summary.push_back(make_pair(p, we));
    }

    // cout << recur(w, 0);
    cout << setprecision(4) << fixed << recur(w, 0);
}
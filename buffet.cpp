#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int f, w, n;
    cin >> f >> w >> n;
    vector<int> food(f);
    for (int i = 0; i < f; i++) {
        cin >> food[i];
    }
    sort(food.begin(), food.end());
    
    int ans = 1;
    int cur = food[0];
    for (int i = 0; i < f; i++) {
        if (food[i] > cur + 2*w) {
            ans++;
            cur = food[i];
        }
    }

    cout << ans;
}
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> mp;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        mp[tmp] += 1;
    }
    
    int sum = 1;

    for (auto x : mp) {
        int res = x.second;
        if (res == 1) sum *= 1;
        else sum *= res * (res - 1);
    }

    cout << sum;
}
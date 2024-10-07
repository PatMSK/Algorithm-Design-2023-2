#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
   int n, l;
   cin >> n >> l;
   vector<int> vec(n);
   for (int i = 0; i < n; i++) {
    cin >> vec[i];
   }
   sort(vec.begin(), vec.end());
   int cur = vec[0];
   int ans = 1;
   for (int i = 0; i < n; i++) {
    if (vec[i] > cur + l - 1) {
        ans++;
        cur = vec[i];
    }
   }

   cout << ans;
}
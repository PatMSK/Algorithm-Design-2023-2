#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> ans(m);

   for (int i = 0; i < n; i++) {
        cin >> x;
        A[i] = x;
   }

   int q;
   unordered_map<int, int> mp;
   
   for (int i = 0; i < m; i++) {
    cin >> q;
    mp[q] = 0;
    ans[i] = q;
   }


   for (int pos = A.size()-2;pos >= 0;pos--) {
        int tmp = A[pos];
        size_t i = pos+1;
        while (i < A.size() && A[i] < tmp) {
            if (mp.count(A[i])) mp[A[i]] += 1;
            A[i-1] = A[i];
            i++;
        }
        A[i-1] = tmp;
        }

    for (int i = 0; i < m; i++) {
        cout << mp[ans[i]] << "\n";
    }
    
    
}
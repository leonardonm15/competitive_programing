#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
   map<pair<int, int>, int> mp; // numero, quantidade de vezes por q trio
   int n; cin >> n;
   int arr[n];
   for (int i=0; i < n; i++) cin >> arr[i];

   map<int, int> amm;
   int triples = 0;
   int resp = 0;
   for (int i=0; i < n; i++) {
        if (i <= 2) amm[arr[i]]++;
        else {
            if (i > 2) {
                amm[arr[i - 3]]--;
                amm[arr[i]]++;
            }

            if (amm[arr[i]] == 3) {
                continue;
            }
            
            for (int k=0; k <= 2; k++) {
                for (int j=0; j <= 2; j++) {
                    if (k != j && arr[i - k] != arr[i - j]) {
                         // tem que ser igual nos idx i e j
                         pair<int, int> p = {arr[i - k], amm[arr[i - k]]};
                         int v = mp[p];
                    } else if (k != j && arr[i - k] == arr[i - j]) {

                    }
                }
            }
            

            triples++;
        }
   }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

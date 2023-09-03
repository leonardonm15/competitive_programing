#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(31);
        for (int i=0; i < n; i++) {
            int num; cin >> num;
            int it = 0;
            // mapa de frequencias dos 0
            while (it <= 30) {
                if (!(num&1)) arr[it]++;
                num >>= 1;
                it++;
            }
        }
        int resp = 0;
        for (int i=30; i >= 0; i--){
            if (arr[i] <= k) {
                k -= arr[i];
                resp += (1 << i);
            } else {
                resp += (0 << i);
            }
        }
        cout << resp << endl;
    }
}

#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
void solve () {
    int n, k; cin >> n >> k;
    int ko = k;
    int green = 2;
    int blue = 1;
    int resp = 0;
    vector<int> arr(n);
 
    for (int i=0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
 
    int i = 0;
    for (i = 0; i < n;) {
        if (arr[i] < k) {
            k += arr[i] / 2;
            i++;
        } else if (arr[i] >= k) {
            if (blue > 0) {
                k *= 3;
                blue--;
                continue;
            } else if (green > 0) {
                k *= 2;
                green--;
                continue;
            } if (!blue && !green) {
                break;
            }
        }
    }
 
    resp = max(resp, i);
    i = 0;
    k = ko;
    green = 2;
    blue = 1;
    for (i = 0; i < n;) {
        if (arr[i] < k) {
            k += arr[i] / 2;
            i++;
        } else if (arr[i] >= k) {
            if (green > 0) {
                k *= 2;
                green--;
                continue;
            } else if (blue > 0) {
                k *= 3;
                blue--;
                continue;
            } if (!blue && !green) {
                break;
            }
        }
    }
 
    resp = max(resp, i);
    i = 0;
    k = ko;
    vector<int> ord = {2, 3, 2};
    int p = 0;
    for (i = 0; i < n;) {
        if (arr[i] < k) {
            k += arr[i] / 2;
            i++;
        } else if (arr[i] >= k) {
            if (p < 3) {
                k *= ord[p];
                p++;
            } else break;
        }
    }
    
    cout << max(resp, i) << endl;
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

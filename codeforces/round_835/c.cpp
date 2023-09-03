#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr;
    vector<int> sort_arr;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        sort_arr.push_back(num);
    }
    sort(sort_arr.begin(), sort_arr.end());
    for (int i=0; i < n; i++){
        int resp = 0;
        bool flag = false;
        for (int j=n-1; j >= 0; j--) {
            if (arr[i] == sort_arr[j] && flag == false) {
                flag = true;
                continue;
            } 
            else  {
                resp = arr[i] - sort_arr[j];
                break;
            }
        }
        cout << resp << " ";
    }
    cout << endl;
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

#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    vector<int> resp(n);
    bool flag = false;
    int l = 0;
    int k = n;
    int r = n - 1;
    int ops = 0;
    while (l < r) {
        /* cout << "-----------" << endl; */
        /* cout << "l -> " << l << endl; */
        /* cout << "r -> " << r << endl; */

        if (arr[l] == arr[r]){
            k -= 2;
            l++;
            r--;
        } else if (arr[l] < arr[r]) {
            while (l < r && arr[l] < arr[r]) {
                arr[l + 1] += arr[l];
                l++;
                ops++;
            }

            /* int sum = 0; */
            /* while (l < r && sum < arr[r]) { */
            /*     arr[l] += sum; */
            /*     ops++; */
            /*     if (arr[l] >= arr[r]) break; */
            /*     sum += arr[l]; */
            /*     l++; */
            /* } */
            /* cout << "arr -> "; */
            /* for (auto cara: arr) cout << cara << " "; */
            /* cout << endl; */
            /* sum = arr[l]; */
            /* cout << "sum -> " << sum << endl; */
            if (l >= r && arr[l] != arr[r]) break;
        } else if (arr[r] < arr[l]) {
            while (l < r && arr[r] < arr[l]) {
                arr[r - 1] += arr[r];
                ops++;
                r--;
            }
            if (l >= r && arr[r] != arr[l]) break;
        }
    }

    /* cout << k << endl; */
    cout << ops << endl;
    // k - 1 quantidade de somas pra dar merge em tudo
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

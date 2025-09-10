#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> pref(n, -1);
    vector<int> suf(n, -1);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> stack;

    for (int i = 0; i < n; i++) {
        while (stack.size() && arr[stack.back()] > arr[i]) {
            pref[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    stack.clear();

    for (int i = n - 1; i >= 0; i--) {
        while (stack.size() && arr[stack.back()] > arr[i]) {
            suf[stack.back()] = i;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    vector<int> resp(n + 1);
    for (int i = 0; i < n; i++) {
        if (pref[i] == -1 && suf[i] == -1) continue;

        int k = (pref[i] - suf[i]) - 1;
        if (pref[i] == -1) { // sufixo até ele
            k = (n - 1) - suf[i];
        }
        
        if (suf[i] == -1) { // dele até meu prefixo
            k = pref[i];
        }

        /* cout << "arr[" << i << "] -> " << arr[i] << " - " << k << endl; */
        resp[k] = max(resp[k], arr[i]);
    }

    sort(arr.begin(), arr.end());

    resp[n] = arr[0];
    resp[1] = arr[n - 1];

    for (int i = n - 1; i >= 1; i--) {
        resp[i] = max(resp[i], resp[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << resp[i] << " ";
    }
    cout << endl;
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

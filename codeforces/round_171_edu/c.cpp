#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    queue<int> stack;

    int resp = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            stack.push(i + 1);
        } else if (stack.empty() && s[i] == '0') {
            resp += i + 1;
        } else if (stack.size() && s[i] == '0') {
            stack.pop();
            resp += i + 1;
        }
    }

    vector<int> vec;

    while (stack.size()) {
        vec.push_back(stack.front());
        stack.pop();
    }

    sort(vec.begin(), vec.end());
    for (int i = 0; i < (int) (vec.size() + 1) / 2; i++) {
        /* cout << "vec[i] -> " << vec[i] << endl; */
        resp += vec[i];
    }

    cout << resp << endl;
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

#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool increasing(string& s) {
        int n = s.size();

        if (n == 0) return true;

        for (int i = 1; i < n; i++) {
                if ((int)(s[i - 1] - 'a') > (int)(s[i] - 'a')) return false;
        }

        return true;
}

bool palindrome(string& s) {
        int n = s.size();
        if (n == 0) return true;

        int l = 0;
        int r = n - 1;

        while (l <= r) {
                if (s[l] == s[r]) {
                        l++;
                        r--;
                } else return false;
        }

        return true;
}

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < (1 << n); i++) {
            string sobrou;
            string p;
            for (int j = n - 1; j >= 0; j--){
                if (i & (1 << j)) {
                    p.push_back(s[j]);
                } else {
                    sobrou.push_back(s[j]);
                }
            }

            reverse(p.begin(), p.end());

            if (palindrome(sobrou) && increasing(p)) {

                    cout << p.size() << endl;

                    int counter = n;
                    vector<int> resp;
                    for (int k = n - 1; k >= 0; k--) {
                            if (i & (1 << k)) {
                                    resp.push_back(counter);
                            }
                            counter--;
                    }

                    reverse(resp.begin(), resp.end());
                    for (auto v: resp) cout << v << " ";
                    cout << endl;

                    return;
            }
    }


    cout << -1 << endl;
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

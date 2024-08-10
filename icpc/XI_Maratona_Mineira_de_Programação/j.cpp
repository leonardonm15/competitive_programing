#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, d; cin >> n >> d;

    vector<int> p(n);

    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    int time = 0;
    int resp = 0;
    while (time < 500) {

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (time > p[i] && abs(time - p[i]) == d) {
                resp++;
                p[i] = 1e15;
                flag = true;
                break;
            }
        }

        if (!flag) {
            for (int i = 0; i < n; i++) {
                if (abs(p[i] - time) == d) {
                    p[i] = 1e15;
                    resp++;
                    break;
                }
            }
        }

        time++;
    }

    cout << resp << endl;
}

signed main() {
    solve();
    return 0;
}

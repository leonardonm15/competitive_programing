#include <bits/stdc++.h>

using namespace std;
// #define int long long

signed main() {
    int n; cin >> n;
    int d;
    int resp = 0;
    for (int i=1; i <= n; i++) {
        int aci = i;
        cin >> d;
        string o = to_string(i);
        bool flag2 = true;
        for (int u=0; u < o.size(); u++) {
            if (o[u] != o[0]) flag2 = false;
        }
        if (flag2) aci = o[0] - '0';
        for (int j=1; j <= d; j++) {
            string m = to_string(j);
            char ok = m[0];
            bool flag = true;
            for (int k=0; k < m.size(); k++) {
                if (m[k] != ok || m[k] - '0' != aci) {
                    flag = false;
                }
            }
            if (flag){
                resp++;
                /* cout << "j -> " << j << endl; */
            }
        }

    }
    cout << resp << endl;
}


#include <bits/stdc++.h>

#define endl '\n'
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    vector<int> resp;

    int k = 0;
    for (int i=0; i < n; i++) {
        int c = arr[i];
        bool coloca_no_array = false;
        // se esse numero tem o mesmo bit ligado do k entao corta
        for (int j = 32; j >= 0; j--) {
            if (k&(1 << j) && c&(1 << j)) {
                coloca_no_array = true;
            }
        }

        if (coloca_no_array) {
            resp.push_back(k);
            k = c;
        } else {
            k |= c;
        }
    }

    resp.push_back(k);

    int respostaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa = 0;
    for (auto c: resp) {
        respostaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa += c;
    }
    cout << respostaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa << " " << resp.size() << endl;
}

signed main() {
    solve();
    return 0;
}

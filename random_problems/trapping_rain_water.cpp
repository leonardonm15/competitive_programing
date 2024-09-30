#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define tii tuple<int, int, int>

void solve () {
    int n; cin >> n;
    vector<int> height(n);
    vector<int> pref;

    for (int i = 0; i < n; i++) cin >> height[i];

    int soma = 0;
    pref.push_back(soma);
    for (int i = 0; i < n; i++) {
        soma += height[i];
        pref.push_back(soma);
    }

    vector<tii> stack;

    int resp = 0;

    for (int i = 0; i < n; i++) {
        if (!height[i]) continue;
        if (!stack.size() || get<0>(stack.back()) > height[i]) stack.push_back({height[i],  i, 0});
        else {
            int ta = height[i];
            cout << "----------------------------" << endl;
            cout << "ta -> " << ta << endl;
            cout << "i -> " << i << endl;

            int sum = 0;
            int sub = 0;
            int proximo = 0;
            while (stack.size()) {
                auto [val, pos, adi] = stack.back();
                if (val <= ta) stack.pop_back();
                if (i > 0 && height[i - 1] == height[i]) break;
                sub += proximo;
                proximo = adi;
                sum = (((i - 1) - pos) * min(val, ta)) - (pref[i] - pref[pos + 1]);
                cout << "------------" << endl;
                cout << "pos -> " << pos << endl;
                cout << "sum -> " << sum << endl;
                if (val > ta) break;
            }


            cout << "sub -> " << sub << endl;
            resp += (sum - sub);
            cout << "resp -> " << resp << endl;

            stack.push_back({ta, i, sum});
        }
    }


    
    /* int sum = 0; */
    /* int sub = 0; */
    /* int proximo = 0; */
    /* while (stack.size()) { */
    /*     auto [val, pos, adi] = stack.back(); */
    /*     if (val <= ta) stack.pop_back(); */
    /*     sub += proximo; */
    /*     proximo = adi; */
    /*     sum = (((i - 1) - pos) * min(val, ta)) - (pref[i] - pref[pos + 1]); */
    /*     cout << "------------" << endl; */
    /*     cout << "pos -> " << pos << endl; */
    /*     cout << "sum -> " << sum << endl; */
    /*     if (val > ta) break; */
    /* } */

    cout << resp + sum << endl;
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

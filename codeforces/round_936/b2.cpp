#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long
#define ll long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

template <int MOD> struct Mint {
    using m = Mint;
    int v;
    Mint() : v(0) { }
    Mint(ll val) {
        if (val < -MOD or val >= 2 * MOD) {
            val %= MOD;
        }
        if (val >= MOD) {
            val -= MOD;
        }
        if (val < 0) {
            val += MOD;
        }
        v = (int)val;
    }
    bool operator==(const m &o) const { return v == o.v; }
    bool operator!=(const m &o) const { return v != o.v; }
    bool operator<(const m &o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res;
        for (res = 1; e > 0; e >>= 1, b *= b) {
            if (e & 1) {
                res *= b;
            }
        }
        return res;
    }
    m &operator+=(const m &o) {
        v += o.v;
        if (v >= MOD) {
            v -= MOD;
        }
        return *this;
    }
    m &operator-=(const m &o) {
        v -= o.v;
        if (v < 0) {
            v += MOD;
        }
        return *this;
    }
    m &operator*=(const m &o) { return *this = m((ll)v * o.v % MOD); }
    m &operator/=(const m &o) { return *this *= pwr(o, MOD - 2); }
    m &operator^=(ll e) {
        assert(e >= 0);
        return *this = pwr(*this, e);
    }
    friend m operator+(m a, const m &b) { return a += b; }
    friend m operator-(m a, const m &b) { return a -= b; }
    friend m operator*(m a, const m &b) { return a *= b; }
    friend m operator/(m a, const m &b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
    friend ostream &operator<<(ostream &os, const m &a) { return os << a.v; }
    friend istream &operator>>(istream &is, m &a) {
        ll x;
        is >> x, a = m(x);
        return is;
    }
};

const int MOD = 1e9 + 7; // o MOD tem que ser primo
using mint = Mint<MOD>;

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    /* vector<int> pos; */
    /* int neg = 0; */
    /* int posi = 0; */

    mint soma = 0;
    vector<mint> pref(n + 1);

    mint zero = 0;
    mint mx = 0;
    for (int i=1; i <= n; i++) {
        if (arr[i - 1] > 0 && (((mint)MOD - pref[i - 1]) < arr[i - 1])) {
            mx = arr[i - 1] + pref[i - 1];
        }
        pref[i] = max((pref[i - 1] + arr[i - 1]), zero);
        soma += arr[i - 1];
    }

    sort(pref.rbegin(), pref.rend());
    cout << "pref -> ";
    for (auto cara: pref) cout << cara << " ";
    cout << endl;
    cout << "mx -> " << mx << endl;
    /* cout << "soma -> " << soma << endl; */
    /* cout << "pref[0] -> " << pref[0] << endl; */

    soma -= mx;

    cout << "soma -> " << soma << endl;
    cout << "mx -> " << mx << endl;

    /* int resp = 0; */


    bool flag = false;
    if (soma == mx) flag = true;
    if (mx == 0) {
        cout << soma << endl;
        return;
    }

    while (k--) {
        mx += mx;
    }


    if (flag) {
        cout << mx << endl;
        return;
    }

    cout << mx + soma << endl;
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

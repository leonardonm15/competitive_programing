#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

typedef complex<double> cd;
typedef vector<cd> poly;
const double PI = acos(-1);

void fft(poly &a, bool invert = 0) {
    int n = a.size(), log_n = 0;
    while ((1 << log_n) < n) {
        log_n++;
    }

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    double angle = 2 * PI / n * (invert ? -1 : 1);
    poly root(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        root[i] = cd(cos(angle * i), sin(angle * i));
    }

    for (long long len = 2; len <= n; len <<= 1) {
        long long step = n / len;
        long long aux = len / 2;
        for (long long i = 0; i < n; i += len) {
            for (int j = 0; j < aux; ++j) {
                cd u = a[i + j], v = a[i + j + aux] * root[step * j];
                a[i + j] = u + v;
                a[i + j + aux] = u - v;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; ++i) {
            a[i] /= n;
        }
    }
}

vector<long long> convolution(vector<long long> &a, vector<long long> &b) {
    int n = 1, len = a.size() + b.size();
    while (n < len) {
        n <<= 1;
    }
    a.resize(n);
    b.resize(n);
    poly fft_a(a.begin(), a.end());
    fft(fft_a);
    poly fft_b(b.begin(), b.end());
    fft(fft_b);

    poly c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = fft_a[i] * fft_b[i];
    }
    fft(c, 1);

    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = round(c[i].real()); //  res = c[i].real();
                                     //  se for vector de
                                     //  double
    }
    // while(size(res) > 1 && res.back() == 0)
    // res.pop_back(); // apenas para quando os
    // zeros direita nao importarem
    return res;
}

const int maxn = 2e5 + 5;
vector<int> resp(maxn);
void solve () {
    int n, m, q; cin >> n >> m >> q;

    vector<int> d1(1e5 + 5);
    vector<int> d2(1e5 + 5);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        d1[num]++;
    }
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        d2[num]++;
    }

    vector<int> bomba = convolution(d1, d2);

    while (q--) {
        int k; cin >> k;
        cout << bomba[k] << endl;
    }
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

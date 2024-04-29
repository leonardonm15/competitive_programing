#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;


vector<vector<int>> pos(101, vector<int> (101, true));
vector<bool> sv;

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 5, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

void calc() {
    for (int i=0; i <= 100; i++) {
        for (int j=0; j <= i; j++) {
            if (sv[abs(i - j)] == false && gcd(i, j) == 1) {
                cout << "i -> " << i << endl;
                cout << "j -> " << j << endl;
                pos[i][j] = false;
                pos[j][i] = false;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    sv = sieve(105);
    calc();
    /* cout << (sv[1] == false && gcd(2, 1) == 1) << endl; */

    int pg = 0;
    int pp = 0;
    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (pos[a][b]) pg++;
        else pp++;
    }

    for (int i=1; i <= 5; i++) {
        for (int j=1; j <= 5; j++) {
            cout << pos[i][j] << " ";
        }
        cout << endl;
    }
    
    if (pg) cout << "Y" << endl;
    else cout << "N" << endl ;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}



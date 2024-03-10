#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


const int N = 1001 + 5;
vector<int> d(N);
vector<bool> sv(N, true);
vector<bool> is_prime(N+1, true);
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i < N) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }

}

void solve () {
    int n; cin >> n;
    vector<int> resp;
    resp.push_back(n);
    while (n > 1) {
        if (is_prime[n] && !d[1]) {
            n--;
            resp.push_back(n);
            d[1]++;
            continue;
        }
        
        bool flag = true;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0 && d[i] < 2) {
                n -= i;
                resp.push_back(n);
                d[i]++;
                flag = false;
                break;
            }
        }

        if (flag) break;
    }

    cout << "n -> " << n << endl;
    cout << resp.size() << endl;
    for (auto cara: resp) cout << cara << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    sieve();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

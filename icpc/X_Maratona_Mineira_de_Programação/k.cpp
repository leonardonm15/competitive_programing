#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long

void solve(){
    int N; cin >> N;
    vector<int> r(N), g(N), b(N);
    for(int i = 0; i < N; i++){
        int A, B, C; cin >> A >> B >> C;
        r[i] = A; g[i] = B; b[i] = C;
    }
    
    int R = -1, G = -1, B = -1, D = -1;
    for(int i = 0; i <= 255; i++){ //valores de R
        for(int j = 0; j <= 255; j++){ //valores de G
            for(int k = 0; k <= 255; k++){ //valores de B
                int d = 1e3;
                for(int m = 0; m < N; m++){
                    int atual = abs(i-r[m]) + abs(j-g[m]) + abs(k-b[m]);
                    if(atual < d) d = atual;
                }

                //cout << "d = " << d << endl;
                if(d > D){
                    //cout << "entra aq\n";
                    D = d;
                    R = i; G = j; B = k;
                }
            }
        }
    }

    cout << R << ' ' << G << ' ' << B << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

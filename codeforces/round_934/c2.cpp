#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
const int N = 2e5 + 5;
vector<int> v(N); // quantos tem
vector<int> freq(N); // se existe
void solve () {
    int n; cin >> n;
    vector<int> arr;
    for (int i=0; i <= n + 1; i++) {
        freq[i] = 0;
        v[i] = 0;
    }
    /* cout << "v[1] -> " << v[1] << endl; */
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        v[num]++;
        if (v[num] == 1) {
            arr.push_back(num);
        }
    }

    if (arr.size() > 1) sort(arr.begin(), arr.end());
    
    /* freq[arr[l]]++; */

    int c = 0;
    for (int i=0; i < (int)arr.size(); i++){
        if (v[arr[i]] <= i || v[arr[i]] == 1) {
            if (c == 0) {
                freq[arr[i]]++;
                c++;
                continue;
            }
            for (int j=0; j <= i - 1; j++) {
                freq[arr[j]]++;
            }
            break;
        } else {
            freq[arr[i]]++;
        }
    }

    for (int i=0; i <= n + 1; i++) {
        if (freq[i] == 0) {
            cout << i << endl;
            return;
        }
    }

}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}


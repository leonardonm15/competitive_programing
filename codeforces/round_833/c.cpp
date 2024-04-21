#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

bool check(pair<int, int> a, pair<int, int> b) {
    return (a.first == b.first ? a.second > b.second : a.first > b.first);
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    vector<int> pref;
    vector<pair<int, int>> spref(n);
    set<int> zero;
    int sum = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] == 0) zero.emplace(i);
        sum += arr[i];
        pref[i] = sum;
        spref[i] = {sum, i}
    }
    // sorta os caras do pair<int, int> mas os caras de indices mais a direita
    // ficam mais a direita quando sortados os valores forem iguais

    sort(spref.begin(), spref.end(), check);

    for (int i=0; i < n; i++) {
        int l = i;
        int r = n - 1;
        int tg = pref[i] - arr[i];
        // tenho que achar um pref[i] tal que pref[i] - tg  = -tg
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (spref[mid] 

        }
        // pega o meu cara atual no arr
        // diminui ele do pref atual
        // pra soma do range dar 0 
        //o prefixo tem que ser pref[j] - (pref[i] - arr[i]) == -arr[i]


    }


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

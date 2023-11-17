#include <bits/stdc++.h>

using namespace std;
#define int long long


// ### NOTES ###
// ordena os caras
// faz prefix sum de todos os caras 
// faz lower bound pra ver de quantos cara pra tras ele vai comer
// come esses caras e acmula no h
// faz lower bound dnv até o iterador jogar pra um cara maior que ele
// quamdo jogar pra um cara maior que ele poppa um dos blue ou green
// vai acc o poder dele

void solve () {
    int n, h; cin >> n >> h;
    multiset<int> arr;
    vector<int> p(n + 1);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.emplace(num);
    }
    p[0] = 0;
    int acc = 0;
    int i = 1;
    int blue = 1;
    int green = 2;
    for (auto cara: arr) {
        acc = cara / 2;
        p[i] = acc;
        i++;
    }
    // busca binaria no termo <= 
    // soma o termo dps
    // busca binaria dnv até o mid dar um cara maior que ele, ai poppa a pot
    while (mid != k) {
        
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

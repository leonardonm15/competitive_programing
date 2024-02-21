#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    char c; cin >> c;
    map<char, multiset<int>> map;

    for (int i=0; i < n * 2; i++){
        string s; cin >> s;
        map[s[0]].emplace(s[1] - '0');
    }

    vector<char> s = {'C', 'D', 'H', 'S'};
    for (int i=0; i < s.size(); i++) {
        if (s[i] == c) {
            s.erase(s.begin() + i);
            break;
        }
    }

    vector<string> p;
    int k = 0;
    for (int i=0; i < n; i++) {
        if (map[s[k]].size() == 0) k++;
        
        if (k > s.size()) {
            while (map[c].size() > 0) {
                if (map[c].size() == 1 || (*map[c].begin() == *map[c].rbegin())) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }

                string u;
                u += c + ('0' + *map[c].begin());
                p.push_back(u);
                u.clear();
                u += c + ('0' + *map[c].rbegin());
                p.push_back(u);
                map[c].erase(map[c].begin());
                map[c].erase(map[c].end()--);
            }
        }

        // pegar begin e rbegin
        if (map[s[k]].size() > 1 && (*map[s[k]].begin() != *map[s[k]].rbegin())) {
            string u;
            u += s[k] + ('0' + *map[s[k]].begin());
            p.push_back(u);
            u.clear();
            u += s[k] + ('0' + *map[s[k]].rbegin());
            p.push_back(u);
            map[s[k]].erase(map[s[k]].end()--);
            map[s[k]].erase(map[s[k]].begin());
        } else if (map[c].size() > 0) {
            // pegar o begin + um dos coringas repetidos
            // se nao tiver repetido pega o primeiro, se nao tiver retorna
            int lc = -1;
            int a = 0;
            for (auto cara: map[c]) {
                if (cara == lc) {
                    lc = cara;
                    break;
                }
                lc = cara;
                a++;
            }
            
            string u;
            u += s[k] + ('0' + *map[s[k]].begin());
            p.push_back(u);
            u.clear();

            if (lc == -1) {
                u += c + ('0' + *map[c].begin());
                map[c].erase(map[c].begin());
            } else {
                u += c + ('0' + lc);
                auto idx = map[c].begin();
                advance(idx, a);
                map[c].erase(idx);
            }

            p.push_back(u);
            map[s[k]].erase(map[s[k]].begin());

        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

    }

    cout << p[0] << " " << p[1] << endl;

    
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

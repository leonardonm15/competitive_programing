#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#ifndef ONLINE_JUDGE
#define debarr(arr, n) cerr << "arr: ["; forn(i, n) cerr << arr[i] << (i == n-1 ? "" : ", "); cerr << "]" << endl;
#else
#define debarr(x...)
#endif


// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    char c; cin >> c;
    map<char, multiset<int>> map;

    for (int i=0; i < n * 2; i++){
        string s; cin >> s;
        map[s[1]].emplace(s[0] - '0');
    }


    vector<char> s = {'C', 'D', 'H', 'S'};
    for (int i=0; i < s.size(); i++) {
        /* debug(map[s[i]]); */
        if (s[i] == c) {
            s.erase(s.begin() + i);
            break;
        }
    }


    vector<string> p;
    int k = 0;
    for (int i=0; i < n; i++) {
        /* debug(p); */
        while (k < s.size() && map[s[k]].size() == 0) k++;
        
        /* debug(k); */
        if (k >= s.size()) {
            while (map[c].size() > 0) {
                if (map[c].size() == 1 || (*map[c].begin() == *map[c].rbegin())) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
                string u;

                u.push_back(('0' + *map[c].begin()));
                u.push_back(c);
                p.push_back(u);

                u.clear();

                u.push_back(('0' + *map[c].rbegin()));
                u.push_back(c);
                p.push_back(u);

                map[c].erase(map[c].begin());
                map[c].erase(--map[c].end());
            }
            break;
        }

        // pegar begin e rbegin
        if (map[s[k]].size() > 1 && (*map[s[k]].begin() != *map[s[k]].rbegin())) {
            string u;

            u.push_back(('0' + *map[s[k]].begin()));
            u.push_back(s[k]);
            p.push_back(u);

            u.clear();

            u.push_back(('0' + *map[s[k]].rbegin()));
            u.push_back(s[k]);
            p.push_back(u);

            map[s[k]].erase(map[s[k]].begin());
            map[s[k]].erase(--map[s[k]].end());
        } else if (map[c].size() > 0) {
            // pegar o begin + um dos coringas repetidos
            // se nao tiver repetido pega o primeiro, se nao tiver retorna
            int lc = -1;
            int a = 0;
            for (auto cara: map[c]) {
                if (a == 0) {
                    a++;
                    lc = cara;
                    continue;
                }
                if (cara == lc) {
                    lc = cara;
                    break;
                }
                lc = cara;
                a++;
            }
            
            string u;
            u.push_back(('0' + *map[s[k]].begin()));
            u.push_back(s[k]);
            p.push_back(u);
            u.clear();

            if (lc == -1) {
                u.push_back(('0' + *map[c].begin()));
                u.push_back(c);
                map[c].erase(map[c].begin());
            } else {
                u.push_back(('0' + lc));
                u.push_back(c);
                map[c].erase(--map[c].end());
            }

            p.push_back(u);
            map[s[k]].erase(map[s[k]].begin());

        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }

    }

    for (int i=0; i < 2 * n; i += 2) {
        cout << p[i] << " " << p[i + 1] << endl;
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

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; // n sao os nodos e m sao as conexões
        vector<int> freq(201);
        vector<vector<int>> g(n + 1, vector<int>(0));
        for (int i=0; i < m; i++) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << endl;
        for (int i=1; i <= n; i++) {
            freq[g[i].size()]++;
        } 
        /* sort(freq.begin(), freq.end(), greater<int>()); */
        int i_maior = 0;
        int n_maior = 0;
        int n_menor = 20000000;
        int i_menor = 20000000;
        /* for (int i=0; i <=n; i++) cout << freq[i] << " "; */
        /* cout << endl; */
        for (int i=2; i <= n; i++) {
            if (freq[i] >= i_maior && freq[i] > 0) {
                i_maior = i;
                n_maior = freq[i];
            }
            if (freq[i] > 0 && freq[i] < i_menor) {
                i_menor = i;
                n_menor = freq[i];
            } 
        }
        i_maior--;
        cout  << i_menor << " " << i_maior << endl;
    }
}

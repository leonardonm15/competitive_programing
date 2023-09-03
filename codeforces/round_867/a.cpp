#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        int n, t; cin >> n >> t;
        int dur[n];
        vector<pair<int, int>> fel;
        for (int i=0; i < n; i++) {
            int num; 
            cin >> num;
            num += i;
            dur[i] = num;
        }
        for (int i=0; i < n; i++) {
            int num; cin >> num;
            pair<int, int> p = {num, i};
            fel.push_back(p);
        }
        /* for(int i=0; i < n; i++) cout << " " << dur[i]; */
        /* cout << endl; */
        /* for(int i=0; i < n; i++) cout << " " << fel[i].first; */
        /* cout << endl; */
        sort(fel.begin(), fel.end());
        int idxmf = -1;
        int mf = -1;
        for (int i=0; i < n; i++) {
            int felicidade = fel[i].first;
            int duracao = dur[fel[i].second];
            // cout << duracao  << " " << felicidade << endl;
            if (felicidade > mf && duracao <= t) {
                idxmf = fel[i].second;
                mf = felicidade;
            }
        }
        if (idxmf >= 0) idxmf++;
        cout << idxmf << endl;
    }
}

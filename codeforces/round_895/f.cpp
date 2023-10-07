#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;

void solve () {
    vector<int> adj[maxn]; priority_queue<pair<int, int>> pq;
    int n; cin >> n;
    vector<pair<int, int>> top(n + 1, pair<int, int>{0, 0});
    vector<int> freq(maxn);
    vector<int> resp;
    vector<int> vis(maxn);
    // recebe o adj
    for (int i=1;i <= n; i++) {
        int num; cin >> num;
        adj[i].push_back(num);
        freq[num]++;
    }
    for (int i=1; i < n; i++) {
        int num; cin >> num;
        pq.push({num, i});
    }

    for (int i=1; i <= n; i++) top[i] = {freq[i], i};
    
    /* cout << "freq" << endl; */
    /* for(int i=1; i <= n; i++) cout << freq[i] << " - "; */
    /* cout << endl; */

    sort(top.begin() + 1, top.end());
    
    for (int i=1; i <= n; i++) {
        if (top[i].first == 0 && vis[i] == 0) {
            // enquanto o top[num].first do meu cara for == 0 
            int num = i;
            while (!top[num].first)  {
                vis[num]++;
                resp.push_back(num);
                top[top[num].second].first--;
                num = top[top[num].second].second;
                adj[num].clear();
            }   
        }
    }
    /* cout << "visitados " << endl; */
    /* for (int i=1; i <= n; i++) cout << vis[i] << " - "; */
    /* cout << endl; */

    /* for (int i=1; i <= n; i++) { */
    /*     cout << adj[i][0] << " - "; */
    /* } */
    /* cout << endl; */

    for (int i=1; i <= n; i++) {
        // se o meu preço ja tiver sido visitado
        while (vis[pq.top().second] && !pq.empty()) pq.pop();
        /* cout << " i -> " << i << endl; */
        int num = pq.top().first;
        int idx = pq.top().second;
        resp.push_back(idx);
        vis[idx]++;
        int nidx = adj[idx][0];
        /* cout << "nidx - idx " << nidx << " - " << idx << endl; */
        /* cout << " vis nidx -> " << vis[nidx] << endl; */
        if (vis[nidx]) {
            /* cout << "dando coninue" << endl; */
            continue;
        }
        while (true) {
            vis[nidx]++;
            resp.push_back(nidx);
            nidx = adj[nidx][0];
            if (nidx == idx) break;
        }
    }
    for (int i=0; i < n; i++) cout << resp[i] << " ";
    cout << endl;
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

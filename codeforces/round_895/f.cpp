#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;

void solve () {
    int n; cin >> n;
    vector<int> adj(n + 1); 
    priority_queue< pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>> > pq;
    vector<int> freq(n + 1);
    vector<int> resp;
    vector<int> vis(n + 1);
    vis[0]++;
    // recebe o adj
    for (int i=1;i <= n; i++) {
        int num; cin >> num;
        adj[i] = num;
        freq[num]++;
    }
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        pq.push({num, i});
    }

    sort(top.begin() + 1, top.end());
    
    // poda as bordas soltas do grado direcionado
    for (int i=1; i <= n; i++) {
        // vê a freq do nodo, se for 0 visita ele bota na resposta 
        // + vai no adj dele tira um de freq e diz que o nodo agora é adj[nodo]
        // + para quando a freq do adj[nodo] > 1
        int nodo = i;
        int f = freq[nodo]; 
        while (!f && !vis[nodo])  {
            vis[nodo]++;
            resp.push_back(nodo);
            freq[adj[nodo]]--;
            f = freq[adj[nodo]]; 
            nodo = adj[nodo]; 
        }   
    }
    // pega o menor preço de nodo, ve quem ele ta olhando
    // + começa a cortar o ciclo por esse cara
    for (int i=1; i <= n + 1; i++) {
        // pula os visitados
        while (vis[pq.top().second] == 1 && !pq.empty()) pq.pop();
        if (pq.empty()) continue;
        // pega o proximo do menor
        int nodo = adj[pq.top().second];
        resp.push_back(nodo);
        vis[nodo]++;
        int p_nodo = adj[nodo];
        // vai cortando o ciclo
        while (!vis[p_nodo]) {
            vis[p_nodo]++;
            resp.push_back(p_nodo);
            p_nodo = adj[p_nodo];
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

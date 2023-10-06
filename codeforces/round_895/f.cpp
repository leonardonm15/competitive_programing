#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn = 1e5 + 5;

void solve () {
    vector<int> adj[maxn];
    priority_queue< pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>> > pq;
    int n;
    vector<pair<int, int>> top(n, pair<int, int>{0, 0});
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

    sort(top.begin() + 1, top.end());

    for (int i=1; i <= n; i++) {
        int idx = pq.top().second;
        int val = pq.top().first;
        while (vis[val]) {
            idx = pq.top().second;
            val = pq.top().first;
            pq.pop();
        }
        if (top[i].first == 0) {
            // enquanto o top[num].first do meu cara for == 0 
            int num = i;
            while (top[num].first == 0 && vis[num] == 0) {
                vis[num]++;
                resp.push_back(i);
                top[top[num].second].first--;
                num = top[top[num].second].second;
            }   
        }
    }
    for (int i=1; i < n; i++) {
        if (top[i].first != 0 && vis[i] == 0) {
        
        }
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

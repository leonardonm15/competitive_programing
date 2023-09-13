#include <bits/stdc++.h>

using namespace std;
//#define int long long
#define MAX 204

vector<vector<int>> arr(MAX);
vector<int> vis(205);
int c;

void dfs(int sala) {
    for (int tunel: arr[sala]) {
        if (!vis[tunel]) {
            vis[tunel]++;
            c++;
            dfs(tunel);
        }
    }
}

void solve() {
    int s, t, p; cin >> s >> t >> p;
    vector<int> alt(s + 1);
    for (int i=0; i < s; i++) {
        int num; cin >> num;
        alt[i + 1] = num;
    }
    for (int i=0; i < t; i++) {
        int num1, num2; cin >> num1 >> num2;
        if (alt[num1] > alt[num2]) {
            arr[num1].push_back(num2);
        } else if (alt[num1] < alt[num2]) {
            arr[num2].push_back(num1);
        }
    }
    dfs(p);
    cout << c << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

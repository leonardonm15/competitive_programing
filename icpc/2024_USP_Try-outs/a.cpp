#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define ti tuple<int, int, int>

void solve () {
    int n; cin >> n;
    vector<int> time(3e7 + 100);
    vector<tuple<int, int, int, int>> arr;
    queue<ti> queue;

    for (int i = 0; i < n; i++) {
        int t, d, o; cin >> t >> d >> o;
        arr.push_back({t, d, o, i + 1});
    }

    sort(arr.begin(), arr.end());

    int k = 1e7;
    for (int i = 1; i <= n; i++) {
        auto [t, d, o, idx] = arr[i - 1];
        time[t] = i + (o ? k : 0);
    }

    vector<int> resp;

    /* cout << "time -> "; */
    /* for (int i = 1; i <= 10; i++) cout << time[i] << " "; */
    /* cout << endl; */

    int ef = -1;
    int evento_atual = 0;
    for (int t = 1; t <= 3 * k; t++) {
        if (t == ef + 1) {
            ef = -1;
            evento_atual = 0;
        }

        if (time[t] < k && time[t] > 0) {
            auto[_, d, o, idx] = arr[time[t] - 1];
            queue.push({_, d, idx});
        }

        if (!evento_atual && queue.size()) {
            auto [_, d, idx] = queue.front();
            queue.pop();
            evento_atual = idx;
            ef = t + d - 1;
        }

        if (time[t] > k) {
            auto[_, d, o, idx] = arr[time[t] - k - 1];
            if (evento_atual) resp.push_back(evento_atual);
            ef = t + d - 1;
            evento_atual = idx;
        }

    }

    cout << resp.size() << endl;
    for (auto c: resp) cout << c << " ";
    cout << endl;

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

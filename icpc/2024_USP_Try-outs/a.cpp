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

    for (int i = 1; i <= n; i++) {
        auto [t, d, o, idx] = arr[i - 1];
        if (o) {
            time[t] = i;
        } else {
            queue.push({t, d, idx});
        }
    }

    vector<int> resp;

    /* cout << "tl -> "; */
    /* for (int i = 1; i <= 12; i++) cout << time[i] << " "; */
    /* cout << endl; */


    int t = 1;
    while (t <= (int)3e7 + 5) {
        if (time[t] == 0 && !queue.empty()) {
            auto [_, d, idx] = queue.front();
            queue.pop();
            int tf = t + d - 1;
            /* cout << "--------------------" << endl; */
            /* cout << "d -> " << d << endl; */
            /* cout << "t -> " << _ << endl; */
            /* cout << "tf -> "<< tf << endl; */
            while (t <= tf) {
                /* cout << "t -> " << t << endl; */
                if (time[t]) {
                    resp.push_back(idx);
                    break;
                }
                t++;
            }
        } else if (time[t]) {
            int inicio = t;
            auto [_, d, o, idx] = arr[time[t] - 1];
            int tf = t + d - 1;
            while (t <= tf) {
                /* cout << "--------------------" << endl; */
                /* cout << "d -> " << d << endl; */
                /* cout << "o -> " << o << endl; */
                /* cout << "t -> " << t << endl; */
                /* cout << "tf -> "<< tf << endl; */
                /* cout << "inicio -> " << inicio << endl; */
                if (time[t] && t != inicio) {
                    resp.push_back(idx);
                    break;
                }
                t++;
            }
        } else t++;

    }

    cout << resp.size() << endl;
    for (auto c: resp) cout << c << " ";
    cout << endl;

}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, u; cin >> n >> k >> u;
    map<int, vector<int>> freq;
    vector<int> win;
    for (int i=1; i < n + 1; i++) {
        vector<int> arr(u + 5, 0);
        arr[u + 1] = k;
        freq[i] = arr;
        for (int j=0; j < k; j++) {
            int num; cin >> num;
            freq[i][num]++;
        }
    }
    bool flag = false;
    for (int i=0; i < u; i++) {
        int num; cin >> num;
        for (auto& pair: freq) {
            if (pair.second[num] > 0) {
                pair.second[num] = 0;
                pair.second[u + 1] -= 1;
                if (pair.second[u + 1] == 0) {
                    win.push_back(pair.first);
                    flag = true;
                }
            }
        }
        if (flag) break;
    }
    sort(win.begin(), win.end());
    for (auto winer: win) cout << winer << " ";
    cout << endl;
}

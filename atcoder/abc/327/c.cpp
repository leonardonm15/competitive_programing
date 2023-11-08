#;include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    vector<int> arr[9];
    for (int i=0; i < 9; i++) {
        for (int j=0; j < 9; j++) {
            int num; cin >> num;
            arr[i].push_back(num);
        }
    }

    vector<int> vis(8, 0);
    for (int i=0; i < 9; i++) {
        vis.assign(8, 0);
        for (int j=0; j < 9; j++) {
            vis[arr[i][j] - 1]++;
        }
        /* cout << "visitados -> "; */
        for (auto cara: vis) {
            /* cout << cara << " "; */
            if (cara > 1 || cara == 0) {
                cout << "No" << endl;
                return;
            }
        }
    }

    vis.assign(8, 0);
    for (int i=0; i < 9; i++) {
        for (int j=0; j < 9; j++) {
            vis[arr[j][i] - 1]++;
        }
        for (auto cara: vis) {
            if (cara > 1 || cara == 0) {
                cout << "No" << endl;
                return;
            }
        }
        vis.assign(8, 0);
    }

    vis.assign(8, 0);
    for (int l = 0; l < 7; l += 3) {
        for (int k=0; k < 7; k += 3) {
            for (int i=l; i < l + 3; i++) {
                for (int j=k; j < k + 3; j++) {
                    // cout << i << " " << j << endl;
                    vis[arr[i][j] - 1]++;
                }
            }
            for (auto cara: vis) {
                if (cara > 1 || cara == 0) {
                    cout << "No" << endl;
                    return;
                }
            }
            vis.assign(8, 0);
        }
    }
    cout << "Yes" << endl;

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

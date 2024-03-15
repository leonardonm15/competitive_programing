#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> vec(n);
    vector<int> resp;
    for (int i=0; i < n; i++) cin >> vec[i];

    for (int i=n - 2; i >= 0; i--){
        vector<int> nums;
        if (vec[i] > vec[i + 1]) {
            int k = vec[i];
            while (k) {
                nums.push_back(k%10);
                k /= 10;
            }

            reverse(nums.begin(), nums.end());
            if (nums.size() > 1) {
                for (int j=1; j < (int)nums.size(); j++) {
                    if (nums[j] < nums[j - 1] || nums[j] > vec[i + 1] || nums[j - 1] > vec[i + 1]) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            } else {
                if (nums[0] > vec[i + 1]) {
                    cout << "NO" << endl;
                    return;
                }
            }

            vec[i] = nums[0];
        }
    }

    /* resp.push_back(vec[n - 1]); */
    /* cout << "resp -> "; */
    /* for (auto cara: resp) cout << cara << " "; */
    /* cout << endl; */
    /* for (int i=1; i < (int)resp.size() - 1; i++) { */
    /*     if (resp[i] > resp[i + 1]) { */
    /*         cout << "NO" << endl; */
    /*         return; */
    /*     } */
    /* } */
    cout << "YES" << endl;
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

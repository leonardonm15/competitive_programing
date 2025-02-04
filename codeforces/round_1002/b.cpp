#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

/* const int INF = 1e18; */

bool bb(int l, int r, vector<int>& arr) {
    int L = 0;
    int R = arr.size() - 1;
    bool resp = false;

    /* cout << "arr -> "; */
    /* for (auto v: arr) cout << v << " "; */
    /* cout << endl; */
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (arr[mid] < l) {
            L = mid + 1;
        } else if (arr[mid] > r) {
            R = mid - 1;
        } else {
            resp = true;
            break;
        }
    }

    return resp;
}

void solve () {
    // fixa o priemiro cara
    // acha o range em que eu quero achar um cara diferente de 1
    // prefixo de minimo e prefixo de maximo
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<vector<int>> where(n + 3);
    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        numbers.push_back(arr[i]);
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    for (int i = 0; i < n; i++) {
        where[min(arr[i], n + 1)].push_back(i);
    }

    int l = 0;
    int resp = 1;
    for (int i = 1; i <= k; i++) {
        if (i&1) {
            if (i != 1) {
                if (arr[i - 1] != resp && n - k > 0) {
                    cout << resp << endl;
                    return;
                }
            }
            l++;
            continue;
        } 

        int r = n - 1 - (k - i);
        bool find = false;
        for (int j = l; j <= r; j++) {
            if (arr[j] != resp) {
                find = true;
                break;
            }
        }
        /* bool find = bb(l, r, where[min(number, n + 1)]); */
        if (find) {
            cout << resp << endl;
            return;
        }
        resp++;
        l++;

    }

    cout << resp << endl;
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

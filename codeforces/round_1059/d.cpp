#include <bits/stdc++.h>

using namespace std;

#define int long long

int counter;

vector<int> a = {2, 1, 3, 4};
vector<int> b = {2, 2, 4, 5};

int q(int l, int r, vector<int>& arr) {
        int soma = 0;
        for (int i = l - 1; i <= r - 1; i++) {
                soma += arr[i];
        }
        return soma;
}

int q1(int l, int r) {
    counter++;
    cout << 1 << " " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

int q2(int l, int r) {
    counter++;
    cout << 2 << " " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

int findl(int n) {
        int l = 1;
        int r = n;
        int ans = -1;

        while (l <= r) {
                int mid = (l + r) >> 1;
                int a = q1(1, mid);
                int b = q2(1, mid);
                int diff = b - a;

                if (diff > 1) {
                        r = mid - 1;
                } else if (diff == 0) {
                        l = mid + 1;
                } else {
                        return ans = mid;
                }
        }

        return ans;
}

int findr(int n) {
        int l = 1;
        int r = n;
        int ans = -1;

        while (l <= r) {
                int mid = (l + r) >> 1;
                int a = q1(mid, n);
                int b = q2(mid, n);
                int diff = b - a;

                if (diff > 1) {
                        l = mid + 1;
                } else if (diff == 0) {
                        r = mid - 1;
                } else {
                        return ans = mid;
                }
        }

        return ans;
}

void solve () {
    int n; cin >> n;
    int l = findl(n);
    int r = findr(n);
    cout << "! " << l << " " << r << endl;
}

signed main() {
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

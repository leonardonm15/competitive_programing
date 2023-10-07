#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long soma=0;
        cin >> n;
        vector<long long> arr(n);
        for (int i=0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        soma += arr[0];
        bool flag_no = false;
        for (int i=1; i < n; i++) {
           if (arr[i] > soma) flag_no = true;
           soma+= arr[i];
        }
        if (arr[0] != 1) flag_no = true;
        if (n == 1 && soma > 1) flag_no = true;
        if (flag_no) cout << "NO" << endl;
        else cout << "YES" << endl;
        }
}

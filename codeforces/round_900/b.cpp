#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
void solve () {
    int n; cin >> n;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    if (n <= 3) {
        for (int i=0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " ";
    while (arr.size() < n) {
        int k = arr.size();
        int soma = arr[k - 1] + arr[k - 2];
        int j = arr[k - 1] + 1;
        while (((j * 3) % soma) == 0) j++;
        cout << j << " ";
        arr.push_back(j);

    }
    cout << endl;
    
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

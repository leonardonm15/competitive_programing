#include <bits/stdc++.h>

using namespace std;
int maxi = 2e8 + 1;
int main() {
    int t; cin >> t;
    while (t--) {
        map<string, long long> map;
        map["01"] = maxi;
        map["10"] = maxi;
        map["11"] = maxi;
        int n; cin >> n;
        for (int i=0; i < n; i++) {
            int num; cin >> num;
            string skill; cin >> skill;
            if (map[skill] > num) map[skill] = num;
        }
        long long resp = min(map["11"], map["10"] + map["01"]);
        if (resp == 2e8 + 1) resp = -1;
        cout <<  resp << endl;
    }
}

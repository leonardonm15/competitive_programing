#include <bits/stdc++.h>
 
using namespace std;
map<string, long long> counter;
 
int main(){
    int t; cin >> t;
    for(int k=0; k < t; k++) {
        counter.clear();
        long long c = 0;
        int n = 0;
        cin >> n;
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            counter[s]++;
        }
        vector<string> keys;
        vector<long long> val;
        for(auto[x, y]:counter) {
            keys.push_back(x);
            val.push_back(y);
        }
        for (int i=0; i < keys.size(); i++) {
            for (int j=i; j < val.size(); j++) {
                string alt = "";
                alt += keys[j][1];
                alt += keys[j][0];
                if (keys[i] == keys[j] || keys[i] == alt) {
                    continue;
                } 
                
                if (keys[i][1] == keys[j][1] || keys[i][0] == keys[j][0]) {
                    c += val[i] * val[j];
                }
            }
        }
        cout << c << endl;
    }
}

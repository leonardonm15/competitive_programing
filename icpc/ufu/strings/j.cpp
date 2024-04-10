#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 2e5 + 2;
const int INF = 1.05e9;
const int INFM = -1.05e9;
const long long INFLL = 4.5e18;
const long long MAXLL = 2.5e9;
typedef long long ll;
typedef pair<int,int> pi;
vector<int> adj[MAX];
int res[MAX];

void solve(){
    int flg = 1;
    string s; getline(cin,s);
    string t; getline(cin,t);
    if(s.size() != t.size()) flg = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] != t[i]){
            flg = 0;
            break;
        }
    }
    cout << flg << endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   // int testcase; cin >> testcase;
   // while (testcase--){
    solve();
  // }
    return 0;
}

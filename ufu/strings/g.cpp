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
    vector<string> s;
    int n; cin >> n;
    for (int i=0; i<n; i++){
        string temp; cin >> temp;
        s.push_back(temp);
    }
    for(int i=0; i<n; i++){
        cout << s[i] << ' ';
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   // int testcase; cin >> testcase;
   // while (testcase--){
    solve();
  // }
    return 0;
}

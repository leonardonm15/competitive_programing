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
    string s; getline(cin,s);
    int esp = 0;
    int car = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == ' ') {
            if(s[i-1] != ' ' && i != 0){
                esp++;
            }
        }
        else car++;
    }
    if(car == 0) {
        cout << 0 << endl;
        cout << 0 << endl;
        return;
    }
    if(s[n-1] == ' ') esp--;
    cout << esp + 1 << endl;
    cout << car << endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   // int testcase; cin >> testcase;
   // while (testcase--){
    solve();
  // }
    return 0;
}

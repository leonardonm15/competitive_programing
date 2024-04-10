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
int freq[MAX];

void solve(){
    unsigned long n; cin >> n;
    unsigned long maior = 0, num = 0;
    for(int i = 0; i < n; i++){
        unsigned long x; cin >> x;
        freq[x]++;
        if(freq[x] > maior){
            maior = freq[x];
            num = x;
        }else if(freq[x] == maior){
            if(x > num) num = x;
        }
    }
    cout << num << ' ' << maior << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   // int testcase; cin >> testcase;
   // while (testcase--){
    solve();
  // }
    return 0;
}

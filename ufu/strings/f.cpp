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
    string s;
    getline(cin, s);
    int n = s.size();
    string res;
    string temp;
    int flgup=0;
    int flglow=0;
    int flgnum=0;

    for(int i = 0; i < n; i++){
        if(isdigit(s[i])){
            flgnum = 1;
        }
        if(isupper(s[i])){
            flgup = 1;
        }
        if(islower(s[i])){
            flglow = 1;
        }
    }

    if (n < 8)
        cout << "minimo de 8 caracteres" << endl;
    if (flgup == 0)
        cout << "letra maiuscula" << endl;
    if (flglow == 0)
        cout << "letra minuscula" << endl;
    if (flgnum == 0)
        cout << "numero" << endl;
    if (flgup && flglow && flgnum)
        cout << "senha valida" << endl;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   // int testcase; cin >> testcase;
   // while (testcase--){
    solve();
  // }
    return 0;
}

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
    int flg=0;

    for(int i = 0; i < n; i++){
        if(s[i] == ' '){
            if(temp == "da" || temp == "de" || temp == "do" || temp == "dos" || temp == "e"){
                temp = "";
            }else{
                if(flg == 0){
                    res += temp + " ";
                    temp = "";
                    flg = 1;
                }else{
                    // cout << temp << endl;
                    // cout << temp[0] << endl;
                    res += temp[0];
                    res += ". ";
                    temp = "";
                }
                        }
        }else{
            temp += s[i];
        }

    }
    cout << res << temp << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   // int testcase; cin >> testcase;
   // while (testcase--){
    solve();
  // }
    return 0;
}

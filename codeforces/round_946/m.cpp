#include <its/stdc++.h>
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string res;
        int contr = 0;
        int conth = 0;
        int nsrover=0, werover=0, nsheli=0, weheli=0;
        for(int i = 0; i < n; i++){
            char dir; cin >> dir;
            if(dir == 'N'){
                if(nsrover > nsheli){
                    nsheli++;
                    res += 'H';
                    conth++;
                }else if(nsheli > nsrover){
                    nsrover++;
                    res += 'R';
                    contr++;
                }else if(nsheli == nsrover && contr== 0){
                    nsrover++;
                    res+= 'R';
                    contr++;
                }else{
                    nsheli++;
                    res+= 'H';
                    conth++;
                }
            }else if(dir == 'S'){
                if(nsrover < nsheli){
                    nsheli--;
                    res += 'H';
                    conth++;
                }else if(nsrover > nsheli){
                    nsrover--;
                    res += 'R';
                    contr++;
                }else if(nsrover == nsheli && contr == 0){
                    nsrover--;
                    res += 'R';
                    contr++;
                }else{
                    nsheli--;
                    res += 'H';
                    conth++;
                }
            }else if(dir == 'E'){
                if(werover > weheli){
                    weheli++;
                    res += 'H';
                    conth++;
                }else if(werover < weheli){
                    werover++;
                    res += 'R';
                    contr++;
                }else if(werover == weheli && contr == 0){
                    werover++;
                    res += 'R';
                    contr++;
                }else{
                    weheli++;
                    res += 'H';
                    conth++;
                }
            }else{
                if(werover < weheli){
                    weheli--;
                    res += 'H';
                    conth++;
                }else if (werover > weheli){
                    werover--;
                    res += 'R';
                    contr++;
                }else if(werover == weheli && contr == 0){
                    werover--;
                    res += 'R';
                    contr++;
                }else{
                    weheli--;
                    res += 'H';
                    conth++;
                }
            }
        }
        if(werover == weheli && nsrover == nsheli && contr > 0 && conth > 0){
            cout << res << endl;
        }else{
            cout << "NO" << endl;
        }
    }
 
}b

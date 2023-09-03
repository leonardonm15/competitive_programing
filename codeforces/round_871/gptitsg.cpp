#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll calculateSum(ll n) {
    ll sum = 0;
    ll currentRow = 1;
    ll cansInCurrentRow = 1;
    ll cansToSkip = 0;
    
    while (currentRow <= n) {
        ll cansInNextRow = cansInCurrentRow + 1;
        ll cansInFallingRow = cansInCurrentRow - cansToSkip;
        ll cansFalling = min(cansInFallingRow, n - cansToSkip);
        
        ll firstFallingCan = (currentRow - 1) * (currentRow - 1) + cansToSkip + 1;
        ll lastFallingCan = firstFallingCan + cansFalling - 1;
        
        sum += (firstFallingCan + lastFallingCan) * cansFalling / 2;
        
        currentRow++;
        cansInCurrentRow = cansInNextRow;
        cansToSkip += cansFalling;
    }
    
    return sum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        ll result = calculateSum(n);
        cout << result << endl;
    }
    
    return 0;
}


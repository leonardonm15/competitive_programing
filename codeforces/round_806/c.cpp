#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i < n; i++) {
            cin >> arr[n];
        }
        int c = 0;
        for (int i=0; i < n; i++) {
            int num_op;
            cin >> num_op;
            int soma = 0;
            for (int j=0; j < num_op; j++) {
                char op;
                cin >> op;
                if (op == 'D') soma++;
                else soma--;
            }
            arr[c] = static_cast<int>(fabs(arr[c] + soma)) % 10;
            c++;
        }
        for (int i=0; i < n; i++) cout << " " << arr[n];
        cout << endl;
    }    
}

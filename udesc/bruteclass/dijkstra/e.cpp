//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long findgroups(int arr[], int n) {
        map<int, int> map;
        for (int i=0; i < n; i++) {
            cout << i << endl;
            cout << "to aqui -> " << arr[i] << endl;
            map[arr[i] % 3]++;
        }
        cout << "map [0] -> " << map[0] << endl;
        cout << "map [1] -> " << map[1] << endl;
        cout << "map [2] -> " << map[2] << endl;
        long long dupla = 0;
        if (map[0] >= 2) dupla += (map[0] * (map[0] - 1)) / 2;
        cout << "dupla -> " << dupla << endl;
        dupla += map[1] * map[2];
        cout << "dupla -> " << dupla << endl;
        long long trio = 0;
        for (int i=0; i <= 3; i++) {
            if (map[i] >= 3) {
                trio += (map[i] + (map[i] - 1) + (map[i] - 2)) / 6;
            }
        }
        cout << "trio -> " << trio << endl;
        trio += map[1] * map[2] * map[3];
        cout << "trio -> " << trio << endl;
        long long a = dupla + trio;
        cout << dupla << " " << trio << endl;
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findgroups(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

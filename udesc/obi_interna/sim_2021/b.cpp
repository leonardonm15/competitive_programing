#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (num == 0) {
            arr.pop_back();
        } else {
            arr.push_back(num);
        }
    }
    long long soma = 0;
    for (int i=0; i < arr.size(); i++) {
        soma += arr[i];
    }
    cout << soma << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int maior = -1;
    vector<vector<int>> act;
    for (int i=0; i < n; i++) {
        vector<int> nums(3);
        cin >> nums[0] >> nums[1] >> nums[2];
        act.push_back(nums);
    }
    if (act.size() < 2) {
        for (int k=0; k < 3; k++) {
            if (act[0][k] > maior) maior = act[0][k];
        }
    } else {
        for (int i=1; i < n; i++) {
            for (int j=0; j < 3; j++) {
                if (j == 0) {
                    act[i][j] += max(act[i - 1][1], act[i - 1][2]);
                } else if (j == 1) {
                    act[i][j] += max(act[i - 1][0], act[i - 1][2]);
                } else {
                    act[i][j] += max(act[i - 1][0], act[i - 1][1]);
                }
            }
            for (int k=0; k < 3; k++) {
                if (act[i][k] > maior) maior = act[i][k];
            }
        }
    }
    cout << maior << endl;
}

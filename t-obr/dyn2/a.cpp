#include<bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    vector<int> nn(n);

    for (int i = 0; i < n; ++i)
        cin >> nn[i];

    cin >> k;
    vector<int> kk(k);

    for (int i = 0; i < k; ++i)
        cin >> kk[i];
    
    vector<vector<int>> dynamic(n+1, vector<int>(k+1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (nn[i-1] == kk[j-1]) {
                dynamic[i][j] = dynamic[i-1][j-1] + 1;
            }
            else {
                dynamic[i][j] = max(dynamic[i-1][j], dynamic[i][j-1]);
            }
        }
    }

    cout << dynamic[n][k]<< "\n";

    /*for (auto el : dynamic[n][k].elements) {
        cout << el << " ";
    }*/

    vector<int> result;
    int i = n, j = k;
    while (i > 0 && j > 0) {
        if (nn[i - 1] == kk[j - 1]) {
            result.push_back(nn[i - 1]);
            i--;
            j--;
        } else if (dynamic[i - 1][j] > dynamic[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(result.begin(), result.end());

    for (auto el : result) {
        cout << el << " ";
    }

    return 0;
}
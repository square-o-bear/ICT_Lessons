#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull k, w;
    cin >> k >> w;
    vector<ull> elements(k+1);
    vector<vector<ull>> dynamic(k+1, vector<ull>(w, 0));

    for (int i = 1; i <= k; ++i) {
        cin >> elements[i];

        for (int j = 1; j < w; ++j) {
            if (j >= elements[i]) {
                dynamic[i][j] = max(dynamic[i-1][j], dynamic[i-1][j-elements[i]] + elements[i]);
            }
            else {
                dynamic[i][j] = dynamic[i-1][j];
            }
        }
    }

    cout << dynamic[k][w-1] << '\n';


    return 0;
}
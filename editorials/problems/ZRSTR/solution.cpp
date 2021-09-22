#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0); // cout << fixed << setprecision(15);

    int TT = 1;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k > 1)
        s = s + s;

    int len = 0;
    bool one = false;
    vector<int> lengths;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') len++;
        else {
            lengths.push_back(len);
            one = true;
            len = 0;
        }
    }
    lengths.push_back(len);

    if (one == false) {
        cout << n * 1ll * k << "\n";
        return 0;
    }
    cout << *max_element(lengths.begin(), lengths.end()) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test_case() {
    int n;
    cin >> n;
    ll ans = 0, temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        ans |= temp;
    }
    cout << ans << "\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin.tie(0)->sync_with_stdio(0);

    int tt;
    cin >> tt;
    while (tt--) {
        test_case();
    }

    return 0;
}

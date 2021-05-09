#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> stacks(n);
        for(int i = 0; i < n; ++i) {
            cin >> stacks[i];
        }

        sort(stacks.begin(), stacks.end());

        for (ll i : stacks) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
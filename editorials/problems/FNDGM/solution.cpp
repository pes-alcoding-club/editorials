#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void check(vector<pair<ll, ll>> ranges, ll pos, ll x) {
    ll last_not_found = 0;
    bool found = false;
    for (auto [l, r]: ranges) {
        assert(l > 0 && r <= x);
        if (l > 1 + last_not_found) {
            assert((1 + last_not_found) == pos);
            assert(found != true);
            found = true;
        }
        last_not_found = max(last_not_found, r);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // cout << fixed << setprecision(15);


    ll x;
    int q;

    cin >> x >> q;
    vector<pair<ll, ll>> ranges;

    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
    }

    sort(ranges.begin(), ranges.end());

    ll last_not_found = 0;
    for (auto [l, r]: ranges) {
        assert(l > 0 && r <= x);
        if (l > 1 + last_not_found) {
            cout << last_not_found + 1 << "\n";
            check(ranges, last_not_found + 1, x);
            return 0;
        }
        last_not_found = max(last_not_found, r);
    }
    check(ranges, x, x);
    cout << x << "\n";

    return 0;
}
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Loading complete
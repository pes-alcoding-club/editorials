#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {
    int n;
    cin >> n;

    auto updateTotal = [&](ll total, ll value) -> ll {
        // lambda function to update total
        return (total + value) % mod;
    };

    vector<pair<int, int>> pointsSet;  // Store all the points here
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pointsSet.push_back({x, y});
    }
    sort(pointsSet.begin(), pointsSet.end());  // Sort points in ascending order
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        ll total = 1;
        for (int j = 0; j < i; j++) {
            if (pointsSet[j].second > pointsSet[i].second) {
                total = updateTotal(total, dp[j]);
                // Update total if it matches the required condition
            }
        }
        dp[i] = total;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = updateTotal(ans, dp[i]);
        // Find the sum of all the values in the dp array
    }
    cout << ans << endl;
}

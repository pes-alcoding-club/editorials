#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    ll sum = 0;
    for (int i=1;i<n+1;i++) {
        cin>>a[i];
        sum += a[i];
    }
    vector<bool> dp(sum + 1, false);
    dp[0]=true;

    for (int i=0;i<n;i++) {
        for (int j=sum;j>=0;j--) {
            if (dp[j]) {
                dp[j+a[i]]=true;
            }
        }
    }
    ll ans = sum;
    for (ll i=0;i<=sum;i++) {
        if (dp[i]) {
            ans=min(ans,max(i,sum-i));
        }
    }

    cout << ans << "\n";
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(m);
    for(int i = 0; i < m; ++i) cin >> b[i];

    map<int, int> bitMap;
    for(int i = 0; i < m; ++i) bitMap[b[i]] = i;

    map<int, int> occur;
    int cur = 0;
    occur[cur] = -1;

    int sol = 0;
    for(int i = 0; i < n; ++i) {
        if(bitMap.find(a[i]) != bitMap.end())
            cur = cur ^ (1 << bitMap[a[i]]);            
        if(occur.find(cur) == occur.end())
            occur[cur] = i;

        sol = max(sol, i - occur[cur]);
    }

    cout << sol << "\n";


    return 0;
} 
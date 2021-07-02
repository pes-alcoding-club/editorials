#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // cout << fixed << setprecision(15);

  int tt;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    map<int, int> b;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      b[temp]++;
      ok = (b[temp] > 1 ? false : true) & ok;
    }
    cout << (ok == true ? "Yes\n" : "No\n");
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // cout << fixed << setprecision(15);

  int n;
  cin >> n;
  map<int, int> match;
  map<pair<int, int>, int> matchPairs;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    if (h < w) {
      swap(w, h);
    }
    if (w == h) {
      ans += match[w];
      match[w]++;
    } else {
      ans += match[w] + match[h] - matchPairs[{w, h}];
      match[w]++;
      match[h]++;
      matchPairs[{w, h}]++;
    }
  }

  cout << ans << "\n";
  return 0;
}

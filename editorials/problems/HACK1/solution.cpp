#include <bits/stdc++.h>

using namespace std;

void solve() {
  int N, a;
  cin >> N;
  long int sum = 0l, xr = 0l;
  for (; N; --N) {
    cin >> a;
    sum += a;
    xr ^= a;
  }
  if (2*xr==sum) cout << "-1\n"; // array already satisfies condition
  else if (xr==0) cout << sum << "\n";
  else cout << xr << " " << (sum+xr) << "\n";
  return;
}

// driver
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int T;
  cin >> T;
  for (; T; --T) {
    solve();
  }
  return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const long long MOD = 1e9 + 7;
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int Q;
  cin >> Q;
  while (Q--) {
    ll T;
    cin >> T;
    ll prevD = 1, prevABC = 0;
    for (int i = 0; i < T; i++) {
      ll temp = ((3 % MOD) * (prevABC)) % MOD;
      prevABC = ((prevD % MOD) + (((2 % MOD) * (prevABC % MOD)) % MOD)) % MOD;
      prevD = temp;
    }
    cout << prevD << endl;
  }
  return 0;
}

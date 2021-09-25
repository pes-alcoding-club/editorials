#include <bits/stdc++.h>
 using namespace std;
 using ll = long long;
 using uint = unsigned int;
 using ull = unsigned long long;

 // https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp
 struct DSU {
  public:
   DSU(int n) : _n(n + 1), parent_or_size(n + 1, -1) {}

   int merge(int a, int b) {
     assert(0 <= a && a < this->_n);
     assert(0 <= b && b < this->_n);
     int x = this->leader(a), y = this->leader(b);
     if (x == y) return x;
     if (-this->parent_or_size[x] < -this->parent_or_size[y]) swap(x, y);
     this->parent_or_size[x] += this->parent_or_size[y];
     this->parent_or_size[y] = x;
     return x;
   }

   int leader(int a) {
     assert(0 <= a && a < _n);
     if (this->parent_or_size[a] < 0) return a;
     return this->parent_or_size[a] = this->leader(parent_or_size[a]);
   }

   int size(int a) {
     assert(0 <= a && a < _n);
     return -this->parent_or_size[leader(a)];
   }

  private:
   int _n;
   vector<int> parent_or_size;
 };

 const int nax = 2e5 + 10;

 int main() {
   cin.tie(0)->sync_with_stdio(0);  // cout << fixed << setprecision(15);

   int n, q, type, a, b;
   cin >> n >> q;

   DSU dsu(nax);

   while (q--) {
     cin >> type;
     if (type == 1) {
       cin >> a >> b;
       dsu.merge(a, b);
     }
     else {
       cin >> a;
       cout << dsu.size(a) << "\n";
     }
   }

   return 0;
 }

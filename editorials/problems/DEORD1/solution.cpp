#include<bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 1;
vector<int> tree(2 * nax);

void update(int idx, int val) {
    idx += nax;

    while (idx) {
        tree[idx] += val;
        idx >>= 1;
    }
}

int query(int lhs, int rhs) {
    lhs += nax;
    rhs += nax;
    int ret = 0;

    while (lhs <= rhs) {
        if (lhs & 1) ret += tree[lhs++];
        if ((rhs & 1) == 0) ret += tree[rhs--];
        lhs >>= 1;
        rhs >>= 1;
    }

    return ret;
}

void solve(vector<int> a) {
    int n = a.size();
    vector<pair<int, int>> pairs;

    for (int i = 0; i < n; i++) {
        pairs.emplace_back(a[i], i);
    }

    sort(pairs.begin(), pairs.end());

    for (auto p : pairs) {
        cout << (p.second - query(0, p.second - 1)) + 1 << "\n";
        update(p.second, 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);

    return 0;
}

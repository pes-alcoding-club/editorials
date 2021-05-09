#include<bits/stdc++.h>
using namespace std;

void addNode(priority_queue<pair<int, int> >&  left,
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > >& right, int x, int v) {
    pair<int, int> node = { v, x };
    if(node > left.top())
        right.push(node);
    else
        left.push(node);
    if (left.size() > right.size() + 1) {
        right.push(left.top());
        left.pop();
    } else if (right.size() > left.size() + 1) {
        left.push(right.top());
        right.pop();
    }
}

int main() {
    int d, x, v;
    cin >> d;
    cin >> x >> v;

    priority_queue<pair<int, int> >  left;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > right;

    left.push({ v, x });

    for(int i = 0; i < d; ++i) {
        cin >> x >> v;
        addNode(left, right, x, v);
        cin >> x >> v;
        addNode(left, right, x, v);
        if (left.size() > right.size())
            cout << left.top().second << "\n";
        else
            cout << right.top().second << "\n";
    }

    return 0;
} 
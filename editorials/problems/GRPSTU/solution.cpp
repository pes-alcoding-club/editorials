#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int> >& graph, vector<int>& vis, int i, int c) {
    if(vis[i] == (c ^ 1)) return false;
    if(vis[i] != -1) return true;
    vis[i] = c;
    bool res = true;
    for(int x: graph[i]) res = res & dfs(graph, vis, x, c ^ 1);
    return res;
}

void checkBiPartite(vector<vector<int> >& graph, int n, bool& check, int& count) {
    vector<int> vis(n + 1, -1);    
    for(int i = 1; i <= n; ++i) {
        if(vis[i] == -1) {
            check &= dfs(graph, vis, i, 1);
            ++count;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int f;
    cin >> f;
    vector<vector<int> > graph(n + 1, vector<int>());
    for(int i = 0; i < f; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool check = true; 
    int count = 0;    

    checkBiPartite(graph, n, check, count);
    
    if(!check) cout << 0 << endl;    
    else cout << int(pow(2, count)) << endl;
    return 0;
}
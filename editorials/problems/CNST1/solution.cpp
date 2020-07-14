#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];

int isValid(int i, int j, int m, int n){
    return i >= 0 && i < m && j >= 0 && j < n;
}

void bfs(int i, int j, int m, int n){
    int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    queue<pair<int, int> > q;    
    q.push({i, j});    
    a[i][j] = 0;
    while(!q.empty()) {
        pair<int, int> node = q.front();        
        for(int k=0; k<4; ++k){
            int ii = node.first + directions[k][0];
            int jj = node.second + directions[k][1];
            if(isValid(ii, jj, m, n) && a[ii][jj])
                q.push({ii, jj}), a[ii][jj] = 0;
        }
        q.pop();
    }
}

void solve() {
    int m, n;
    cin >> m >> n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin >> a[i][j];
    int count = 0;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(a[i][j])
                bfs(i, j, m, n), ++count;
    cout<<count<<"\n";        
}


int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> occur(26, false);
    for(char x: s) {
        if(x <= 'Z') occur[x - 'A'] = true;
        else occur[x - 'a'] = true;
    }

    int count = 0;
    for(bool x: occur) if(x) ++count;

    if(count == 26) cout << "YES\n";    
    else cout << "NO\n";    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int m;
    int n;
    int a[1005][1005] = {{0}};
    for(int test=0;test<t;++test)
    {
        cin>>m>>n;        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>a[i][j];
            }
        }
        int count=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(a[i][j])
                {
                    if(a[i][j]==1){
                        if(i==0 && j==0)
                            ++count;
                        else if(i == 0 && a[i][j-1] == 0)
                            ++count;
                        else if(j==0 && a[i-1][j] == 0)
                            ++count;                            
                        else if(a[i-1][j] == 0 && a[i][j-1] == 0)
                            ++count;                        
                    }                                            
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
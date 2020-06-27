#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int parent[100005], rank[100005] , sets[100005];
int find(int i)
{
    if(parent[i]!=i)
    parent[i] = find(parent[i]);
    return parent[i];    
}
void unions(int x , int y)
{
    if(rank[x]>rank[y])
        parent[y] = x ;
    else
    {
        parent[x] = y ;
        if(rank[x]==rank[y])
        rank[y]++;
    }
}
int main() 
{
    int i , j , k , m , n ,  p , a , b , x , y;
    long long int sum = 0, sqsum = 0, ans ;
    scanf("%d%d",&n,&m);
    for(i = 0 ; i<n ; i++)
        parent[i] = i ;
    for(i = 0 ; i<m ; i++)
    {
        scanf("%d%d",&a,&b);
        x = find(a);
        y = find(b);
        if(x!=y)
            unions(x,y);
    }
    for(i = 0 ; i<n ; i++)
    {
        x = find(i);
        sets[x]++;
    }
    for(i = 0 ; i<n ; i++)
    {
       if(sets[i])
       {
           sum+=sets[i];
           sqsum+=sets[i]*sets[i];
       }
    }
    ans = (sum*sum - sqsum)/2 ;
    printf("%lld\n",ans);
    return 0;
}
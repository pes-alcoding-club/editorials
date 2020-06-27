// Problem Name: Exploring Planets
// Difficulty : Hard
// Tags : Backtracking, DFS

#include<bits/stdc++.h>
using namespace std;

void func(vector<vector<int>> d2, vector<bool> visit, int time_left, int& time_left_max, int curr, int n, int count, int& max, vector<int> temp, vector<int> &ans)
{
    if(count == n)
    {
        if(count>max)
	{
            max = count;
	    ans = temp;
       	    time_left_max = time_left;
	}
	if((count==max) && (time_left > time_left_max))
	{
	    ans = temp;
	    time_left_max = time_left;
	}
        return;
    }

    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if ((!visit[i]) && (d2[curr][i] <= time_left))
        {
            flag = 1;

            visit[i] = 1;
	    temp[count] = i;

            func(d2,visit,time_left-d2[curr][i],time_left_max,i,n,count+1,max,temp,ans);

            visit[i] = 0;
	    temp[count] = 0;
        }
    }

    if(!flag)
    {
        if(count>max)
        {
            max = count;
	    ans = temp;
    	    time_left_max = time_left;
	}
	if((count==max) && (time_left > time_left_max))
	{
	    ans = temp;
   	    time_left_max = time_left;
	}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    int n,x,max,ind,time_left_max;
    while(t--)
    {
        cin>>n>>x;

        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];

        vector<vector<int>> d2;
        vector<int> row(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>row[j];
            d2.push_back(row);
        }

        vector<bool> visit(n);
	vector<int> temp(n);
	vector<int> ans(n);

        max = 0;
        ind = 0;
        while(ind < n && arr[ind] > x)
            ind++;

        if(ind < n)
        {
            visit[ind] = 1;
            max = 1;
	    ans[0] = ind;
  	    time_left_max = x-arr[ind];
	    temp[0] = ind;
            func(d2,visit,x-arr[ind],time_left_max,ind,n,1,max,temp,ans);

            for(int i=ind+1; i<n; i++)
            {
                visit[i-1] = 0;
                visit[i] = 1;
                if(arr[i] <= x)
                {
                    temp[0] = i;
		    func(d2,visit,x-arr[i],time_left_max,i,n,1,max,temp,ans);
                }
            }
        }

        cout<<max<<"\n";
	if(max>0)
	{
	    for(int i=0; i<max; i++)
  	    	cout<<ans[i]+1<<" ";
	    cout<<"\n";
	}
    }

    return 0;
}

n=int(input())
arr=list(map(int,input().split()))
cc=sorted(arr)
ans=0
for i in range(len(arr)):
    if(arr[i]==cc[i]):
        ans+=1
print(ans)

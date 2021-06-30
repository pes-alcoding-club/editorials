n,m=map(int,input().split())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
or1=A[0]
for i in range(1,n):
    or1|=A[i]
or2=B[0]
for i in range(1,m):
    or2|=B[i]
print(or1&or2)
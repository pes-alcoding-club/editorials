n = int(input())
s = input()
s = s.lower()
a = set()
for c in s:
    if c not in a:
        a.add(c)
if len(a) == 26:
    print("YES")
else:
    print("NO") 
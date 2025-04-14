w=input().upper()
a=list(set(w))
cnt=[]
for i in a:
    cnt.append(w.count(i))
if cnt.count(max(cnt))>1:
    print("?")
else:
    print(a[cnt.index(max(cnt))])
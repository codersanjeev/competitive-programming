n,m,q=map(int,input().split())
arr=[list(map(int,input().split())) for _ in range(q)]
ans=0
for i1 in range(1,m+1):
  for i2 in range(i1,m+1):
    for i3 in range(i2,m+1):
      for i4 in range(i3,m+1):
        for i5 in range(i4,m+1):
          for i6 in range(i5,m+1):
            for i7 in range(i6,m+1):
              for i8 in range(i7,m+1):
                for i9 in range(i8,m+1):
                  for i10 in range(i9,m+1):
                    tmp=0
                    arrs=[0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10]
                    for a,b,c,d in arr:
                      if arrs[b]-arrs[a]==c:
                        tmp+=d
                    ans=max(ans,tmp)
print(ans)

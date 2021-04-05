c={0:"Thousand ",1:"Million ",2:"Billion ",3:"Trillion "}
def fun(n):
    dic={0:"",1:"One ",2:"Two ",3:"Three ",4:"Four ",5:"Five ",6:"Six ",7:"Seven ",8:"Eight ",9:"Nine ",10:"Ten ",11:"Eleven ",12:"Twelve ",13:"Thirteen ",14:"Fourteen ",15:"Fifteen ",16:"Sixteen ",17:"Seventeen ",18:"Eighteen ",19:"Nineteen ",20:"Twenty ",30:"Thirty ",40:"Forty ",50:"Fifty ",60:"Sixty ",70:"Seventy ",80:"Eighty ",90:"Ninety "}
    if n>=100:
        h=n//100
        r=n%100
        if(r<=19):
            return dic[h]+"Hundred "+dic[r]
        else:
            return dic[h]+"Hundred "+dic[r-(r%10)]+dic[r%10]
    else:
        if(n<=19):
            return dic[n]
        else:
            return dic[n-(n%10)]+dic[n%10]
        
n=int(input().strip())
for i in range(n):
    m=int(input())
    li=[]
    if(m==0):
        print("Zero")
    else:
        while(m>100):
            re=m%1000
            m=m//1000
            li.append(fun(re))
        if(m>0):
            li.append(fun(m))
        k=len(li)
        s=li[0]
        for i in range(1,k):
            if(li[i]!=""):
                s=li[i]+c[i-1]+s
        print(s)
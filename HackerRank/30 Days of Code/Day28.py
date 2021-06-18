#!/bin/python3

import sys
import re


N = int(input().strip())
p = re.compile(r'^@gmail$')
lst = []
for a0 in range(N):
    firstName,emailID = input().strip().split(' ')
    firstName,emailID = [str(firstName),str(emailID)]
    if(emailID.endswith("@gmail.com")) :
        lst.append(firstName)
lst.sort()
for i in lst :
    print(i)
    

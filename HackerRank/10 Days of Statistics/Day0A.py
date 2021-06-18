from collections import Counter
from statistics import mode
import numpy as np
from scipy import stats

n = int(input())
arr = list(map(int, input().split()))

a = np.array(arr)
data = Counter(a)
print(np.mean(a))
print(np.median(a))
m = stats.mode(a)
ans = m[0]
print(int(stats.mode(arr)[0]))

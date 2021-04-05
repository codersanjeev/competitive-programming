class Solution:
# @param A : integer
# @return an integer
	def numTrees(self, n):
		y = 1
	    x = 1
        for i in range(2, n + 1) :
	        y = y * (n + i)
            x = x * i
        return y // x

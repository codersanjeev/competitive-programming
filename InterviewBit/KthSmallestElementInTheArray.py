class Solution:
	def kthsmallest(self, A, B):
	    return sorted(A)[B-1]

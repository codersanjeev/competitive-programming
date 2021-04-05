import re

class Solution:
	def isNumber(self, A):
        num = '-?(\d*\.)?\d+'
        reg = '^\s*' + num + '(e-?\d+)?\s*$'
        if re.search(reg, A) :
            return 1
        else :
            return 0

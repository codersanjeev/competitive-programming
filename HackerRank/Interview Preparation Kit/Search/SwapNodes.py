#!/bin/python

from __future__ import print_function
from collections import deque


import os
import sys

class Node:
    def __init__(self, d):
        self.data = d
    
def build_tree(indexes):
    f = lambda x: None if x == -1 else Node(x)
    children = [list(map(f,x)) for x in indexes]
    nodes = {n.data: n for n in filter(None, sum(children, []))}
    nodes[1] = Node(1)
    for idx, child_pair in enumerate(children):
        nodes[idx+1].left = child_pair[0]
        nodes[idx+1].right = child_pair[1]
    return nodes[1]

def inorder(root):
    stack = []
    curr = root
    while stack or curr:
        if curr:
            stack.append(curr)
            curr = curr.left
        elif stack:
            curr = stack.pop()
            yield curr.data
            curr = curr.right
        
def swap_nodes(indexes, queries):
    root = build_tree(indexes)
    for k in queries:
        h = 1
        q = deque([root])
        while q:
            for _ in range(len(q)):
                node = q.popleft()
                if h % k == 0:
                    node.left, node.right = node.right, node.left
                q += filter(None, (node.left, node.right))
            h += 1
        yield inorder(root)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    indexes = []

    for _ in xrange(n):
        indexes.append(map(int, raw_input().rstrip().split()))

    queries_count = int(raw_input())

    queries = []

    for _ in xrange(queries_count):
        queries_item = int(raw_input())
        queries.append(queries_item)

    result = swap_nodes(indexes, queries)

    fptr.write('\n'.join([' '.join(map(str, x)) for x in result]))
    fptr.write('\n')

    fptr.close()

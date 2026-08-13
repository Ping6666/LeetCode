from typing import Dict, List


class Node:

    def __init__(self, t):
        self.t = t
        self.children = []
        return

    def add_children(self, v):
        self.children.append(v)
        return

    def get_time(self):
        if len(self.children) == 0:
            return self.t

        _min, _max = None, None
        for c in self.children:
            _t = c.get_time()
            if _min is None or _max is None:
                _min = _max = _t
            _min = min(_min, _t)
            _max = max(_max, _t)
        return _max + (_max - _min) + self.t


class Solution:

    def finishTime(
        self,
        n: int,
        edges: List[List[int]],
        baseTime: List[int],
    ) -> int:
        nodes_hash: Dict[int, Node] = {}

        for i in range(n):
            nodes_hash[i] = Node(baseTime[i])

        for u, v in edges:
            nodes_hash[u].add_children(nodes_hash[v])

        return nodes_hash[0].get_time()

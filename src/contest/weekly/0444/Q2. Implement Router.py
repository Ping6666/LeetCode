from typing import List, Dict
# import queue

from collections import deque


class Router:

    def __init__(self, memoryLimit: int):
        self.memoryLimit = memoryLimit

        self.q = deque()
        self.p = set()

        self.t: Dict[int, Dict[int, int]] = {}

        return

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:

        _new = (source, destination, timestamp)
        if _new in self.p:
            return False

        # if self.q.qsize() == self.memoryLimit:
        if len(self.q) == self.memoryLimit:
            # return False

            # try to remove
            self.forwardPacket()

        # self.q.put(_new)
        self.q.append(_new)
        self.p.add(_new)

        if destination not in self.t.keys():
            self.t[destination] = {}

        if timestamp not in self.t[destination].keys():
            self.t[destination][timestamp] = 0
        self.t[destination][timestamp] += 1

        return True

    def forwardPacket(self) -> List[int]:
        # if self.q.qsize() == 0:
        if len(self.q) == 0:
            return []

        # _arr = self.q.get()
        _arr = self.q.popleft()

        self.t[_arr[1]][_arr[2]] -= 1
        if self.t[_arr[1]][_arr[2]] == 0:
            self.t[_arr[1]].pop(_arr[2])
        if len(self.t[_arr[1]]) == 0:
            self.t.pop(_arr[1])

        self.p.remove(_arr)

        return list(_arr)

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        i = 0

        if destination not in self.t.keys():
            return i

        _dict = self.t[destination]

        for _v, _c in _dict.items():
            if startTime <= _v and _v <= endTime:
                i += _c

        return i

from typing import Dict

# TLE

# tgt str -> diff
lookup: Dict[str, int] = {}


def get_diff(c1: chr, c2: chr):
    return abs(int(c1) - int(c2))


def update_and_get_lookup(_str: str):
    if _str not in lookup.keys():

        m = 0
        p = s = _str[-1]

        for c in _str[:-1][::-1]:
            _s = f"{c}{p}"
            if _s not in lookup.keys():
                lookup[_s] = get_diff(c, p)

            s = f"{c}{s}"
            if s not in lookup.keys():
                lookup[s] = max(m, lookup[_s])

            m = max(m, lookup[s])
            p = c

        lookup[_str] = m

    return lookup[_str]


class Solution:

    def goodIntegers(self, l: int, r: int, k: int) -> int:
        ans = 0
        for i in range(l, r + 1):
            i_str = str(i)
            if update_and_get_lookup(i_str) <= k:
                ans += 1
        return ans

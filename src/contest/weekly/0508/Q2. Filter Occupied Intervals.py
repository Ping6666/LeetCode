from typing import List

T = List[List[int]]


class Solution:

    def filterOccupiedIntervals(
        self,
        occupiedIntervals: T,
        freeStart: int,
        freeEnd: int,
    ) -> T:
        sorted_o_int = sorted(occupiedIntervals)
        # print(sorted_o_int)

        # ---
        # merge
        # ---

        ans = []
        p_s, p_e = None, None
        for c_s, c_e in sorted_o_int:
            if p_s is None:
                p_s = c_s
                p_e = c_e

            if p_e >= c_s - 1:
                # can merge
                p_e = max(p_e, c_e)
            else:
                # can not merge
                ans.append([p_s, p_e])
                # reset
                p_s, p_e = c_s, c_e
        if p_s is not None:
            ans.append([p_s, p_e])
        # print(ans)

        # ---
        # remove free
        # ---

        i = 0
        n = len(ans)

        while 0 <= i and i < n:
            if ans[i][0] > freeEnd:
                break

            if freeStart <= ans[i][0] and ans[i][1] <= freeEnd:
                # full cover by free
                ans.pop(i)
                i -= 1
                n -= 1
            elif ans[i][0] < freeStart and freeEnd < ans[i][1]:
                # full cover by occupy
                o_e = ans[i][1]
                ans[i][1] = freeStart - 1
                ans.insert(i + 1, [freeEnd + 1, o_e])
                i += 1
                n += 1
            elif (ans[i][0] < freeStart and freeStart <= ans[i][1]
                  and ans[i][1] <= freeEnd):
                # front partial
                ans[i][1] = freeStart - 1
            elif (freeStart <= ans[i][0] and ans[i][0] <= freeEnd
                  and freeEnd < ans[i][1]):
                # end partial
                ans[i][0] = freeEnd + 1
            i += 1

        return ans

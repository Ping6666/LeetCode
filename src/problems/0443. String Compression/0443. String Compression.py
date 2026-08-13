from typing import List


class Solution:

    def compress(self, chars: List[str]) -> int:
        l = len(chars)
        if l == 1:
            return 1

        i = 1

        prev_count = 1
        prev_char = chars[0]
        while True:
            if i >= len(chars): break
            if chars[i] == prev_char:
                prev_count += 1
            else:
                if prev_count != 1:
                    for _ in range(prev_count - 1):
                        chars.pop(i - prev_count)
                    s = str(prev_count)
                    for c in reversed(s):
                        chars.insert(i - prev_count + 1, c)

                    i = i - (prev_count - 1) + len(s)

                prev_count = 1
                prev_char = chars[i]
            i += 1

        if prev_count != 1:
            for _ in range(prev_count - 1):
                chars.pop(i - prev_count)
            s = str(prev_count)
            for c in reversed(s):
                chars.insert(i - prev_count + 1, c)

        return len(chars)

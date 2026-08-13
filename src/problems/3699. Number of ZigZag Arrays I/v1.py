class Solution:

    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        lr_len = r - l + 1

        # lr_len * 2, lr_len * 2
        dp_odd, dp_even = [], []
        for i in range(lr_len):
            dp_odd.append([i, lr_len - i - 1])
            dp_even.append([0, 0])

        # print(dp_odd)
        # print(dp_even)
        # print()

        use_even = False
        for _ in range(n - 2):
            if not use_even:
                use_even = True
                for i in range(lr_len):
                    dp_even[i][0] = dp_even[i][1] = 0
                for i in range(lr_len):
                    for j in range(lr_len):
                        if i < j:
                            dp_even[j][0] += dp_odd[i][1]
                        elif i > j:
                            dp_even[j][1] += dp_odd[i][0]
                # print(dp_odd)
                # print(dp_even)
                # print()
            else:
                use_even = False
                for i in range(lr_len):
                    dp_odd[i][0] = dp_odd[i][1] = 0
                for i in range(lr_len):
                    for j in range(lr_len):
                        if i < j:
                            dp_odd[j][0] += dp_even[i][1]
                        elif i > j:
                            dp_odd[j][1] += dp_even[i][0]
                # print(dp_odd)
                # print(dp_even)
                # print()

        ans = 0
        if use_even:
            for i in range(lr_len):
                ans += dp_even[i][0] + dp_even[i][1]
        else:
            for i in range(lr_len):
                ans += dp_odd[i][0] + dp_odd[i][1]
        return ans % (10**9 + 7)

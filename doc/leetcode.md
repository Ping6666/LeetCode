# LeetCode

## Magic

```
#include <iostream>

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    void solve()
    {
        // magic 2
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
    }
};
```

using above code in the submission can reduce the runtime on the LeetCode server

## Complexity

### Runtime, Memory

Just use asymptotic complexity to measure the complexity of the code, and present in big O notation. \
This measurement can be used in both time (Runtime) and space (Memory).

### Reliability

> Runtime < Memory

Runtime will depend on the LeetCode servers' current load not just on the time complexity of the code. \
Therefore, it may get different results on runtime complexity or memory complexity while running same code.

## write-up

- [0208. Implement Trie (Prefix Tree)](../src/0208.%20Implement%20Trie%20(Prefix%20Tree)/readme.md)
- [0330. Patching Array](../src/0330.%20Patching%20Array/readme.md)
- [0502. IPO](../src/0502.%20IPO/readme.md)
- [0560. Subarray Sum Equals K](../src/0560.%20Subarray%20Sum%20Equals%20K/readme.md)
- [1248. Count Number of Nice Subarrays](../src/1248.%20Count%20Number%20of%20Nice%20Subarrays/readme.md)
- [1509. Minimum Difference Between Largest and Smallest Value in Three Moves](../src/1509.%20Minimum%20Difference%20Between%20Largest%20and%20Smallest%20Value%20in%20Three%20Moves/readme.md)
- [2121. Intervals Between Identical Elements](../src/2121.%20Intervals%20Between%20Identical%20Elements/readme.md)
- [2559. Count Vowel Strings in Ranges](../src/2559.%20Count%20Vowel%20Strings%20in%20Ranges/readme.md)

## good questions

- [2045. Second Minimum Time to Reach Destination](../src/2045.%20Second%20Minimum%20Time%20to%20Reach%20Destination/)

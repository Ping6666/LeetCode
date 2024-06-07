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

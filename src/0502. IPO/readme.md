# 502. IPO

> Topics: Array, Greedy, Sorting, Heap (Priority Queue)

## Comparison

| File Name | Runtime (ms) | Beats (%) | Memory (MB) | Beats (%) |
|:---------:|:------------:|:---------:|:-----------:|:---------:|
|   src-1   |     403      |   5.02    |   123.86    |   5.31    |
|   src-2   |     104      |   97.97   |    81.17    |   92.55   |

## Details

### `src-1.cpp`

> Without `priority_queue`

Uses the map's BST (binary search tree) to keep key-value pairs sorted. It tracks the capital, profits, and indices using `map<int, map<int, vector<int>>> cap_to_pro_to_indices_table` and the current addable projects with their profits and indices using `map<int, vector<int>> pro_to_indices_table`.

While processing the `cap_to_pro_to_indices_table` map, if the current capital (w) is larger than the stored capital (key), it dumps its value into the `pro_to_indices_table`. Then, it takes the front object in `pro_to_indices_table` as the project with the highest profit under the current capital.

### `src-2.cpp`

> With `priority_queue`

Uses `priority_queue<int> p_pqueue` to keep track of all currently assignable projects' profits and `priority_queue<CapitalProfits> cp_pqueue` to track capital pairs with their profits, prioritizing by capital.

While processing the `cp_pqueue`, if a project's capital is less than the current capital, it is added to the `p_pqueue`. Then, the highest profit from the `p_pqueue` is added to the current capital. This process continues until the maximum number of projects that can be completed is reached.

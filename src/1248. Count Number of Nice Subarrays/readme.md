# 1248. Count Number of Nice Subarrays

> Topics: Array, Hash Table, Math, Sliding Window

## Comparison

| File Name | Runtime (ms) | Beats (%) | Memory (MB) | Beats (%) |
|:---------:|:------------:|:---------:|:-----------:|:---------:|
|   src-1   |     435      |   5.00    |    71.93    |   29.86   |
|   src-2   |      48      |   99.36   |    69.89    |   91.54   |

## Details

### `src-1.cpp`

Uses a `vector` to store all possible odd counts. While looping through `nums`, it stores the current number. If the current number is odd, it shifts all values in the `vector` to their next positions and resets the value for odd count 0 to 0, then increments the count for odd count 1. If the current number is even, it keeps the vector the same but increments the count for odd count 1.

This method is extremely slow due to the `vector.insert` operation.

### `src-2.cpp`

Tracks the last `k` and `k-1` odd indices. When the current count of odd numbers exceeds `k`, it adds the difference between the last `k` and `k-1` odd indices. This difference represents the combination count. After looping through all values in `nums`, it sums up the combination counts.

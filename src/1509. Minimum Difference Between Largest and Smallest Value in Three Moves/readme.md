# 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

> Topics: Array, Greedy, Sorting

## Comparison

| File Name | Runtime (ms) | Beats (%) | Memory (MB) | Beats (%) |
|:---------:|:------------:|:---------:|:-----------:|:---------:|
|   src-1   |      61      |   86.29   |    38.64    |   80.72   |
|   src-2   |      49      |   97.28   |    37.55    |   99.09   |

## Details

The core algorithm in both `src-1` and `src-2` is the same: find the difference between the largest and smallest values in three moves. This involves checking the largest and smallest four elements, determining the three intervals, and using a sliding window to identify the highest value within the window. This highest value represents the difference that can be removed, and the final result is the maximum difference in the original `nums` minus this removable difference.

### `src-1.cpp`

Sort the entire vector `nums` with a time complexity of O(n * log(n)).

```
sort(nums.begin(), nums.end());
```

### `src-2.cpp`

Sort only the partial vector `nums` (the front 4 elements and the back 4 elements) with a time complexity of O(n). The `nth_element` function ensures that the `front 4 elements <= rest of the elements <= back 4 elements`.

```
nth_element(nums.begin(), nums.begin() + 4, nums.end());
nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
sort(nums.begin(), nums.begin() + 4);
sort(nums.end() - 4, nums.end());
```

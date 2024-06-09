# 560. Subarray Sum Equals K

> Topics: Array, Hash Table, Prefix Sum

## Comparison

| File Name | Runtime (ms) | Beats (%) | Memory (MB) | Beats (%) |
|:---------:|:------------:|:---------:|:-----------:|:---------:|
|   src-1   |      53      |   93.92   |    44.91    |   71.59   |
|   src-2   |     1629     |   20.53   |    32.95    |   80.29   |
|   src-3   |     2225     |   17.32   |    32.74    |   96.21   |

## Details

### `src-1.cpp`

Utilizes prefix-sum with an `unordered_map`.

### `src-2.cpp`

Employs a brute-force approach, storing sums not in-place.

### `src-3.cpp`

Uses a brute-force method, storing sums in-place.

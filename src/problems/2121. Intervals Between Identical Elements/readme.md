# 2121. Intervals Between Identical Elements

> Topics: Array, Hash Table, Prefix Sum

## Details

### `src.cpp`

After constructing a map that associates each value with a list of its indices (`unordered_map<int, vector<int>> value_idx_map`), loop through this map. Since the index list is sorted by default, calculating the absolute differences becomes straightforward.

If loop through the array again and compute the absolute differences repeatedly, it will result in a Time Limit Exceed (TLE) error.

# 2559. Count Vowel Strings in Ranges

> Topics: Array, String, Prefix Sum

## Details

### `src-1.cpp`

First, process the list of words and store the results of the vowel check in a `vowel_table`. Then, create a map (`words_range_query_indices_map`) that uses word range pairs as keys and query indices as values, using a custom comparator `vecKeyComp` to sort the pairs in map as desired. Compute the prefix sum and store the sum corresponding to each index in the `vowel_table`. Finally, populate the results list (`ans`) with the sum values according to the query indices.

This method consumes a significant amount of runtime and memory to build the `words_range_query_indices_map` and keeps unnecessary repeated numbers while computing the `vowel_table`.

### `src-2.cpp`

This approach treats the prefix sum as a straightforward mathematical problem. While checking if each word in the list is a valid vowel, build the `vowel_table`. This table stores the cumulative sum of valid vowels from the beginning to the current index. To get the answer, simply compute the difference between the values in the `vowel_table` at the left and right indices of each word range.

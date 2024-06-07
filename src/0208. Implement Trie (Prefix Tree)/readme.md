# 208. Implement Trie (Prefix Tree)

## Comparison

| f name | Runtime | Beats (%) | Memory | Beats (%) |
|:------:|:-------:|:---------:|:------:|:---------:|
| src-1  |   75    |   17.82   | 50.15  |   26.77   |
| src-2  |   45    |   72.54   | 55.77  |   87.79   |
| src-3  |   30    |   99.22   | 48.03  |   79.86   |
| src-4  |   68    |   23.68   | 35.80  |   97.90   |

## Details

### `src-1.cpp`

Uses `unordered_map` in the Node, where a given character points to the next Node. The core algorithm is implemented within the Node structure.

### `src-2.cpp`

Uses a `vector` in the Node, where the index corresponding to the given character (offset from 'a') points to the next Node. The core algorithm is implemented within the Node structure.

### `src-3.cpp`

Similar to `src-1.cpp` and `src-2.cpp`, the core algorithm is within the Node structure. However, initializing memory for new Nodes can significantly increase runtime and memory usage. This version uses an array to store the next Node and keeps the algorithm within the Trie class.

### `src-4.cpp`

Uses two `unordered_set`s to store the prefix and word, with the algorithm implemented within the Trie class.

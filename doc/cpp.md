# C++

## `std::set`

> ref. [std::set - cppreference.com](https://en.cppreference.com/w/cpp/container/set)

### Time complexity

| Operation |    Average    | Worst |
|:---------:|:-------------:|:-----:|
| Construct | O(n * log(n)) |       |
|  Search   |   O(log(n))   |       |
|  Insert   |   O(log(n))   |       |
|  Delete   |   O(log(n))   |       |

### Space complexity

| Operation | Average | Worst |
|:---------:|:-------:|:-----:|
|   Space   |  O(n)   |       |

## `std::reverse`

> ref. [std::reverse - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/reverse)

Reverses the order of the elements in the range `[first, last)`.

Time Complexity

Exactly `std::distance(first, last) / 2` swaps.

## `std::priority_queue`

TBD

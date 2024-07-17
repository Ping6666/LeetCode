# C++

## header `<algorithm>`

### `std::reverse`

> ref. [std::reverse - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/reverse)

Reverses the order of the elements in the range `[first, last)`.

#### Time Complexity

O(n) \
Exactly `std::distance(first, last) / 2` swaps.

### `std::sort`

> ref. [std::sort - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/sort)

Introsort

#### Time Complexity

O(n ⋅ log(n))

#### Usage: sort and keep the indice

```c
vector<int> indices(n);
for (int i = 0; i < n; i++)
{
    indices[i] = i;
}

sort(indices.begin(), indices.end(), [&](int lhs, int rhs) { return vec[lhs] < vec[rhs]; });

// ex.
// vec = {10, 3, 5, 7, 2}
// indices = {4, 1, 2, 3, 0}
```

### `std::nth_element`

> ref. [std::nth_element - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/nth_element)

Introselect \
keep all elements in the array that `first~nth <= nth <= nth~last`

#### Time Complexity

Average: O(n) \
Worst: O(n ⋅ log(n))

## header `<set>`

### `std::set`

> ref. [std::set - cppreference.com](https://en.cppreference.com/w/cpp/container/set)

Red–black trees

#### Time complexity

| Operation |    Average    | Worst |
|:---------:|:-------------:|:-----:|
| Construct | O(n ⋅ log(n)) |       |
|  Search   |   O(log(n))   |       |
|  Insert   |   O(log(n))   |       |
|  Delete   |   O(log(n))   |       |

#### Space complexity

O(n)

## header `<queue>`

### `std::priority_queue`

> ref. [std::priority_queue - cppreference.com](https://en.cppreference.com/w/cpp/container/priority_queue)

heap

#### Time complexity

> also see. [Heap (data structure) - Wikipedia](https://en.wikipedia.org/wiki/Heap_(data_structure)#Comparison_of_theoretic_bounds_for_variants)

| Operation  |  Average  | Worst |
|:----------:|:---------:|:-----:|
| Construct  |   O(n)    |       |
|  Get max   |   O(1)    |       |
| Delete max | O(log(n)) |       |
|   Insert   | O(log(n)) |       |

#### Space complexity

O(n)

## header `<deque>`

### `std::deque`

> ref. [std::deque - cppreference.com](https://en.cppreference.com/w/cpp/container/deque)

double-ended queue (queue + stack) \
As opposed to `std::vector`, the elements of a deque are not stored contiguously. (using doubly linked list) \
Expansion of a deque is cheaper than the expansion of a std::vector because it does not involve copying of the existing elements to a new memory location. On the other hand, deques typically have large minimal memory cost.

#### Time complexity

Random access: O(1)
Insert / Delete: O(1)

#### Space complexity

O(n)

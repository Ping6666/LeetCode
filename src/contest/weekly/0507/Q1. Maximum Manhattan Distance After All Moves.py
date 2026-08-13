def get_dir_id(c):
    if c == 'U':
        _id = 1
    elif c == 'D':
        _id = 1
    elif c == 'L':
        _id = 2
    elif c == 'R':
        _id = 2
    else:  # '_'
        _id = 0
    return _id


def get_dir_amount(c):
    if c == 'U':
        amount = -1
    elif c == 'D':
        amount = 1
    elif c == 'L':
        amount = -1
    elif c == 'R':
        amount = 1
    else:  # '_'
        amount = 1
    return amount


class Solution:

    def maxDistance(self, moves: str) -> int:
        _c_dir = [0] * 3

        _d = 0
        for m in moves:
            _id = get_dir_id(m)
            _c_dir[_id] += get_dir_amount(m)

            _d = abs(_c_dir[0]) + abs(_c_dir[1]) + abs(_c_dir[2])
            # max_d = max(max_d, _d)
        return _d

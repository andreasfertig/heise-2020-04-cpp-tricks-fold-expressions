// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

template<typename T, typename... Ts>
constexpr bool in_range(T min, T max, Ts... ts)
{
    return ((min <= ts && ts <= max) && ...);
}

int main()
{
    int x = 2;
    int y = 3;
    int z = 3;
    if(in_range(2, 5, x, y, z)) {
        // ...
    }

    int m = 4;
    int n = 5;
    if(in_range(m, n, x, y, z)) {
        // ...
    }
}
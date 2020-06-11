// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <vector>

void ManipulateVector(std::vector<int>& v)
{
    // manipulate v
}

template<typename T, typename... Args>
void push_back(std::vector<T>& v, Args&&... args)
{
    (v.push_back(std::forward<Args>(args)), ...);
}

int main()
{
    std::vector<int> v{1, 2, 3};

    ManipulateVector(v);

    int z = 5;

    v.push_back(z);
    v.push_back(6);
    v.push_back(7);
}
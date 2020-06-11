// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <vector>

void ManipulateVector(std::vector<int>& v)
{
    // manipulate v
}
template<typename T, typename... Args>
void PushBack(std::vector<T>& v, Args&&... args)
{
    (v.push_back(std::forward<Args>(args)), ...);
}

int main()
{
    std::vector<int> v{1, 2, 3};

    int z = 5;

    ManipulateVector(v);

    PushBack(v, z, 6, 7);
}
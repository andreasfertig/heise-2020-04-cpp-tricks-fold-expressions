// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <iostream>

template<typename... Ts>
auto StrCat(Ts&&... ts)
{
    std::string ret{};

    ret.reserve((ts.size() + ...));

    (ret += ... += ts);

    return ret;
}

int main()
{
    std::string a{"Hello,"};
    std::string b{" World"};
    std::string c{"!"};

    auto x = StrCat(a, b, c);

    std::cout << x << '\n';
}
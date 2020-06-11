// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <iostream>
#include <string>

namespace details {
    void StrCat(std::string& buffer) {}

    template<typename T, typename... Ts>
    void StrCat(std::string& buffer, T&& t, Ts&&... ts)
    {
        buffer += t;

        StrCat(buffer, ts...);
    }
}  // namespace details

template<typename... Ts>
std::string StrCat(Ts&&... ts)
{
    std::string ret{};

    details::StrCat(ret, ts...);

    return ret;
}

int main()
{
    std::string a{"Hello,"};
    std::string b{" World"};
    std::string c{"!"};

    auto x = StrCat(a, b, c);

    std::cout << x;
}
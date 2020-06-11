// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <iostream>

namespace details {

    size_t TotalLen() { return 0; }

    template<typename T, typename... Ts>
    size_t TotalLen(T&& t, Ts&&... ts)
    {
        return t.size() + TotalLen(ts...);
    }

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

    ret.reserve(details::TotalLen(ts...));

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
// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstddef>
#include <utility>
template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N], const T (&b)[N]);

struct MACAddress
{
    unsigned char value[6];
};

#ifdef CPP20
template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N], const T (&b)[N])
{
    return [&]<size_t... I>(std::index_sequence<I...>)
    {
        return ((a[I] == b[I]) && ...);
    }
    (std::make_index_sequence<N>{});
}

#else
namespace details {
    template<typename T, size_t N, size_t... I>
    constexpr bool
    Compare(const T (&a)[N], const T (&b)[N], std::index_sequence<I...>)
    {
        return ((a[I] == b[I]) && ...);
    }
}  // namespace details

template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N], const T (&b)[N])
{
    return details::Compare(a, b, std::make_index_sequence<N>{});
}

#endif
namespace details {
    template<typename T, size_t N, size_t... I>
    constexpr bool
    Compare(const T (&a)[N], const T& b, std::index_sequence<I...>)
    {
        return ((a[I] == b) && ...);
    }
}  // namespace details

template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N], const T& b)
{
    return details::Compare(a, b, std::make_index_sequence<N>{});
}

int main()
{
    constexpr MACAddress macA{0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
    constexpr MACAddress macB{0x1, 0x2, 0x3, 0x4, 0x5, 0x6};
    const unsigned char  v{0xff};

    if(Compare(macA.value, v)) {
        // ...
    }

    static_assert(Compare(macA.value, macB.value), "macs are not equal");
}
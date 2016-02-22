#ifndef endianness_included
#define endianness_included

#pragma once

#include <cstdint>
#include "endianness_utils.hpp"

namespace tlv
{

struct endianness
{
    static constexpr int le = 0;
    static constexpr int be = 1;
};

template <unsigned int byte_order>
struct to_little_endian
{
};

template <>
struct to_little_endian<endianness::le>
{
    static uint16_t convert_uint16(uint16_t v)
    {
        return v;
    }
    static uint32_t convert_uint32(uint32_t v)
    {
        return v;
    }
    static uint64_t convert_uint64(uint64_t v)
    {
        return v;
    }
    static int16_t convert_int16(int16_t v)
    {
        return v;
    }
    static int32_t convert_int32(int32_t v)
    {
        return v;
    }
    static int64_t convert_int64(int64_t v)
    {
        return v;
    }
};

template <>
struct to_little_endian<endianness::be>
{
    static uint16_t convert_uint16(uint16_t v)
    {
        return endianness_utils::swap_uint16(v);
    }
    static uint32_t convert_uint32(uint32_t v)
    {
        return endianness_utils::swap_uint32(v);
    }
    static uint64_t convert_uint64(uint64_t v)
    {
        return endianness_utils::swap_uint64(v);
    }
    static int16_t convert_int16(int16_t v)
    {
        return endianness_utils::swap_int16(v);
    }
    static int32_t convert_int32(int32_t v)
    {
        return endianness_utils::swap_int32(v);
    }
    static int64_t convert_int64(int64_t v)
    {
        return endianness_utils::swap_int64(v);
    }
};

}

#endif // endianness_included

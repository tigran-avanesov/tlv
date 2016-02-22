#ifndef endianness_utils_hpp_included
#define endianness_utils_hpp_included

#pragma once

#include <cstdint>

namespace tlv
{

struct endianness_utils
{
    static uint16_t swap_uint16(uint16_t val);
    static uint32_t swap_uint32(uint32_t val);
    static uint64_t swap_uint64(uint64_t val);
    static int16_t swap_int16(int16_t val);
    static int32_t swap_int32(int32_t val);
    static int64_t swap_int64(int64_t val);
};

}

#endif // endianness_utils_hpp_included

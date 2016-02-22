#ifndef utils_hpp_included
#define utils_hpp_included

#pragma once

namespace tlv
{
namespace utils
{

enum class byte_order
{
    little_endian,
    big_endian
};

byte_order detect_byte_order();

uint16_t uint16_swap(uint16_t v);
uint32_t uint32_swap(uint32_t v);
uint32_t uint64_swap(uint32_t v);

template <typename T> to_little_endian(T value);

} // utils
} // tlv

#endif // utils_hpp_included

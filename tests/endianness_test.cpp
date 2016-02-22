#include "gtest/gtest.h"
#include "endianness_utils.hpp"
#include "endianness.hpp"
#include "config.hpp"

//-----------------------------------------------------------------------------
typedef tlv::to_little_endian<tlv::config::cpu_endianness> to_little_endian;
//-----------------------------------------------------------------------------
TEST(tlv, swap_uint16)
{
    uint16_t value = 12345;
    uint16_t expected = 14640;
    uint16_t actual = tlv::endianness_utils::swap_uint16(value);

    ASSERT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(tlv, swap_uint32)
{
    uint32_t value = 123456789;
    uint32_t expected = 365779719;
    uint32_t actual = tlv::endianness_utils::swap_uint32(value);

    ASSERT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(tlv, swap_uint64)
{
    uint64_t value = 1234512345;
    uint64_t expected = 15648202521040650240ULL;
    uint64_t actual = tlv::endianness_utils::swap_uint64(value);

    ASSERT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(tlv, swap_int16)
{
    int16_t value = -12345;
    int16_t expected = -14385;
    int16_t actual = tlv::endianness_utils::swap_int16(value);

    ASSERT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(tlv, swap_int32)
{
    int32_t value = -123456789;
    int32_t expected = -349002504;
    int32_t actual = tlv::endianness_utils::swap_int32(value);

    ASSERT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(tlv, swap_int64)
{
    int64_t value = -1234512345;
    int64_t expected = 2870599146706829311;
    int64_t actual = tlv::endianness_utils::swap_int64(value);

    ASSERT_EQ(expected, actual);
}
//-----------------------------------------------------------------------------
TEST(tlv, endianness_convert_uint16)
{
    uint16_t orig_val = 123;

#if CPU_IS_BIGENDIAN == 1
    uint16_t swap_val = tlv::endianness_utils::swap_uint16(orig_val);
    ASSERT_EQ(swap_val, to_little_endian::convert_uint16(orig_val));
#else
    ASSERT_EQ(orig_val, to_little_endian::convert_uint16(orig_val));
#endif
}
//-----------------------------------------------------------------------------
TEST(tlv, endianness_convert_uint32)
{
    uint32_t orig_val = 12345;

#if CPU_IS_BIGENDIAN == 1
    uint32_t swap_val = tlv::endianness_utils::swap_uint32(orig_val);
    ASSERT_EQ(swap_val, to_little_endian::convert_uint32(orig_val));
#else
    ASSERT_EQ(orig_val, to_little_endian::convert_uint32(orig_val));
#endif
}
//-----------------------------------------------------------------------------
TEST(tlv, endianness_convert_uint64)
{
    uint64_t orig_val = 12345678;

#if CPU_IS_BIGENDIAN == 1
    uint64_t swap_val = tlv::endianness_utils::swap_uint64(orig_val);
    ASSERT_EQ(swap_val, to_little_endian::convert_uint64(orig_val));
#else
    ASSERT_EQ(orig_val, to_little_endian::convert_uint64(orig_val));
#endif
}
//-----------------------------------------------------------------------------
TEST(tlv, endianness_convert_int16)
{
    int16_t orig_val = -123;

#if CPU_IS_BIGENDIAN == 1
    int16_t swap_val = tlv::endianness_utils::swap_int16(orig_val);
    ASSERT_EQ(swap_val, to_little_endian::convert_int16(orig_val));
#else
    ASSERT_EQ(orig_val, to_little_endian::convert_int16(orig_val));
#endif
}
//-----------------------------------------------------------------------------
TEST(tlv, endianness_convert_int32)
{
    int32_t orig_val = -12345;

#if CPU_IS_BIGENDIAN == 1
    int32_t swap_val = tlv::endianness_utils::swap_int32(orig_val);
    ASSERT_EQ(swap_val, to_little_endian::convert_int32(orig_val));
#else
    ASSERT_EQ(orig_val, to_little_endian::convert_int32(orig_val));
#endif
}
//-----------------------------------------------------------------------------
TEST(tlv, endianness_convert_int64)
{
    int64_t orig_val = -12345678;

#if CPU_IS_BIGENDIAN == 1
    int64_t swap_val = tlv::endianness_utils::swap_int64(orig_val);
    ASSERT_EQ(swap_val, to_little_endian::convert_int64(orig_val));
#else
    ASSERT_EQ(orig_val, to_little_endian::convert_int64(orig_val));
#endif
}
//-----------------------------------------------------------------------------

#include "gtest/gtest.h"
#include "stream.hpp"

//-----------------------------------------------------------------------------
TEST(tlv, stream_empty)
{
    tlv::stream stream;

    ASSERT_EQ(0U, stream.size());
    ASSERT_EQ(nullptr, stream.data());
}
//-----------------------------------------------------------------------------
TEST(tlv, stream_empty_after_reset)
{
    tlv::stream stream;
    stream.write_uint8(1);
    stream.write_uint16(500);
    stream.reset();

    ASSERT_EQ(0U, stream.size());
    ASSERT_EQ(nullptr, stream.data());
}
//-----------------------------------------------------------------------------
TEST(tlv, stream_add_uint8)
{
    uint8_t expected[] = {0x01, 0xF4, 0x01};
    tlv::stream stream;
    stream.write_uint8(1);
    stream.write_uint16(500);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, stream_add_uint16)
{
    uint8_t expected[] = {0xF4, 0x01};
    tlv::stream stream;
    stream.write_uint16(500U);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, stream_add_uint32)
{
    uint8_t expected[] = {0xFF, 0x00, 0xFF, 0x00};
    tlv::stream stream;
    stream.write_uint32(0x00FF00FFU);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, stream_add_uint64)
{
    uint8_t expected[] = {0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00};
    tlv::stream stream;
    stream.write_uint64(0x00FF00FF00FF00FFU);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, stream_add_string)
{
    uint8_t expected[] = {'t', 'e', 's', 't'};
    tlv::stream stream;
    stream.write_string("test", 4);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------

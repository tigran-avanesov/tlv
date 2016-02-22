#include "gtest/gtest.h"
#include "encoder.hpp"
#include "config.hpp"

//-----------------------------------------------------------------------------
TEST(tlv, encoder_empty)
{
    tlv::stream stream;
    tlv::encoder e(stream);

    ASSERT_EQ(0, stream.size());
    ASSERT_EQ(nullptr, stream.data());
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_empty_after_reset)
{
    tlv::stream stream;
    tlv::encoder e(stream);
    e.encode<uint8_t>(1, 1);
    e.reset();

    ASSERT_EQ(0, stream.size());
    ASSERT_EQ(nullptr, stream.data());
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_encode_uint8)
{
    uint8_t expected[] =
    {
        0x01, 0x00, 0x01, 0x00, 0x01
    };

    tlv::stream stream;
    tlv::encoder(stream).encode<uint8_t>(1, 1);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_encode_uint16)
{
    uint8_t expected[] =
    {
        0x02, 0x00, 0x02, 0x00, 0xFF, 0x00
    };

    tlv::stream stream;
    tlv::encoder(stream).encode<uint16_t>(2, 0x00FF);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_encode_uint32)
{
    uint8_t expected[] =
    {
        0x03, 0x00, 0x04, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
    };

    tlv::stream stream;
    tlv::encoder(stream).encode<uint32_t>(3, 0xFFFFFFFF);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_encode_uint64)
{
    uint8_t expected[] =
    {
        0x04, 0x00, 0x08, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00
    };

    tlv::stream stream;
    tlv::encoder(stream).encode<uint64_t>(4, 0xFFFFFFFF);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_encode_string)
{
    uint8_t expected[] =
    {
        0x05, 0x00, 0x04, 0x00, 't', 'e', 's', 't' 
    };

    tlv::stream stream;
    tlv::encoder(stream).encode<std::string>(5, "test");

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------
TEST(tlv, encoder_encode_vector_of_int)
{
    typedef std::vector<uint16_t> short_vector;

    short_vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    uint8_t expected[] =
    {
        0x06, 0x00, 0x06, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00 
    };

    tlv::stream stream;
    tlv::encoder(stream).encode<short_vector>(6, vec);

    ASSERT_EQ(sizeof(expected), stream.size());

    for (std::size_t i = 0; i != stream.size(); ++i)
    {
        EXPECT_EQ(expected[i], stream.data()[i]);
    }
}
//-----------------------------------------------------------------------------

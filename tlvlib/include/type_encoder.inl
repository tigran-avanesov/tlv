#include <cstdint>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

//-----------------------------------------------------------------------------
template <>
struct tlv_tag_encoder<uint8_t>
{
    void operator()(tlv::stream& stream, const uint8_t& tag)
    {
        stream.write_uint8(tag);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_tag_encoder<uint16_t>
{
    void operator()(tlv::stream& stream, const uint16_t& tag)
    {
        stream.write_uint16(tag);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_tag_encoder<uint32_t>
{
    void operator()(tlv::stream& stream, const uint32_t& tag)
    {
        stream.write_uint32(tag);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_len_encoder<uint8_t>
{
    void operator()(tlv::stream& stream, const uint8_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_val_encoder<uint8_t>
{
    void operator()(tlv::stream& stream, const uint8_t& value)
    {
        stream.write_uint8(value);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_len_encoder<uint16_t>
{
    void operator()(tlv::stream& stream, const uint16_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_val_encoder<uint16_t>
{
    void operator()(tlv::stream& stream, const uint16_t& value)
    {
        stream.write_uint16(value);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_len_encoder<uint32_t>
{
    void operator()(tlv::stream& stream, const uint32_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_val_encoder<uint32_t>
{
    void operator()(tlv::stream& stream, const uint32_t& value)
    {
        stream.write_uint32(value);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_len_encoder<uint64_t>
{
    void operator()(tlv::stream& stream, const uint64_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_val_encoder<uint64_t>
{
    void operator()(tlv::stream& stream, const uint64_t& value)
    {
        stream.write_uint64(value);
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_len_encoder<std::string>
{
    void operator()(tlv::stream& stream, const std::string& value)
    {
        stream.write_uint16(value.size());
    }
};
//-----------------------------------------------------------------------------
template <>
struct tlv_val_encoder<std::string>
{
    void operator()(tlv::stream& stream, const std::string& value)
    {
        stream.write_string(value.data(), value.size());
    }
};
//-----------------------------------------------------------------------------
template <typename T>
struct tlv_len_encoder< std::vector<T> >
{
    void operator()(tlv::stream& stream, const std::vector<T>& vec)
    {
        stream.write_uint16(vec.size() * sizeof(T));
    }
};
//-----------------------------------------------------------------------------
template <typename T>
struct tlv_val_encoder< std::vector<T> >
{
    void operator()(tlv::stream& stream, const std::vector<T>& vec)
    {
        std::for_each(vec.begin(), vec.end(),
            std::bind(tlv_val_encoder<T>(),
                std::ref(stream), std::placeholders::_1));
    }
};
//-----------------------------------------------------------------------------

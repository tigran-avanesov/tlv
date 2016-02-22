#include <cstring>
#include "stream.hpp"

//-----------------------------------------------------------------------------
tlv::stream::stream()
    : size_(0)
{
}
//-----------------------------------------------------------------------------
void tlv::stream::write_uint8(uint8_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_uint16(uint16_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_uint32(uint32_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_uint64(uint64_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_int8(int8_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_int16(int16_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_int32(int32_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_int64(int64_t v)
{
    return write_data(&v, sizeof(v));
}
//-----------------------------------------------------------------------------
void tlv::stream::write_string(const char* str, std::size_t length)
{
    return write_data(str, length);
}
//-----------------------------------------------------------------------------
void tlv::stream::write_data(const void* data, std::size_t length)
{
    grow_if_needed(size() + length);
    std::memcpy(memory_.data() + size(), data, length);
    size_ += length;
}
//-----------------------------------------------------------------------------
void tlv::stream::reset()
{
    std::vector<uint8_t>().swap(memory_);
    size_ = 0;
}
//-----------------------------------------------------------------------------
std::size_t tlv::stream::size() const
{
    return size_;
}
//-----------------------------------------------------------------------------
const uint8_t* tlv::stream::data() const
{
    return memory_.data();	
}
//-----------------------------------------------------------------------------
void tlv::stream::grow_if_needed(std::size_t required_size)
{
    if (memory_.capacity() == 0)
    {
        memory_.reserve(100);
    } else if (memory_.capacity() < required_size)
    {
        memory_.reserve(memory_.capacity() * 2);
    }
}
//-----------------------------------------------------------------------------

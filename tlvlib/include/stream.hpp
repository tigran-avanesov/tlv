#ifndef stream_hpp_included
#define stream_hpp_included

#pragma once

#include <vector>
#include <cstdint>

namespace tlv
{

class stream
{
public:
    stream();

    void write_uint8(uint8_t v);
    void write_uint16(uint16_t v);
    void write_uint32(uint32_t v);
    void write_uint64(uint64_t v);
    void write_int8(int8_t v);
    void write_int16(int16_t v);
    void write_int32(int32_t v);
    void write_int64(int64_t v);
    void write_string(const char* str, std::size_t length);

    void reset();

    std::size_t size() const;
    const uint8_t* data() const;
private:
    void write_data(const void* data, std::size_t length);
    void grow_if_needed(std::size_t required_size);
private:
    std::vector<uint8_t> memory_;
    std::size_t size_;
};

}

#endif // stream_hpp_included

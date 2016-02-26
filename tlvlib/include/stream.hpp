#ifndef stream_hpp_included
#define stream_hpp_included

#pragma once

#include <vector>
#include <cstdint>

namespace tlv
{

/*! TLV data stream implementation */
class stream
{
public:
    /*! Constructor */
    stream();

    /*! Encode 8 bit unsigned integer to the stream */
    /*!
        \param v value to encode
    */
    void write_uint8(uint8_t v);

    /*! Encode 8 bit signed integer to the stream */
    /*!
        \param v value to encode
    */
    void write_int8(int8_t v);

    /*! Encode 16 bit unsigned integer to the stream */
    /*!
        \param v value to encode
    */
    void write_uint16(uint16_t v);

    /*! Encode 16 bit signed integer to the stream */
    /*!
        \param v value to encode
    */
    void write_int16(int16_t v);

    /*! Encode 32 bit unsigned integer to the stream */
    /*!
        \param v value to encode
    */
    void write_uint32(uint32_t v);

    /*! Encode 32 bit signed integer to the stream */
    /*!
        \param v value to encode
    */
    void write_int32(int32_t v);

    /*! Encode 16 bit unsigned integer to the stream */
    /*!
        \param v value to encode
    */
    void write_uint64(uint64_t v);

    /*! Encode 64 bit unsigned integer to the stream */
    /*!
        \param v value to encode
    */
    void write_int64(int64_t v);

    /*! Encode string to the stream */
    /*!
        \param str string pointer to encode
        \param length string length
    */
    void write_string(const char* str, std::size_t length);

    /*! Reset stream to the default state */
    void reset();

    /*! Get current size of the stream */
    /*!
        \return current size of the stream in bytes
    */
    std::size_t size() const;

    /*! Get pointer stream data */
    /*!
        \return void pointer to the raw encoded data
    */
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

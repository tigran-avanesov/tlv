#ifndef type_encoder_hpp_included
#define type_encoder_hpp_included

#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

#include "stream.hpp"

/*! Encode tag of the given type to stream */
template <typename T>
struct tlv_tag_encoder
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param tag tag to encode
    */
    void operator()(tlv::stream& stream, const T& tag);
};

/*! Encode data length of the given type to stream */
template <typename T>
struct tlv_len_encoder
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to get and encode size for
    */
    void operator()(tlv::stream& stream, const T& value);
};

/*! Encode value of the given type to stream */
template <typename T>
struct tlv_val_encoder
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to encode
    */
    void operator()(tlv::stream& stream, const T& value);
};

/*! Encode 8 bit tag to the stream */
template <>
struct tlv_tag_encoder<uint8_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param tag tag to encode
    */
    void operator()(tlv::stream& stream, const uint8_t& tag)
    {
        stream.write_uint8(tag);
    }
};

/*! Encode 16 bit tag to the stream */
template <>
struct tlv_tag_encoder<uint16_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param tag tag to encode
    */
    void operator()(tlv::stream& stream, const uint16_t& tag)
    {
        stream.write_uint16(tag);
    }
};

/*! Encode 32 bit tag to the stream */
template <>
struct tlv_tag_encoder<uint32_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param tag tag to encode
    */
    void operator()(tlv::stream& stream, const uint32_t& tag)
    {
        stream.write_uint32(tag);
    }
};

/*! Encode 8 bit unsigned integer value size to the stream */
template <>
struct tlv_len_encoder<uint8_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to calculate and encode size for
    */
    void operator()(tlv::stream& stream, const uint8_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};

/*! Encode 8 bit unsigned integer value to the stream */
template <>
struct tlv_val_encoder<uint8_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to encode
    */
    void operator()(tlv::stream& stream, const uint8_t& value)
    {
        stream.write_uint8(value);
    }
};

/*! Encode 16 bit unsigned integer value size to the stream */
template <>
struct tlv_len_encoder<uint16_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to calculate and encode size for
    */
    void operator()(tlv::stream& stream, const uint16_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};

/*! Encode 16 bit unsigned integer value to the stream */
template <>
struct tlv_val_encoder<uint16_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to encode
    */
    void operator()(tlv::stream& stream, const uint16_t& value)
    {
        stream.write_uint16(value);
    }
};

/*! Encode 32 bit unsigned integer value size to the stream */
template <>
struct tlv_len_encoder<uint32_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to calculate and encode size for
    */
    void operator()(tlv::stream& stream, const uint32_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};

/*! Encode 32 bit unsigned integer value to the stream */
template <>
struct tlv_val_encoder<uint32_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to encode
    */
    void operator()(tlv::stream& stream, const uint32_t& value)
    {
        stream.write_uint32(value);
    }
};

/*! Encode 64 bit unsigned integer value size to the stream */
template <>
struct tlv_len_encoder<uint64_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to calculate and encode size for
    */
    void operator()(tlv::stream& stream, const uint64_t& value)
    {
        stream.write_uint16(sizeof(value));
    }
};

/*! Encode 64 bit unsigned integer value to the stream */
template <>
struct tlv_val_encoder<uint64_t>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to encode
    */
    void operator()(tlv::stream& stream, const uint64_t& value)
    {
        stream.write_uint64(value);
    }
};

/*! Encode std::string size to the stream */
template <>
struct tlv_len_encoder<std::string>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to calculate and encode size for
    */
    void operator()(tlv::stream& stream, const std::string& value)
    {
        stream.write_uint16(value.size());
    }
};

/*! Encode std::string to the stream */
template <>
struct tlv_val_encoder<std::string>
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param value value to encode
    */
    void operator()(tlv::stream& stream, const std::string& value)
    {
        stream.write_string(value.data(), value.size());
    }
};

/*! Encode vector of given type size to the stream */
template <typename T>
struct tlv_len_encoder< std::vector<T> >
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param vec vector to calculate and encode size for
    */
    void operator()(tlv::stream& stream, const std::vector<T>& vec)
    {
        stream.write_uint16(vec.size() * sizeof(T));
    }
};

/*! Encode vector of given type to the stream */
template <typename T>
struct tlv_val_encoder< std::vector<T> >
{
    /*! Encoder function operator implementation */
    /*!
        \param stream stream to encode data to
        \param vec vector to encode
    */
    void operator()(tlv::stream& stream, const std::vector<T>& vec)
    {
        std::for_each(vec.begin(), vec.end(),
            std::bind(tlv_val_encoder<T>(),
                std::ref(stream), std::placeholders::_1));
    }
};

#endif // type_encoder_hpp_included

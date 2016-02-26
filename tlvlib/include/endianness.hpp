#ifndef endianness_included
#define endianness_included

#pragma once

#include <cstdint>
#include "endianness_utils.hpp"

namespace tlv
{

/*! Constants enumeration of supported endianness types */
struct endianness
{
    static constexpr int le = 0; /*!< little endian CPU architecture */
    static constexpr int be = 1; /*!< big endian CPU architecture */
};

/*! Default implementation of to_little_endian template (does nothing) */
template <unsigned int byte_order>
struct to_little_endian
{
};

/*! Implementation of to_little_endian template for little endian machines */
template <>
struct to_little_endian<endianness::le>
{
    /*! Convert given unsigned 16 bit unsigned integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return given value as it is wihtout changes
    */
    static uint16_t convert_uint16(uint16_t v)
    {
        return v;
    }

    /*! Convert given unsigned 16 bit signed integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return given value as it is wihtout changes
    */
    static int16_t convert_int16(int16_t v)
    {
        return v;
    }

    /*! Convert given unsigned 32 bit unsigned integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return given value as it is wihtout changes
    */
    static uint32_t convert_uint32(uint32_t v)
    {
        return v;
    }

    /*! Convert given unsigned 32 bit signed integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return given value as it is wihtout changes
    */
    static int32_t convert_int32(int32_t v)
    {
        return v;
    }

    /*! Convert given unsigned 64 bit unsigned integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return given value as it is wihtout changes
    */
    static uint64_t convert_uint64(uint64_t v)
    {
        return v;
    }

    /*! Convert given unsigned 64 bit signed integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return given value as it is wihtout changes
    */
    static int64_t convert_int64(int64_t v)
    {
        return v;
    }
};

/*! Implementation of to_little_endian template for big endian machines */
template <>
struct to_little_endian<endianness::be>
{
    /*! Convert given unsigned 16 bit unsigned integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return value with bytes swapped
    */
    static uint16_t convert_uint16(uint16_t v)
    {
        return endianness_utils::swap_uint16(v);
    }

    /*! Convert given unsigned 16 bit signed integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return value with bytes swapped
    */
    static int16_t convert_int16(int16_t v)
    {
        return endianness_utils::swap_int16(v);
    }

    /*! Convert given unsigned 32 bit unsigned integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return value with bytes swapped
    */
    static uint32_t convert_uint32(uint32_t v)
    {
        return endianness_utils::swap_uint32(v);
    }

    /*! Convert given unsigned 32 bit signed integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return value with bytes swapped
    */
    static int32_t convert_int32(int32_t v)
    {
        return endianness_utils::swap_int32(v);
    }

    /*! Convert given unsigned 64 bit unsigned integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return value with bytes swapped
    */
    static uint64_t convert_uint64(uint64_t v)
    {
        return endianness_utils::swap_uint64(v);
    }

    /*! Convert given unsigned 64 bit signed integer value to little endian */
    /*!
        \param v value to swap bytes for
        \return value with bytes swapped
    */
    static int64_t convert_int64(int64_t v)
    {
        return endianness_utils::swap_int64(v);
    }
};

}

#endif // endianness_included

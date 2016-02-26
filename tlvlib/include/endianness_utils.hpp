#ifndef endianness_utils_hpp_included
#define endianness_utils_hpp_included

#pragma once

#include <cstdint>

namespace tlv
{

/*! Structure for byte order swapping utility functions */
struct endianness_utils
{
    /*! Swap bytes in unsigned 16 bit integer value */
    /*!
        \param val value to swap bytes for
        \return converted value with bytes swapped
        \sa swap_int16()
    */
    static uint16_t swap_uint16(uint16_t val);

    /*! Swap bytes in signed 16 bit integer value */
    /*!
        \param val value to swap bytes for
        \return converted value with bytes swapped
        \sa swap_uint16()
    */
    static int16_t swap_int16(int16_t val);

    /*! Swap bytes in unsigned 32 bit integer value */
    /*!
        \param val value to swap bytes for
        \return converted value with bytes swapped
        \sa swap_int32()
    */
    static uint32_t swap_uint32(uint32_t val);

    /*! Swap bytes in signed 32 bit integer value */
    /*!
        \param val value to swap bytes for
        \return converted value with bytes swapped
        \sa swap_uint32()
    */
    static int32_t swap_int32(int32_t val);
 
    /*! Swap bytes in signed 64 bit integer value */
    /*!
        \param val value to swap bytes for
        \return converted value with bytes swapped
        \sa swap_int64()
    */
    static uint64_t swap_uint64(uint64_t val);

    /*! Swap bytes in unsigned 64 bit integer value */
    /*!
        \param val value to swap bytes for
        \return converted value with bytes swapped
        \sa swap_uint64()
    */
    static int64_t swap_int64(int64_t val);
};

}

#endif // endianness_utils_hpp_included

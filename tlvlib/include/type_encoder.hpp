#ifndef type_encoder_hpp_included
#define type_encoder_hpp_included

#pragma once

#include "stream.hpp"

template <typename T>
struct tlv_tag_encoder
{
    void operator()(tlv::stream& stream, const T& tag);
};

template <typename T>
struct tlv_len_encoder
{
    void operator()(tlv::stream& stream, const T& length);
};

template <typename T>
struct tlv_val_encoder
{
    void operator()(tlv::stream& stream, const T& value);
};

#include "type_encoder.inl"

#endif // type_encoder_hpp_included

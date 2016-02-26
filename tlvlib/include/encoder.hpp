#ifndef encoder_hpp_included
#define encoder_hpp_included

#pragma once

#include "config.hpp"
#include "stream.hpp"
#include "type_encoder.hpp"

namespace tlv
{

/*! TLV data encoder class implementation */
class encoder
{
    typedef config::tag_t tag_type;
public:
    /*! Constructor */
    /*!
        \param s stream to encode data to
    */
    encoder(stream& s);

    /*! Encode given TLV element */
    /*!
        \param tag of the element being encoded
        \param val value of the element being encoded
        \return self reference
    */
    template <typename T>
    encoder& encode(tag_type tag, const T& val)
    {
        tlv_tag_encoder<tag_type> tag_encoder;
        tlv_len_encoder<T> len_encoder;
        tlv_val_encoder<T> val_encoder;
        tag_encoder(stream_, tag);
        len_encoder(stream_, val);
        val_encoder(stream_, val);
        return *this;
    }

    /*! Reset underlying stream to the default state */
    void reset();

    /*! Get underlying stream */
    /*!
        \return constant reference to the underlying stream
    */
    const stream& data_stream() const;
private:
    stream& stream_;
};

}

#endif // encoder_hpp_included

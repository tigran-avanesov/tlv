#ifndef encoder_hpp_included
#define encoder_hpp_included

#pragma once

#include "config.hpp"
#include "stream.hpp"
#include "type_encoder.hpp"

namespace tlv
{

class encoder
{
public:
    encoder(stream& s);

    template <typename T>
    encoder& encode(tag_t tag, const T& value)
    {
        tlv_tag_encoder<tag_t> tag_encoder;
        tlv_len_encoder<T> len_encoder;
        tlv_val_encoder<T> val_encoder;
        tag_encoder(stream_, tag);
        len_encoder(stream_, value);
        val_encoder(stream_, value);
        return *this;
    }

    void reset();
    const stream& data_stream() const;
private:
    stream& stream_;
};

}

#endif // encoder_hpp_included

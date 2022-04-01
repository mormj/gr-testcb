/* -*- c++ -*- */
/*
 * Copyright 2022 gr-testcb author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "foo_impl.h"
#include <gnuradio/io_signature.h>

#include <gnuradio/buffer_double_mapped.h>
#include <gnuradio/host_buffer.h>
#include <gnuradio/io_signature.h>


namespace gr {
namespace testcb {

using input_type = float;
using output_type = float;
foo::sptr foo::make() { return gnuradio::make_block_sptr<foo_impl>(); }


/*
 * The private constructor
 */
foo_impl::foo_impl()
    : gr::sync_block("foo",
#if 0
                     gr::io_signature::make(
                         1 /* min inputs */, 1 /* max inputs */, sizeof(input_type), buffer_double_mapped::type),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type), buffer_double_mapped::type))
#else
          gr::io_signature::make(1, 1, sizeof(input_type), host_buffer::type),
          gr::io_signature::make(1, 1, sizeof(output_type), host_buffer::type))
#endif
{
    set_history(100);
}

/*
 * Our virtual destructor.
 */
foo_impl::~foo_impl() {}

int foo_impl::work(int noutput_items,
                   gr_vector_const_void_star& input_items,
                   gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto out = static_cast<output_type*>(output_items[0]);

    memcpy(out, in + history() - 1, sizeof(input_type) * noutput_items);
    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace testcb */
} /* namespace gr */

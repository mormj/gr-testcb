/* -*- c++ -*- */
/*
 * Copyright 2022 gr-testcb author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTCB_FOO_IMPL_H
#define INCLUDED_TESTCB_FOO_IMPL_H

#include <gnuradio/testcb/foo.h>

namespace gr {
namespace testcb {

class foo_impl : public foo
{
private:
    // Nothing to declare in this block.

public:
    foo_impl();
    ~foo_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace testcb
} // namespace gr

#endif /* INCLUDED_TESTCB_FOO_IMPL_H */

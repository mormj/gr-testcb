/* -*- c++ -*- */
/*
 * Copyright 2022 gr-testcb author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_TESTCB_FOO_H
#define INCLUDED_TESTCB_FOO_H

#include <gnuradio/sync_block.h>
#include <gnuradio/testcb/api.h>

namespace gr {
namespace testcb {

/*!
 * \brief <+description of block+>
 * \ingroup testcb
 *
 */
class TESTCB_API foo : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<foo> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of testcb::foo.
     *
     * To avoid accidental use of raw pointers, testcb::foo's
     * constructor is in a private implementation
     * class. testcb::foo::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};

} // namespace testcb
} // namespace gr

#endif /* INCLUDED_TESTCB_FOO_H */

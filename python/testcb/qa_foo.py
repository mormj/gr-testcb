#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2022 gr-testcb author.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
try:
  from gnuradio.testcb import foo
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from gnuradio.testcb import foo

class qa_foo(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_instance(self):
        # FIXME: Test will fail until you pass sensible arguments to the constructor
        instance = foo()

    def test_001_descriptive_test_name(self):
        src_data = 40000 * [1, 2, 3, 4]
        expected_data = src_data

        src = blocks.vector_source_f(src_data)
        op = foo()
        dst = blocks.vector_sink_f()
        self.tb.connect(src, op, dst)
        self.tb.run()
        result_data = dst.data()
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_foo)

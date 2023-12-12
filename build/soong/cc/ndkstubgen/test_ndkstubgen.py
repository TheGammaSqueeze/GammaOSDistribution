#!/usr/bin/env python
#
# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
"""Tests for ndkstubgen.py."""
import io
import textwrap
import unittest

import ndkstubgen
import symbolfile
from symbolfile import Arch, Tag


# pylint: disable=missing-docstring


class GeneratorTest(unittest.TestCase):
    def test_omit_version(self) -> None:
        # Thorough testing of the cases involved here is handled by
        # OmitVersionTest, PrivateVersionTest, and SymbolPresenceTest.
        src_file = io.StringIO()
        version_file = io.StringIO()
        generator = ndkstubgen.Generator(src_file, version_file, Arch('arm'),
                                         9, False, False)

        version = symbolfile.Version('VERSION_PRIVATE', None, [], [
            symbolfile.Symbol('foo', []),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

        version = symbolfile.Version('VERSION', None, [Tag('x86')], [
            symbolfile.Symbol('foo', []),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

        version = symbolfile.Version('VERSION', None, [Tag('introduced=14')], [
            symbolfile.Symbol('foo', []),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

    def test_omit_symbol(self) -> None:
        # Thorough testing of the cases involved here is handled by
        # SymbolPresenceTest.
        src_file = io.StringIO()
        version_file = io.StringIO()
        generator = ndkstubgen.Generator(src_file, version_file, Arch('arm'),
                                         9, False, False)

        version = symbolfile.Version('VERSION_1', None, [], [
            symbolfile.Symbol('foo', [Tag('x86')]),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

        version = symbolfile.Version('VERSION_1', None, [], [
            symbolfile.Symbol('foo', [Tag('introduced=14')]),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

        version = symbolfile.Version('VERSION_1', None, [], [
            symbolfile.Symbol('foo', [Tag('llndk')]),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

        version = symbolfile.Version('VERSION_1', None, [], [
            symbolfile.Symbol('foo', [Tag('apex')]),
        ])
        generator.write_version(version)
        self.assertEqual('', src_file.getvalue())
        self.assertEqual('', version_file.getvalue())

    def test_write(self) -> None:
        src_file = io.StringIO()
        version_file = io.StringIO()
        generator = ndkstubgen.Generator(src_file, version_file, Arch('arm'),
                                         9, False, False)

        versions = [
            symbolfile.Version('VERSION_1', None, [], [
                symbolfile.Symbol('foo', []),
                symbolfile.Symbol('bar', [Tag('var')]),
                symbolfile.Symbol('woodly', [Tag('weak')]),
                symbolfile.Symbol('doodly',
                                  [Tag('weak'), Tag('var')]),
            ]),
            symbolfile.Version('VERSION_2', 'VERSION_1', [], [
                symbolfile.Symbol('baz', []),
            ]),
            symbolfile.Version('VERSION_3', 'VERSION_1', [], [
                symbolfile.Symbol('qux', [Tag('versioned=14')]),
            ]),
        ]

        generator.write(versions)
        expected_src = textwrap.dedent("""\
            void foo() {}
            int bar = 0;
            __attribute__((weak)) void woodly() {}
            __attribute__((weak)) int doodly = 0;
            void baz() {}
            void qux() {}
        """)
        self.assertEqual(expected_src, src_file.getvalue())

        expected_version = textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo;
                    bar;
                    woodly;
                    doodly;
            };
            VERSION_2 {
                global:
                    baz;
            } VERSION_1;
        """)
        self.assertEqual(expected_version, version_file.getvalue())


class IntegrationTest(unittest.TestCase):
    def test_integration(self) -> None:
        api_map = {
            'O': 9000,
            'P': 9001,
        }

        input_file = io.StringIO(textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo; # var
                    bar; # x86
                    fizz; # introduced=O
                    buzz; # introduced=P
                local:
                    *;
            };

            VERSION_2 { # arm
                baz; # introduced=9
                qux; # versioned=14
            } VERSION_1;

            VERSION_3 { # introduced=14
                woodly;
                doodly; # var
            } VERSION_2;

            VERSION_4 { # versioned=9
                wibble;
                wizzes; # llndk
                waggle; # apex
            } VERSION_2;

            VERSION_5 { # versioned=14
                wobble;
            } VERSION_4;
        """))
        parser = symbolfile.SymbolFileParser(input_file, api_map, Arch('arm'),
                                             9, False, False)
        versions = parser.parse()

        src_file = io.StringIO()
        version_file = io.StringIO()
        generator = ndkstubgen.Generator(src_file, version_file, Arch('arm'),
                                         9, False, False)
        generator.write(versions)

        expected_src = textwrap.dedent("""\
            int foo = 0;
            void baz() {}
            void qux() {}
            void wibble() {}
            void wobble() {}
        """)
        self.assertEqual(expected_src, src_file.getvalue())

        expected_version = textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo;
            };
            VERSION_2 {
                global:
                    baz;
            } VERSION_1;
            VERSION_4 {
                global:
                    wibble;
            } VERSION_2;
        """)
        self.assertEqual(expected_version, version_file.getvalue())

    def test_integration_future_api(self) -> None:
        api_map = {
            'O': 9000,
            'P': 9001,
            'Q': 9002,
        }

        input_file = io.StringIO(textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo; # introduced=O
                    bar; # introduced=P
                    baz; # introduced=Q
                local:
                    *;
            };
        """))
        parser = symbolfile.SymbolFileParser(input_file, api_map, Arch('arm'),
                                             9001, False, False)
        versions = parser.parse()

        src_file = io.StringIO()
        version_file = io.StringIO()
        generator = ndkstubgen.Generator(src_file, version_file, Arch('arm'),
                                         9001, False, False)
        generator.write(versions)

        expected_src = textwrap.dedent("""\
            void foo() {}
            void bar() {}
        """)
        self.assertEqual(expected_src, src_file.getvalue())

        expected_version = textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo;
                    bar;
            };
        """)
        self.assertEqual(expected_version, version_file.getvalue())

    def test_multiple_definition(self) -> None:
        input_file = io.StringIO(textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo;
                    foo;
                    bar;
                    baz;
                    qux; # arm
                local:
                    *;
            };

            VERSION_2 {
                global:
                    bar;
                    qux; # arm64
            } VERSION_1;

            VERSION_PRIVATE {
                global:
                    baz;
            } VERSION_2;

        """))
        parser = symbolfile.SymbolFileParser(input_file, {}, Arch('arm'), 16,
                                             False, False)

        with self.assertRaises(
                symbolfile.MultiplyDefinedSymbolError) as ex_context:
            parser.parse()
        self.assertEqual(['bar', 'foo'],
                         ex_context.exception.multiply_defined_symbols)

    def test_integration_with_apex(self) -> None:
        api_map = {
            'O': 9000,
            'P': 9001,
        }

        input_file = io.StringIO(textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo; # var
                    bar; # x86
                    fizz; # introduced=O
                    buzz; # introduced=P
                local:
                    *;
            };

            VERSION_2 { # arm
                baz; # introduced=9
                qux; # versioned=14
            } VERSION_1;

            VERSION_3 { # introduced=14
                woodly;
                doodly; # var
            } VERSION_2;

            VERSION_4 { # versioned=9
                wibble;
                wizzes; # llndk
                waggle; # apex
                bubble; # apex llndk
                duddle; # llndk apex
            } VERSION_2;

            VERSION_5 { # versioned=14
                wobble;
            } VERSION_4;
        """))
        parser = symbolfile.SymbolFileParser(input_file, api_map, Arch('arm'),
                                             9, False, True)
        versions = parser.parse()

        src_file = io.StringIO()
        version_file = io.StringIO()
        generator = ndkstubgen.Generator(src_file, version_file, Arch('arm'),
                                         9, False, True)
        generator.write(versions)

        expected_src = textwrap.dedent("""\
            int foo = 0;
            void baz() {}
            void qux() {}
            void wibble() {}
            void waggle() {}
            void bubble() {}
            void duddle() {}
            void wobble() {}
        """)
        self.assertEqual(expected_src, src_file.getvalue())

        expected_version = textwrap.dedent("""\
            VERSION_1 {
                global:
                    foo;
            };
            VERSION_2 {
                global:
                    baz;
            } VERSION_1;
            VERSION_4 {
                global:
                    wibble;
                    waggle;
                    bubble;
                    duddle;
            } VERSION_2;
        """)
        self.assertEqual(expected_version, version_file.getvalue())


def main() -> None:
    suite = unittest.TestLoader().loadTestsFromName(__name__)
    unittest.TextTestRunner(verbosity=3).run(suite)


if __name__ == '__main__':
    main()

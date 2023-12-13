#!/usr/bin/python -B

"""Regenerates (just) ICU data files used in the Android system image."""

from __future__ import print_function

import sys

import icuutil


# Run with no arguments from any directory, with no special setup required.
def main():
  icu_dir = icuutil.icuDir()
  print('Found icu in %s ...' % icu_dir)

  icuutil.GenerateIcuDataFiles()

  print('Look in %s for new data files' % icu_dir)
  sys.exit(0)

if __name__ == '__main__':
  main()

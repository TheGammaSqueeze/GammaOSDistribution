# fsverity-utils release notes

## Version 1.3

* Added a `fsverity digest` subcommand.

* Added `libfsverity_enable()` and `libfsverity_enable_with_sig()`.

* Added basic support for Windows builds of `fsverity` using MinGW.

* `fsverity` now defaults to 4096-byte blocks on all platforms.

* libfsverity now will use SHA-256 with 4096-byte blocks if the
  `hash_algorithm` and `block_size` fields are left 0.

* `make install` now installs a pkg-config file for libfsverity.

* The Makefile now uses pkg-config to get the libcrypto build flags.

* Fixed `make check` with `USE_SHARED_LIB=1`.

## Version 1.2

* Changed license from GPL to MIT.

* Fixed build error when /bin/sh is dash.

## Version 1.1

* Split the file digest computation and signing functionality of the
  `fsverity` program into a library `libfsverity`.  See `README.md`
  and `Makefile` for more details.

* Improved the Makefile.

* Added some tests.  They can be run using `make check`.  Also added
  `scripts/run-tests.sh` which does more extensive prerelease tests.

* Lots of cleanups and other small improvements.

## Version 1.0

* First official release of fsverity-utils.

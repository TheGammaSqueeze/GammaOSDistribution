# fsverity-utils

## Introduction

This is fsverity-utils, a set of userspace utilities for fs-verity.
fs-verity is a Linux kernel feature that does transparent on-demand
integrity/authenticity verification of the contents of read-only
files, using a hidden Merkle tree (hash tree) associated with the
file.  It is similar to dm-verity, but implemented at the file level
rather than at the block device level.  See the [kernel
documentation](https://www.kernel.org/doc/html/latest/filesystems/fsverity.html)
for more information about fs-verity.

fs-verity is supported by the ext4 and f2fs filesystems in Linux v5.4
and later when configured with `CONFIG_FS_VERITY=y` and when the
`verity` filesystem feature flag has been enabled.  Other filesystems
might add support for fs-verity in the future.

fsverity-utils currently contains just one program, `fsverity`.  The
`fsverity` program allows you to set up fs-verity protected files.
In addition, the file digest computation and signing functionality of
`fsverity` is optionally exposed through a C library `libfsverity`.
See `libfsverity.h` for the API of this library.

## Building and installing

fsverity-utils uses the OpenSSL library, so you first must install the
needed development files.  For example, on Debian-based systems, run:

```bash
    sudo apt-get install libssl-dev
```

OpenSSL must be version 1.0.0 or later.

Then, to build and install fsverity-utils:

```bash
    make
    sudo make install
```

By default, the following targets are built and installed: the program
`fsverity`, the static library `libfsverity.a`, and the shared library
`libfsverity.so`.  You can also run `make check` to build and run the
tests, or `make help` to display all available build targets.

By default, `fsverity` is statically linked to `libfsverity`.  You can
use `make USE_SHARED_LIB=1` to use dynamic linking instead.

See the `Makefile` for other supported build and installation options.

### Building on Windows

There is minimal support for building Windows executables using MinGW.
```bash
    make CC=x86_64-w64-mingw32-gcc
```

`fsverity.exe` will be built, and it supports the `digest` and `sign` commands.

A Windows build of OpenSSL/libcrypto needs to be available.

## Examples

### Basic use

```bash
    mkfs.ext4 -O verity /dev/vdc
    mount /dev/vdc /vdc
    cd /vdc

    # Create a test file
    head -c 1000000 /dev/urandom > file
    sha256sum file

    # Enable verity on the file
    fsverity enable file

    # Show the verity file digest
    fsverity measure file

    # File should still be readable as usual.  However, all data read
    # is now transparently checked against a hidden Merkle tree, whose
    # root hash is incorporated into the verity file digest.  Reads of
    # any corrupted parts of the data will fail.
    sha256sum file
```

Note that in the above example, the file isn't signed.  Therefore, to
get any authenticity protection (as opposed to just integrity
protection), the output of `fsverity measure` needs to be compared
against a trusted value.

### Using builtin signatures

With `CONFIG_FS_VERITY_BUILTIN_SIGNATURES=y`, the filesystem supports
automatically verifying a signed file digest that has been included in
the verity metadata.  The signature is verified against the set of
X.509 certificates that have been loaded into the ".fs-verity" kernel
keyring.  Here's an example:

```bash
    # Generate a new certificate and private key:
    openssl req -newkey rsa:4096 -nodes -keyout key.pem -x509 -out cert.pem

    # Convert the certificate from PEM to DER format:
    openssl x509 -in cert.pem -out cert.der -outform der

    # Load the certificate into the fs-verity keyring:
    keyctl padd asymmetric '' %keyring:.fs-verity < cert.der

    # Optionally, lock the keyring so that no more keys can be added
    # (requires keyctl v1.5.11 or later):
    keyctl restrict_keyring %keyring:.fs-verity

    # Optionally, require that all verity files be signed:
    sysctl fs.verity.require_signatures=1

    # Now set up fs-verity on a test file:
    sha256sum file
    fsverity sign file file.sig --key=key.pem --cert=cert.pem
    fsverity enable file --signature=file.sig
    rm -f file.sig
    sha256sum file

    # The digest to be signed can also be printed separately, hex
    # encoded, in case the integrated signing cannot be used:
    fsverity digest file --compact --for-builtin-sig | tr -d '\n' | xxd -p -r | openssl smime -sign -in /dev/stdin ...
```

By default, it's not required that verity files have a signature.
This can be changed with `sysctl fs.verity.require_signatures=1`.
When set, it's guaranteed that the contents of every verity file has
been signed by one of the certificates in the keyring.

Note: applications generally still need to check whether the file
they're accessing really is a verity file, since an attacker could
replace a verity file with a regular one.

### With IMA

IMA support for fs-verity is planned.

## Notices

fsverity-utils is provided under the terms of the MIT license.  A copy
of this license can be found in the file named [LICENSE](LICENSE).

Send questions and bug reports to linux-fscrypt@vger.kernel.org.

Signed release tarballs for fsverity-utils can be found on
[kernel.org](https://kernel.org/pub/linux/kernel/people/ebiggers/fsverity-utils/).

## Contributing

Send patches to linux-fscrypt@vger.kernel.org with the additional tag
`fsverity-utils` in the subject, i.e. `[fsverity-utils PATCH]`.
Patches should follow the Linux kernel's coding style.  A
`.clang-format` file is provided to approximate this coding style;
consider using `git clang-format`.  Additionally, like the Linux
kernel itself, patches require the following "sign-off" procedure:

The sign-off is a simple line at the end of the explanation for the
patch, which certifies that you wrote it or otherwise have the right
to pass it on as an open-source patch.  The rules are pretty simple:
if you can certify the below:

Developer's Certificate of Origin 1.1

By making a contribution to this project, I certify that:

        (a) The contribution was created in whole or in part by me and I
            have the right to submit it under the open source license
            indicated in the file; or

        (b) The contribution is based upon previous work that, to the best
            of my knowledge, is covered under an appropriate open source
            license and I have the right under that license to submit that
            work with modifications, whether created in whole or in part
            by me, under the same open source license (unless I am
            permitted to submit under a different license), as indicated
            in the file; or

        (c) The contribution was provided directly to me by some other
            person who certified (a), (b) or (c) and I have not modified
            it.

        (d) I understand and agree that this project and the contribution
            are public and that a record of the contribution (including all
            personal information I submit with it, including my sign-off) is
            maintained indefinitely and may be redistributed consistent with
            this project or the open source license(s) involved.

then you just add a line saying::

	Signed-off-by: Random J Developer <random@developer.example.org>

using your real name (sorry, no pseudonyms or anonymous contributions.)

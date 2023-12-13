#!/bin/bash

set -e
set -o xtrace

export DEBIAN_FRONTEND=noninteractive
export GOPATH=/usr/local/go
export PATH=$PATH:/usr/local/go/bin
export LD_LIBRARY_PATH=/usr/local/lib64:/usr/local/lib:/usr/local/lib/x86_64-linux-gnu
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:/usr/local/lib64/pkgconfig:/usr/local/share/pkgconfig:/usr/local/lib/x86_64-linux-gnu/pkgconfig
export LDFLAGS="-L/usr/local/lib64 -L/usr/local/lib/ -L/usr/local/lib/x86_64-linux-gnu"
export CC="gcc-8"
export CXX="g++-8"
export CFLAGS="-g3"
export CXXFLAGS="-g3"
export GIT_DATE="2020-02-02"
export MESA_DEBUG=1

echo 'path-exclude=/usr/share/doc/*' > /etc/dpkg/dpkg.cfg.d/99-exclude-cruft
echo 'path-exclude=/usr/share/man/*' >> /etc/dpkg/dpkg.cfg.d/99-exclude-cruft
echo '#!/bin/sh' > /usr/sbin/policy-rc.d
echo 'exit 101' >> /usr/sbin/policy-rc.d
chmod +x /usr/sbin/policy-rc.d

echo deb-src http://deb.debian.org/debian buster main >> /etc/apt/sources.list
echo deb http://deb.debian.org/debian buster-backports main >> /etc/apt/sources.list
apt-get update
apt-get -y install ca-certificates
apt-get -y install --no-install-recommends \
      autoconf \
      busybox \
      ccache \
      check \
      clang-8 \
      cmake \
      dbus \
      g++-8 \
      gcc-8 \
      gdb \
      gdc-8 \
      git \
      golang-go \
      kbd \
      libcurl4-openssl-dev \
      libgbm-dev \
      libnss-systemd \
      libpng-dev \
      libxrandr-dev \
      libxvmc-dev \
      libsm-dev \
      libwayland-dev \
      libwayland-egl-backend-dev \
      linux-image-amd64 \
      lld-8 \
      llvm-8-dev \
      mesa-utils \
      meson \
      nasm \
      ninja-build \
      procps \
      psmisc \
      python-numpy \
      python-six \
      python-mako \
      python3-pip \
      python3-setuptools \
      python3-six \
      python3-wheel \
      qemu \
      spirv-headers \
      strace \
      systemd \
      systemd-coredump \
      time \
      waffle-utils \
      wget \
      xinit \
      xserver-xorg-core \
      xterm \
      xvfb \
      zlib1g-dev

apt-get -y build-dep --no-install-recommends \
      libdrm \
      mesa \
      piglit \
      check

apt-get -y remove valgrind libdrm-dev
rm -rf /var/lib/apt/lists/*

export KNOWN_GOOD_DRM=libdrm-2.4.104
mkdir /drm
pushd /drm
git clone --shallow-since="$GIT_DATE" https://gitlab.freedesktop.org/mesa/drm.git . && \
    git checkout ${KNOWN_GOOD_DRM} && \
    git log --oneline -n 1 && \
    mkdir -p build && \
    meson build/ && \
    meson configure build/ -Dprefix=/usr/local -Dlibdir=lib && \
    ninja -C build/ install >/dev/null && \
    rm -rf /drm
    [ "$?" = "0" ] || exit 1
popd

export KNOWN_GOOD_MESA=${KNOWN_GOOD_MESA:-30a393f4581079ced1ac05d6b74c7408fbe26f83}
echo $KNOWN_GOOD_MESA
export MESA_REPO=https://gitlab.freedesktop.org/mesa/mesa.git
echo $MESA_REPO
mkdir /mesa
pushd /mesa
git clone --shallow-since="$GIT_DATE" ${MESA_REPO} . && \
    git checkout ${KNOWN_GOOD_MESA} && \
    git log --oneline -n 1 && \
    mkdir -p build && \
    meson build/ && \
    meson configure build/ -Dprefix=/usr/local -Dplatforms=drm,x11,wayland,surfaceless -Ddri-drivers=i965 -Dgallium-drivers=swrast,virgl,radeonsi -Dbuildtype=debugoptimized -Dllvm=true -Dglx=dri -Dgallium-vdpau=false -Dgallium-va=false -Dvulkan-drivers=[] -Dlibdir=lib && \
    ninja -C build/ install >/dev/null && \
    rm -rf /mesa
    [ "$?" = "0" ] || exit 1
popd

export KNOWN_GOOD_EPOXY=${KNOWN_GOOD_EPOXY:-1.5.4}
mkdir /epoxy
pushd /epoxy
git clone --shallow-since="$GIT_DATE" https://github.com/anholt/libepoxy.git . && \
    git fetch --tags && 
    git checkout ${KNOWN_GOOD_EPOXY} && \
    git log --oneline -n 1 && \
    mkdir -p build && \
    meson build/ && \
    meson configure build/ -Dprefix=/usr/local -Dlibdir=lib && \
    ninja -C build/ install >/dev/null && \
    rm -rf /epoxy
    [ "$?" == "0" ] || exit 1
popd

export BATTERY_VERSION=0.1.23
mkdir /battery
pushd /battery
wget "https://github.com/VoltLang/Battery/releases/download/v${BATTERY_VERSION}/battery-${BATTERY_VERSION}-x86_64-linux.tar.gz" && \
    tar xzvf battery-${BATTERY_VERSION}-x86_64-linux.tar.gz && \
    rm battery-${BATTERY_VERSION}-x86_64-linux.tar.gz && \
    mv battery /usr/local/bin
    [ "$?" = "0" ] || exit 1
popd

mkdir /volt
pushd /volt
git clone --depth=1 https://github.com/VoltLang/Watt.git && \
    git clone --depth=1 https://github.com/VoltLang/Volta.git && \
    git clone --depth=1 https://github.com/Wallbraker/dEQP.git && \
    battery config --release --lto Volta Watt && \
    battery build && \
    battery config --cmd-volta Volta/volta Volta/rt Watt dEQP && \
    battery build && \
    cp dEQP/deqp /usr/local/bin && \
    rm -rf /volt
    [ "$?" = "0" ] || exit 1
popd

# To avoid this error:
# error: RPC failed; curl 56 GnuTLS recv error (-54): Error in the pull function.
git config --global http.postBuffer 1048576000

export KNOWN_GOOD_CTS=${KNOWN_GOOD_CTS:-524e5bcfba33d1b8dede4b4ec1ec33d24ccf8d2c}
mkdir /VK-GL-CTS
pushd /VK-GL-CTS
git clone --shallow-since="$GIT_DATE" https://github.com/KhronosGroup/VK-GL-CTS.git . && \
    git checkout ${KNOWN_GOOD_CTS} && \
    git log --oneline -n 1 && \
    python3 external/fetch_sources.py && \
    mkdir -p build && \
    cd build && \
    cmake -DDEQP_TARGET=x11_egl_glx -DCMAKE_BUILD_TYPE=Release .. && \
    make -j$(nproc) && \
    find . -name CMakeFiles | xargs rm -rf && \
    find . -name lib\*.a | xargs rm -rf
    [ "$?" = "0" ] || exit 1
popd

export KNOWN_GOOD_PIGLIT=${KNOWN_GOOD_PIGLIT:-08a92f4094c927276a20f608d7b3c5de2a72e9e7}
mkdir /piglit
pushd /piglit
git clone --shallow-since="$GIT_DATE" https://gitlab.freedesktop.org/mesa/piglit.git . && \
    git checkout ${KNOWN_GOOD_PIGLIT} && \
    git log --oneline -n 1 && \
    cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DCMAKE_BUILD_TYPE=Release . && \
    make -j$(nproc) install >/dev/null && \
    rm -rf /usr/local/lib/piglit/generated_tests/spec/arb_vertex_attrib_64bit && \
    rm -rf /usr/local/lib/piglit/generated_tests/spec/glsl-4.20 && \
    rm -rf /piglit
    [ "$?" = "0" ] || exit 1
popd



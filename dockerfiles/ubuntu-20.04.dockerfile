FROM docker.io/library/ubuntu:20.04 AS base
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
        autoconf \
        autopoint \
        gengetopt \
        build-essential \
        git \
        libtool \
        ninja-build \
		python3 \
		python3-pip \
        software-properties-common \
        wget \
        vim \
        pkg-config \
        make \
        bison \
        texinfo \
        help2man \
        gtk-doc-tools \
        valgrind \
        abigail-tools \
        cmake \
    && rm -rf /var/lib/apt/lists/* 

RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
        && apt-add-repository "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-12 main" \
        && apt-get update \
        && apt-get install -y llvm-12 llvm-12-dev llvm-12-tools clang-12 clang-format-12 clang-tidy-12 libclang-common-12-dev libclang-12-dev 



COPY ./ /GrayC/
WORKDIR /GrayC

ARG JOBS=$(nproc)

RUN \
  mkdir build \
  && cd build \
  && cmake -GNinja \
    -DCMAKE_EXE_LINKER_FLAGS='-fuse-ld=gold' \
    -DCMAKE_C_FLAGS='-Werror' \
    -DCMAKE_CXX_FLAGS='-Werror' \
    -DCMAKE_C_COMPILER=clang-12 \
    -DCMAKE_CXX_COMPILER=clang++-12 \
    -DLLVM_CONFIG_BINARY=$(which llvm-config-12) \
    ../ \
  && sh -c "ninja -j${JOBS}"

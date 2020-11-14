FROM ubuntu:latest

WORKDIR /usr/src

ARG GCC=gcc-8
ARG CLANG=clang-9

RUN apt update && apt install -y \
  make \
  less \
  $GCC \
  $CLANG

RUN ln -s /usr/bin/$GCC /usr/bin/gcc
RUN ln -s /usr/bin/$CLANG /usr/bin/clang

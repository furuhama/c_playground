FROM ubuntu:latest

WORKDIR /usr/src

ARG GCC=gcc-8
ARG CLANG=clang-9

RUN apt-get update && apt-get install -y \
  make \
  $GCC \
  $CLANG

RUN ln -s /usr/bin/$GCC /usr/bin/gcc
RUN ln -s /usr/bin/$CLANG /usr/bin/clang

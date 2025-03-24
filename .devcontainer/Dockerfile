FROM mcr.microsoft.com/devcontainers/base:bookworm
RUN apt-get update  \
    && apt-get dist-upgrade  \
    && apt-get -y install clang-19 cmake gdb  \
    && apt-get autoremove \
    && export CC=/usr/bin/clang-19

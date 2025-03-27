FROM mcr.microsoft.com/devcontainers/base:bookworm
RUN apt-get update  \
    && apt-get -y dist-upgrade  \
    && apt-get -y install clang-19 cmake gdb  \
    && apt-get autoremove \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/clang-19 30

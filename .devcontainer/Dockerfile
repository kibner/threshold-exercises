FROM mcr.microsoft.com/devcontainers/base:bookworm
# Qodana currently supports Clang 16.0.0 and LLVM 16.
# https://github.com/JetBrains/qodana-docker/blob/main/2024.3/base/cpp.Dockerfile
ARG CLANG="16"
RUN apt-get update \
    && apt-get -y upgrade \
    && apt-get -y dist-upgrade  \
    && apt-get -y install \
         clang-$CLANG \
         clang-tidy-$CLANG \
         clang-format-$CLANG \
         lld-$CLANG \
         cmake \
         gdb  \
    && apt-get autoclean \
    && apt-get autoremove \
    && apt-get autopurge \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/clang-$CLANG 30 \
    && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-$CLANG 30

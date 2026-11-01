# Build environment for SuperDrastic (build.sh): clang 22 + lld (apt.llvm.org, the compiler rocknixds.10 was built
# Stack protector on through a target config file, as Ubuntu's clang does by default (the shipped builds have it).
# with) and an aarch64 Debian trixie sysroot (glibc 2.41; the library needs <= 2.38).
FROM debian:trixie
RUN apt-get update && apt-get install -y --no-install-recommends ca-certificates curl gnupg python3 \
 && curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor -o /usr/share/keyrings/llvm.gpg \
 && echo "deb [signed-by=/usr/share/keyrings/llvm.gpg] http://apt.llvm.org/trixie/ llvm-toolchain-trixie-22 main" > /etc/apt/sources.list.d/llvm.list \
 && apt-get update && apt-get install -y --no-install-recommends clang-22 lld-22 llvm-22 \
 && for t in clang lld ld.lld llvm-strip llvm-readelf; do ln -sf /usr/bin/$t-22 /usr/local/bin/$t; done \
 && dpkg --add-architecture arm64 && apt-get update \
 && mkdir -p /tmp/debs /sysroot && cd /tmp/debs \
 && apt-get download libc6:arm64 libc6-dev:arm64 linux-libc-dev libdrm-dev:arm64 libdrm2:arm64 libgcc-14-dev:arm64 libgcc-s1:arm64 \
 && for d in *.deb; do dpkg-deb -x "$d" /sysroot; done && ln -s usr/lib /sysroot/lib \
 && rm -rf /tmp/debs /var/lib/apt/lists/*
RUN printf -- "-fstack-protector-strong\n" > /usr/lib/llvm-22/bin/aarch64-unknown-linux-gnu.cfg && cp /usr/lib/llvm-22/bin/aarch64-unknown-linux-gnu.cfg /usr/lib/llvm-22/bin/aarch64-linux-gnu.cfg
WORKDIR /src

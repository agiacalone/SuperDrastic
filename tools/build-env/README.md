# Build environment (agiacalone fork)

A Debian trixie container with the toolchain `build.sh` needs: clang and lld 22.1.8 from apt.llvm.org, and an
aarch64 trixie sysroot (glibc 2.41; the library needs 2.38 at most).

The shipped builds have the stack protector on, which Ubuntu's clang turns on by default. apt.llvm.org's clang
does not, so a target config file adds `-fstack-protector-strong`. Built this way, 0.5.0-beta.1-rocknixds.10
matches the shipped package apart from the compiler's name strings.

```sh
docker build -t superdrastic-build tools/build-env
docker run --rm -u "$(id -u):$(id -g)" -v "$PWD:/src" superdrastic-build \
    sh -c 'sh build.sh /sysroot shtest && sh package.sh'
```

`build/superdrastic-<version>-aarch64.tar.gz` is the package ROCKNIXDS ships in `dsflip/`. `build/shtest` runs one
shader on the handheld without DraStic: `OUT=1024x768 ./shtest <shader> 256 192 out.ppm`.

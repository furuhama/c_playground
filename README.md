## C playground

### Purpose

Just studying the c lnaguage and binary files.

All files are in `/src` directory, and markdown files are also in there, which contain my study logs and outputs.

### Compiler

#### on local machine

clang:

```
Apple LLVM version 10.0.0 (clang-1000.11.45.2)
Target: x86_64-apple-darwin17.7.0
Thread model: posix
```

gcc:

```
gcc version 8.2.0 (Homebrew GCC 8.2.0)
Target: x86_64-apple-darwin17.7.0
Thread model: posix
```

#### on docker image

clang:

```
clang version 9.0.0-2~ubuntu18.04.2 (tags/RELEASE_900/final)
Target: x86_64-pc-linux-gnu
Thread model: posix
```

gcc:

```
gcc version 8.4.0 (Ubuntu 8.4.0-1ubuntu1~18.04)
Target: x86_64-linux-gnu
Thread model: posix
```

### Docker usage

```
$ docker build -t c_playground .
$ docker run -v $(pwd):/usr/src --rm -it c_playground bash
```

### References

- [リンカ・ローダ実践開発テクニック](http://kozos.jp/books/linker_book.html)
- [The C++ Build Process Explained](https://github.com/green7ea/cpp-compilation)
- [Write your Own Virtual Machine](https://justinmeiners.github.io/lc3-vm/)

## C++ Build Process

### C Build Process

#### Header Trees

We can get headers used for compilation as a tree structure. (I am using Mac OSX.)

`-H` option enables us to see a header graph.

```
$ gcc-8 -H -O0 -std=c99 -g -c -o simple.o simple.c
. /usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.0.0/8.2.0/include-fixed/stdio.h
.. /usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.0.0/8.2.0/include/stdarg.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h
.... /usr/local/Cellar/gcc/8.2.0/lib/gcc/8/gcc/x86_64-apple-darwin18.0.0/8.2.0/include-fixed/AvailabilityInternal.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h
..... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/_types.h
..... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h
.... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h
..... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h
....... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h
...... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h
.. /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h
... /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_common.h
. add.h
```



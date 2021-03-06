## Analyze simple binary file

### Compile `hello.c`

#### nm

`nm` command shows us a symbol table.

Symbol table has the pairs of a symbol-name and a memory location address.

And if you want to know more details in this output,

you should use `info nm` or `man nm` commands.

```
$ nm src/linkers_and_loaders/hello
0000000100000000 T __mh_execute_header
0000000100000f6b T _main
                 U _puts
                 U dyld_stub_binder
```

#### objdump

```
$ objdump -p src/linkers_and_loaders/hello

hello:	file format Mach-O 64-bit x86-64

Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
MH_MAGIC_64  X86_64        ALL LIB64     EXECUTE    16       1264   NOUNDEFS DYLDLINK TWOLEVEL PIE
Load command 0
      cmd LC_SEGMENT_64
  cmdsize 72
  segname __PAGEZERO
   vmaddr 0x0000000000000000
   vmsize 0x0000000100000000
  fileoff 0
 filesize 0
  maxprot ---
 initprot ---
   nsects 0
    flags (none)
Load command 1
      cmd LC_SEGMENT_64
  cmdsize 472
  segname __TEXT
   vmaddr 0x0000000100000000
   vmsize 0x0000000000001000
  fileoff 0
 filesize 4096
  maxprot rwx
 initprot r-x
   nsects 5
    flags (none)
Section
  sectname __text
   segname __TEXT
      addr 0x0000000100000f6b
      size 0x0000000000000017
    offset 3947
     align 2^0 (1)
    reloff 0
    nreloc 0
      type S_REGULAR
attributes PURE_INSTRUCTIONS SOME_INSTRUCTIONS
 reserved1 0
 reserved2 0
Section
  sectname __stubs
   segname __TEXT
      addr 0x0000000100000f82
      size 0x0000000000000006
    offset 3970
     align 2^1 (2)
    reloff 0
    nreloc 0
      type S_SYMBOL_STUBS
attributes PURE_INSTRUCTIONS SOME_INSTRUCTIONS
 reserved1 0 (index into indirect symbol table)
 reserved2 6 (size of stubs)
Section
  sectname __stub_helper
   segname __TEXT
      addr 0x0000000100000f88
      size 0x000000000000001a
    offset 3976
     align 2^2 (4)
    reloff 0
    nreloc 0
      type S_REGULAR
attributes PURE_INSTRUCTIONS SOME_INSTRUCTIONS
 reserved1 0
 reserved2 0
Section
  sectname __cstring
   segname __TEXT
      addr 0x0000000100000fa2
      size 0x000000000000000e
    offset 4002
     align 2^0 (1)
    reloff 0
    nreloc 0
      type S_CSTRING_LITERALS
attributes (none)
 reserved1 0
 reserved2 0
Section
  sectname __eh_frame
   segname __TEXT
      addr 0x0000000100000fb0
      size 0x0000000000000050
    offset 4016
     align 2^3 (8)
    reloff 0
    nreloc 0
      type S_REGULAR
attributes (none)
 reserved1 0
 reserved2 0
Load command 2
      cmd LC_SEGMENT_64
  cmdsize 232
  segname __DATA
   vmaddr 0x0000000100001000
   vmsize 0x0000000000001000
  fileoff 4096
 filesize 4096
  maxprot rwx
 initprot rw-
   nsects 2
    flags (none)
Section
  sectname __nl_symbol_ptr
   segname __DATA
      addr 0x0000000100001000
      size 0x0000000000000010
    offset 4096
     align 2^3 (8)
    reloff 0
    nreloc 0
      type S_NON_LAZY_SYMBOL_POINTERS
attributes (none)
 reserved1 1 (index into indirect symbol table)
 reserved2 0
Section
  sectname __la_symbol_ptr
   segname __DATA
      addr 0x0000000100001010
      size 0x0000000000000008
    offset 4112
     align 2^3 (8)
    reloff 0
    nreloc 0
      type S_LAZY_SYMBOL_POINTERS
attributes (none)
 reserved1 3 (index into indirect symbol table)
 reserved2 0
Load command 3
      cmd LC_SEGMENT_64
  cmdsize 72
  segname __LINKEDIT
   vmaddr 0x0000000100002000
   vmsize 0x0000000000001000
  fileoff 8192
 filesize 240
  maxprot rwx
 initprot r--
   nsects 0
    flags (none)
Load command 4
            cmd LC_DYLD_INFO_ONLY
        cmdsize 48
     rebase_off 8192
    rebase_size 8
       bind_off 8200
      bind_size 24
  weak_bind_off 0
 weak_bind_size 0
  lazy_bind_off 8224
 lazy_bind_size 16
     export_off 8240
    export_size 48
Load command 5
     cmd LC_SYMTAB
 cmdsize 24
  symoff 8296
   nsyms 4
  stroff 8376
 strsize 56
Load command 6
            cmd LC_DYSYMTAB
        cmdsize 80
      ilocalsym 0
      nlocalsym 0
     iextdefsym 0
     nextdefsym 2
      iundefsym 2
      nundefsym 2
         tocoff 0
           ntoc 0
      modtaboff 0
        nmodtab 0
   extrefsymoff 0
    nextrefsyms 0
 indirectsymoff 8360
  nindirectsyms 4
      extreloff 0
        nextrel 0
      locreloff 0
        nlocrel 0
Load command 7
          cmd LC_LOAD_DYLINKER
      cmdsize 32
         name /usr/lib/dyld (offset 12)
Load command 8
     cmd LC_UUID
 cmdsize 24
    uuid 82BFD7FA-1280-314F-9A44-536383F01189
Load command 9
      cmd LC_VERSION_MIN_MACOSX
  cmdsize 16
  version 10.13
      sdk 10.13
Load command 10
      cmd LC_SOURCE_VERSION
  cmdsize 16
  version 0.0
Load command 11
       cmd LC_MAIN
   cmdsize 24
  entryoff 3947
 stacksize 0
Load command 12
          cmd LC_LOAD_DYLIB
      cmdsize 56
         name /usr/lib/libSystem.B.dylib (offset 24)
   time stamp 2 Thu Jan  1 09:00:02 1970
      current version 1252.50.4
compatibility version 1.0.0
Load command 13
          cmd LC_LOAD_DYLIB
      cmdsize 64
         name /usr/local/lib/gcc/8/libgcc_s.1.dylib (offset 24)
   time stamp 2 Thu Jan  1 09:00:02 1970
      current version 1.0.0
compatibility version 1.0.0
Load command 14
      cmd LC_FUNCTION_STARTS
  cmdsize 16
  dataoff 8288
 datasize 8
Load command 15
      cmd LC_DATA_IN_CODE
  cmdsize 16
  dataoff 8296
 datasize 0
```

### Compile `value_definitions.c` and create object file (compile with `-c` option)

#### nm

`nm` command searches a symbol table in the target file.

```
$ nm src/linkers_and_loaders/value_definitions.o
0000000000000038 s EH_frame1
0000000000000001 C _c0
0000000000000010 D _c1
0000000000000004 C _ci0
0000000000000034 S _ci1
0000000000000008 C _cp0
0000000000000018 D _cp1
0000000000000000 T _fn
0000000000000004 C _i0
0000000000000020 D _i1
0000000000000088 s _si0
0000000000000024 d _si1
0000000000000028 s lC0
```

### Compile `exec_values.c` with `value_definitions.o`

`$ gcc-8 src/linkers_and_loaders/exec_values.c src/linkers_and_loaders/value_definitions.o -o src/linkers_and_loaders/exec_values`

After compile and link step, the binary file even has its symbol table.

And you can see the table with `nm` command.

#### nm

```
$ nm src/linkers_and_loaders/exec_values
0000000100000000 T __mh_execute_header
0000000100001048 S _c0
0000000100001020 D _c1
000000010000104c S _ci0
0000000100000f64 S _ci1
0000000100001050 S _cp0
0000000100001028 D _cp1
                 U _exit
0000000100000e40 T _fn
0000000100001058 S _i0
000000010000103c D _i1
0000000100000ce9 T _main
                 U _printf
0000000100001044 s _si0
0000000100001040 d _si1
0000000100001030 D _str
                 U dyld_stub_binder
```

#### objdump -h

```
$ objdump -h src/linkers_and_loaders/exec_values

src/linkers_and_loaders/exec_values:	file format Mach-O 64-bit x86-64

Sections:
Idx Name          Size      Address          Type
  0 __text        00000167 0000000100000ce9 TEXT
  1 __stubs       0000000c 0000000100000e50 TEXT
  2 __stub_helper 00000024 0000000100000e5c TEXT
  3 __cstring     000000e1 0000000100000e80 DATA
  4 __const       00000004 0000000100000f64 DATA
  5 __eh_frame    00000098 0000000100000f68 DATA
  6 __nl_symbol_ptr 00000010 0000000100001000 DATA
  7 __la_symbol_ptr 00000010 0000000100001010 DATA
  8 __data        00000024 0000000100001020 DATA
  9 __bss2        00000004 0000000100001044 BSS
 10 __common      00000014 0000000100001048 BSS
 ```

### Strip the symbol table

After create binary executable file,

you can remove the symbol table.

Because, it is just for link step and no longer needed.

`$ gcc-8 gcc-8 src/linkers_and_loaders/exec_values.c src/linkers_and_loaders/value_definitions.o -o src/linkers_and_loaders/exec_values_without_symbol_table`

`$ strip src/linkers_and_loaders/exec_values_without_symbol_table`

Try `ls -l` command,

the size of that does not have a symbol table is

lower than that with a symbol table.

```
$ ls -l src/linkers_and_loaders{exec_values,exec_values_without_symbol_table}
-rwxr-xr-x 1 furuhama 8832 10  8 16:37 src/linkers_and_loaders/exec_values
-rwxr-xr-x 1 furuhama 8592 10  8 17:33 src/linkers_and_loaders/exec_values_without_symbol_table
```

With `nm` command, you can know the table was deleted.

```
$ nm src/linkers_and_loaders/exec_values_without_symbol_table
0000000100000000 T __mh_execute_header
                 U _exit
                 U _printf
                 U dyld_stub_binder
```

## Assembly

Compile assembly file to object file with assembler. (.s -> .o)

```
$ arm-none-eabi-as asm/arm/hello_arm.s -o obj/arm/hello_arm.o
```

Link libraries with object file and create an elf-format binary file. (.o -> .elf)

```
$ arm-none-eabi-ld obj/arm/hello_arm.o -Ttext 0x00010000 -o bin/arm/hello_arm.elf
```

Set data into execution file by objcopy command. (.elf -> .bin)

```
$ arm-none-eabi-objcopy -O binary bin/arm/hello_arm.elf bin/arm/hello_arm.bin
```

And, run binary file on an ARM architecture qemu virtual machine.

```
$ qemu-system-arm -M versatilepb -m 128M -nographic -kernel bin/arm/hello_arm.bin -serial mon:stdio
hello
QEMU: Terminated # press `<C-a> x` and exit qemu
```

ref: [karino2/c-lesson](https://github.com/karino2/c-lesson/blob/master/arm_asm.md)

# Bytecode Interpreter VM in C
Bytecode interpreter virtual machine in C for any architecture. This implementation is a generic VM with a little effort one can virtualize any architecture.


## Description:
-In this file there is only one C file, vm.c.

-vm.c is my VM implementation.

-Written in C without using any third-party libraries.

## Build/Run:
-I use GCC 5.4.0 to compile my implementation on a Ubuntu 16.04 LTS machine.

-To use it compile the C file first. Then make an executable.

-After these, call the executable while passing name of the image you would like to run as a argument.

Ex:

```bash
$ cc -c vm.c
$ cc vm.c -o vm
$ ./vm vm.bin
```

Thank you.

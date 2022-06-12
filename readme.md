# StackC

Stack manager library in C

# Getting started

* Include the header file `"stackC.h"` in your source code

```C
    #include "stackC.h"
```

* When you are about to compile

    - in an IDE, find and add to the linker the file `libstackC.a`

    - with gcc, if `libstackC.a` is in the current directory (otherwise, write the whole path)

```
    gcc -Wall -O2 main.c -s libstackC.a
```

# Use and Examples

You will find in the header file how to use each function. 
Go to [example directory](example) to see usage examples

# Compilation of the library

If you to compile again the library, delete `libstackC.a` and run the following command

    gcc -Wall -O2  -c stackC.c -o stackC.o
    ar -r -s libstackC.a stackC.o

# License

Project under [MIT LICENSE](LICENSE-MIT)
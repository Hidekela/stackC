# StackC

Stack manager library in C

# Get started

* Define S_DATA_TYPE as a variable type that you want to store in the stack:

    - before including ``"stackC.h"``

        #define S_DATA_TYPE int // Or something else

    - OR directly in the file ``"stackC.h"``

        #ifndef S_DATA_TYPE
        #define S_DATA_TYPE int // Or something else
        #endif //S_DATA_TYPE

* Define S_DATA_LENGTH as the legth of the data if it is an array (1 if not):

    - before including ``"stackC.h"``

        #define S_DATA_LENGTH 1 // Or something else

    - OR directly in the file ``"stackC.h"``

        #ifndef S_DATA_LENGTH
        #define S_DATA_LENGTH 1 // Or something else
        #endif //S_DATA_LENGTH

* Include the header file ``"stackC.h"`` in your source code
    
    #include "stackC.h"

* When you are about to compile

    - in an IDE, find and add to the linker the file ``libstackC.a``

    - with gcc, if ``libstackC.a`` is in the current directory (otherwise, write the whole path)

        gcc -Wall -O2 main.c -s libstackC.a

# Use and Example

Go to [example directory](example)

# Compilation of the library

If you to compile again the library, delete ``libstackC.a`` and run the following command

    gcc -Wall -O2  -c stackC.c -o stackC.o
    ar -r -s libstackC.a stackC.o

# Limitation

The type of data stored in the stack cannot be changed throughout the program. If you want to have another stack with a different data type, you have to implement the stack yourself or migrate to another language such as C++, python,... which manages stacks.

# License

Project under [MIT LICENSE](LICENSE-MIT)
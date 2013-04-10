## Compile the test library and test program

     # Compile, create and inspect the library.
     gcc -fPIC -fno-common -dynamic -c encrypt.c -o encrypt.o
     libtool -lc -lcrypto -dynamic -o libencrypt.dylib encrypt.o
     otool -L libencrypt.dylib
     file libencrypt.dylib
     nm libencrypt.dylib

     # Compile, link and inspect the test program.
     gcc -I. -L. -lencrypt digest_example.c -o digest_example
     otool -L digest_example
     file digest_example

## Compiler details

    gcc --version
    which gcc
    gcc --print-prog-name=ld


## Resources

https://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/10.6/man1/libtool.1.html
http://www.xappsoftware.com/wordpress/2012/12/20/how-to-create-a-shared-library-on-mac-os-x-using-gcc/

## Learning

### C

* Pointers: type delegated to target
* Operators / functions: sizeof, size_t
* Signedness: size_t
* Memory: stack vs. heap
* String literals
* Function locals: passing in pointers to objects (buffers, ints, etc.)
* Arrays: pointer equivalence, strings as arrays and \0 termination
* Define vs. const
* Makefiles

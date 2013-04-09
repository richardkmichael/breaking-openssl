# Compile the test library and test program

     # Compile the library.
     gcc -fPIC -fno-common -dynamic -c encrypt.c -o encrypt.o
     libtool -lc -lcrypto -dynamic -o libencrypt.dylib encrypt.o

     # Inspect the linking and file type.
     otool -L libencrypt.dylib
     file libencrypt.dylib

     # Compile and link the test program.
     gcc -I. -L. -lencrypt digest_example.c -o digest_example

     # Inspect the linking and file type.
     otool -L digest_example
     file digest_example

## Compiler details

    gcc --version
    which gcc
    gcc --print-prog-name=ld


## Resources

https://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/10.6/man1/libtool.1.html

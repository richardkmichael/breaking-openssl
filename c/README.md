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

    gcc -dynamiclib -Wl,-headerpad_max_install_names,-undefined,dynamic_lookup,-compatibility_version,1.0,-current_version,1.0,-install_name,/usr/local/lib/libfoo.1.dylib
 -o libfoo.1.dylib $(OBJ)


## Resources

### C
https://developer.apple.com/library/mac/#documentation/Darwin/Reference/ManPages/10.6/man1/libtool.1.html
http://www.xappsoftware.com/wordpress/2012/12/20/how-to-create-a-shared-library-on-mac-os-x-using-gcc/
http://www.gnu.org/software/libc/manual/html_node/String-Length.html

### Ruby and C
http://www.ruby-doc.org/docs/ProgrammingRuby/html/ext_ruby.html

## Learning

### C

* Pointers: type delegated to target
* Operators / functions: sizeof, size_t
* Signedness: size_t, casting arrays of unsigned/signed char*
* Memory: stack vs. heap
* String literals
* Function locals: passing in pointers to objects (buffers, ints, etc.)
* Arrays: pointer equivalence, strings as arrays and \0 termination
* Define vs. const
* Makefiles
* C90 declarations and code
* gdb

### Ruby

* StringValue2
* Check_Type()
* gdb call rb_eval_string( .. );


default: encrypt digest_example

new-ssl: encrypt-new-ssl digest_example

encrypt:
	gcc -fPIC -fno-common -ggdb -O0 -dynamic -c encrypt.c -o encrypt.o
	libtool -lc -lcrypto -dynamic -o libencrypt.dylib encrypt.o

encrypt-new-ssl:
	gcc -I/opt/local/include -fPIC -fno-common -ggdb -O0 -dynamic -c encrypt.c -o encrypt.o
	libtool -L/opt/local/lib -lc -lcrypto -dynamic -o libencrypt.dylib encrypt.o

digest_example:
	gcc -I. -L. -lencrypt -ggdb -O0 digest_example.c -o digest_example

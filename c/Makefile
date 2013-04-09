default: encrypt digester

encrypt:
	gcc -fPIC -fno-common -dynamic -c encrypt.c -o encrypt.o
	libtool -lc -lcrypto -dynamic -o libencrypt.dylib encrypt.o

digester:
	gcc -I. -L. -lencrypt digest_example.c -o digest_example

#include <stdio.h>;
#include <stdlib.h>;

#include <openssl/sha.h>;

// char *encrypt_string(char *plaintext_string, char *buffer[])
char *encrypt_string(const char *plaintext_string)
{

  int plaintext_length = sizeof plaintext_string;
  // char *encrypted_string_ptr = malloc(20);
  char *encrypted_string_ptr = malloc(SHA_DIGEST_LENGTH);

  // If encrypted_string_ptr is NULL, SHA1 will return a static array. We could just return that.
  SHA1(plaintext_string, plaintext_length, encrypted_string_ptr);

  // static char encrypted_string[20] = *encrypted_string_ptr;
  return encrypted_string_ptr;
}

int main()
{
  char default_string[] = "This is the default string.";
  char *encrypted_string_ptr = encrypt_string(default_string);
  printf("Encrypted string: \"%s\"\n", encrypted_string);
  int i;
  for(i = 0; i < sizeof encrypted_string; i++) {
    // Convert integer to 0-padded 2-digit unsigned hexidecimal.
    printf("%02x", encrypted_string[i]);
  }
  printf("Size of encrypted_string: %ld\n", sizeof *encrypted_string);
  return 0;
}


/*
*/

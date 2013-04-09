#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// int main(int argc, char *argv[])
// int main()
// void encrypt(char message[])
char *encrypt(char message[], int *md_value_length)
{
  // Load the available digests.
  OpenSSL_add_all_digests();

  // Set the digest type.
  const EVP_MD *evp_md_ptr;
  evp_md_ptr = EVP_get_digestbyname("sha256");

  // Create a digest context.
  EVP_MD_CTX *md_ctx_ptr;
  md_ctx_ptr = EVP_MD_CTX_create();

  // Initialize the context with the digest, and NULL (?).
  EVP_DigestInit_ex(md_ctx_ptr, evp_md_ptr, NULL);

  // Update the context with the message and message length.
  EVP_DigestUpdate(md_ctx_ptr, message, strlen(message));

  // A char array to hold the digest.
  // unsigned char md_value[EVP_MAX_MD_SIZE];
  char *md_value = malloc(EVP_MAX_MD_SIZE);
  // int md_value_length;

  // TODO: We cannot return md_value itself: we'd return a pointer, but lose the contents (outside
  // this function).  Solutions: put the md_value on the heap with malloc, pass a size pointer into
  // which we can write the size; or, NUL terminate md_value.

  // Compute then store the digest and digest length our variables.
  EVP_DigestFinal_ex(md_ctx_ptr, md_value, md_value_length);

  // Free the context.
  EVP_MD_CTX_destroy(md_ctx_ptr);

  return md_value;
}

int main()
{
  // A test message.
  char message[] = "Test Message\n";
  char *encrypted_message;
  int encrypted_message_length;
  encrypted_message = encrypt(message, &encrypted_message_length);

  // Print out the encrypted message as 0-padded 2-digit unsigned hexidecimal.
  int i;
  for(i = 0; i < encrypted_message_length; i++) {
    printf("%02x", encrypted_message[i]);
  }
  printf("\n");

  return 0;
}

#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// int main(int argc, char *argv[])
// int main()
// void encrypt(char message[])
unsigned char *encrypt(char message[], unsigned int *md_value_length)
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
  unsigned char *md_value = (unsigned char *) malloc(EVP_MAX_MD_SIZE);
  // int md_value_length;

  // TODO: We cannot return md_value itself: we'd return a pointer, but lose the contents (outside
  // this function).  Solutions: put the md_value on the heap with malloc, pass a size pointer into
  // which we can write the size; or, NUL terminate md_value.

  // Compute then store the digest and digest length our variables.
  // TODO: "pointer targets in passing argument 3 of ‘EVP_DigestFinal_ex’ differ in signedness"
  EVP_DigestFinal_ex(md_ctx_ptr, md_value, md_value_length);

  // Free the context.
  EVP_MD_CTX_destroy(md_ctx_ptr);

  return md_value;
}

int main(int argc, char* argv[])
{

  // The message to encrypt.
  char *message;

  // Permit a message from the command line; otherwise, use a default.
  if (argv[1]) {
    message = argv[1];
  } else {
    message = "Test message."; // Character array is like a pointer.
  }

  unsigned int encrypted_message_length;

  unsigned char *encrypted_message;
  encrypted_message = encrypt(message, &encrypted_message_length);

  // Print out the encrypted message as 0-padded 2-digit unsigned hexidecimal.
  int i;
  for(i = 0; i < encrypted_message_length; i++) {
    printf("%02x", encrypted_message[i]);
  }
  printf("\n");

  return 0;
}

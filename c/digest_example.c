#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

unsigned char *encrypt(char message[], unsigned int *md_value_length_ptr)
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
  unsigned char *md_value_ptr = (unsigned char *) malloc(EVP_MAX_MD_SIZE);
  // int md_value_length;

  // Compute then store the digest and digest length our variables.
  EVP_DigestFinal_ex(md_ctx_ptr, md_value_ptr, md_value_length_ptr);

  // Free the context.
  EVP_MD_CTX_destroy(md_ctx_ptr);

  // Return a pointer to the encrypted message.
  return md_value_ptr;
}

int main(int argc, char* argv[])
{
  // The message to encrypt.
  char *message;

  // Permit a message from the command line; otherwise, use a default.
  if (argv[1]) {
    message = argv[1];
  } else {
    message = "Test message."; // Character array is essentially a pointer.
  }

  // The encrypt function will fill in the message length.  Used to iterate later.
  unsigned int encrypted_message_length_ptr;

  // A pointer to the encrypted message.
  unsigned char *encrypted_message_ptr = encrypt(message, &encrypted_message_length_ptr);

  // Print out the encrypted message as 0-padded 2-digit unsigned hexidecimal.
  int i;
  for(i = 0; i < encrypted_message_length_ptr; i++) {
    printf("%02x", encrypted_message_ptr[i]);  // Pointer / array equivalence.
  }
  printf("\n");

  return 0;
}

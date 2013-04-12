#include <string.h>
#include <openssl/evp.h>

char *encrypt(char message[], unsigned int *md_value_length_ptr)
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

  // Because rb_str_new2() wants a signed char pointer, cast the unsigned pointer to the encrypted
  // message to a signed pointer and return.  Characters in the array are in the SHA-2 character set
  // {0-9A-F}, which are all 0 < e < 127 (ASCII).
  return (char *) md_value_ptr; }

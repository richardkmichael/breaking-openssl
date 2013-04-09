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

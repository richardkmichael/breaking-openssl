#include <stdio.h>
#include <encrypt.h>

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
  unsigned char *encrypted_message_ptr = (unsigned char *)encrypt(message, &encrypted_message_length_ptr);

  // Print out the encrypted message as 0-padded 2-digit unsigned hexidecimal.
  int i;
  for(i = 0; i < encrypted_message_length_ptr; i++) {
    // printf("%02x", encrypted_message_ptr[i]);  // Pointer / array equivalence.
    printf("%02x", encrypted_message_ptr[i]);  // Pointer / array equivalence.
  }
  printf("\n");

  return 0;
}

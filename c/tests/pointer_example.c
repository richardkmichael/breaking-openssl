#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *char_pointer;
  int *int_pointer;

  printf("char_pointer as pointer: %p\n", char_pointer);
  printf("int_pointer as pointer: %p\n", int_pointer);

  int my_int_1 = 10;
  int my_int_2 = 20;
  int *int_pointer_1;
  int *int_pointer_2;
  int_pointer_1 = &my_int_1;
  int_pointer_2 = &my_int_2;

  printf("my_int_1 is: %d\n", my_int_1);
  printf("int_pointer_1 points to: %d\n", *int_pointer_1);

  printf("my_int_2 is: %d\n", my_int_2);
  printf("int_pointer_2 points to: %d\n", *int_pointer_2);

  int_pointer_1 = int_pointer_2;

  printf("my_int_1 is: %d\n", my_int_1);
  printf("int_pointer_1 is: %d\n", *int_pointer_1);

  *int_pointer_2 = 6;
  printf("my_int_1 is: %d\n", my_int_1);

  char *my_message_ptr = (char *) malloc(50);

  printf("sizeof my_message_ptr: %ld\n", sizeof my_message_ptr);
  printf("sizeof &my_message_ptr: %ld\n", sizeof &my_message_ptr);
  printf("sizeof *my_message_ptr: %ld\n", sizeof *my_message_ptr);

  int i;
  for(i = 0; i < 50; i++) {
    // Convert integer to 0-padded 2-digit unsigned hexidecimal.
    printf("%02x", my_message_ptr[i]);
  }

}

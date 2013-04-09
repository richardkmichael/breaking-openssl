#include <stdio.h>;

int main(int argc, char *argv[])
{

  // Types of arrays.
  int areas[] = {10, 12, 13, 14, 15};

  printf("On this system:\n");
  printf("\tThe size of an int is: %ld\n", sizeof(int));
  printf("\tThe size of int area[] is: %ld\n", sizeof(areas));
  printf("\tThe number of ints in the array area[] is: %ld\n",
    sizeof(areas) / sizeof(int));
  printf("\tThe first element of areas[] is: %d, the second is %d\n",
      areas[0], areas[1]);

  char name[] = "Richard";

  printf("On this system:\n");
  printf("\tThe size of a char is: %ld\n", sizeof(char));
  printf("\tThe size of char name[] is: %ld\n", sizeof(name));
  printf("\tThe number of chars in the array name[] is: %ld\n",
      sizeof(name) / sizeof(char));
  printf("\tThe first char in name[] is: %c\n", name[0]);
  printf("\tThe last printable char in name[] is: %c\n", name[6]);
  printf("\tAn out of bounds (100) char in name[] is: %c\n", name[100]);
  if (name[7] == '\0')
  {
    printf("\tThe last char in name[] is NUL.\n");
  }
  printf("\tThe array name[] is: %s\n", name);

  // Printf uses the \0 null byte as the end of the string.
  char fullname[] = { 'R', 'i', 'c', 'h', '\0', 'a', 'r', 'd' };

  printf("\tThe size of char fullname[] is: %ld\n", sizeof(fullname));
  printf("\tThe number of chars in the array fullname[] is: %ld\n",
      sizeof(fullname) / sizeof(char));
  printf("\tThe array fullname[] is: %s\n", fullname);


  // Manual string construction.
  char short_name[] = { 'a', 'b', 'c', 'd', '\0' };
  printf("Short name: %s\n", short_name);
  printf("Short name sizeof: %ld\n", sizeof(short_name));

  // Automatic null termination.
  char short_name_two[] = "abcd";
  printf("Short name: %s\n", short_name_two);
  printf("Short name sizeof: %ld\n", sizeof(short_name_two));

  // Pointer to a string?
  char *short_name_three = "abcd";
  printf("Short name: %s\n", short_name_three);
  printf("Short name sizeof: %ld\n", sizeof(short_name_three));
  printf("Short name pointer: %c, %c, %c, %c, %c, %c, %c, %c\n",
      short_name_three[0],
      short_name_three[1],
      short_name_three[2],
      short_name_three[3],
      short_name_three[4],
      short_name_three[5],
      short_name_three[6],
      short_name_three[7]);

  return 0;
}

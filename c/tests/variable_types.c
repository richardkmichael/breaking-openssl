#include <stdio.h>;

int main(int argc, char *argv[])
{

  int distance = 100;
  float power = 2.345f;
  double super_power = 56789.4532;
  char initial = 'K';
  char first_name[] = "Richard";
  char last_name[] = "Michael";

  printf("You are %d miles away.\n", distance);
  printf("You have %f levels of power.\n", power);
  printf("You have %f awesome super powers.\n", super_power);
  printf("I have an initial %c.\n", initial);
  printf("I have a first name %s.\n", first_name);
  printf("I have a last name %s.\n", last_name);
  printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

  // Intentionally cause a segfault to learn about valgrind.
  // printf("My whole name is %s %c. %s.\n", initial, first_name, last_name);

  char *first_name_ptr = &first_name[0];
  int first_name_length = sizeof *first_name_ptr;
  printf("first_name: %s\n", first_name);
  printf("first_name length via pointer dereference: %d\n", first_name_length);

  return 0;

}

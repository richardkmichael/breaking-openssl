#include <encrypter.h>

// TODO: How to namespace functions in C; libencrypt has an encrypt() function too.
// static VALUE encrypter_encrypt(VALUE rb_string)
static VALUE encrypter_encrypt()
{
  // This will raise a TypeError exception; otherwise use "TYPE(rb_string) == T_STRING;".
  // Check_Type(rb_string, T_STRING); // T_STRING is an int and defined in ruby.h
  // Cast a VALUE to proper Ruby type to access the structure.
  // RSTRING(rb_string)->len;

  // This should call libencrypt encrypt().
  return rb_str_new2("Encrypted message.");
}

VALUE mEncrypter;

void Init_encrypter()
{
  mEncrypter = rb_define_module("Encrypter");
  // Nice convention: prefix the C function name with the letter of the module, "e_encrypt".
  // rb_define_singleton_method(mEncrypter, "encrypt", encrypter_encrypt, 1);
  rb_define_singleton_method(mEncrypter, "encrypt", encrypter_encrypt, 0);
}

#include <encrypter.h>

// TODO: How to namespace functions in C; libencrypt has an encrypt() function too.
static VALUE encrypter_encrypt(VALUE self, VALUE rb_string_plaintext)
// static VALUE encrypter_encrypt()
{

  // C90 mandates all declarations appear before code.
  unsigned int encrypted_string_length_ptr;
  char *plaintext_string, *encrypted_string;
  VALUE rb_encrypted_string;

  // This will raise a TypeError exception; otherwise use "TYPE(rb_string) == T_STRING;".
  // T_STRING is an int and defined in ruby.h
  // warning: ISO C90 forbids mixed declarations and code
  Check_Type(rb_string_plaintext, T_STRING);

  // Cast a VALUE to proper Ruby type to access the structure.
  // RSTRING(rb_string)->len;

  // STR2CSTR was removed in Ruby 1.9.1.
  // StringValuePtr is not \0 terminated, use StringValueCStr (despite being slower) because encrypt
  // uses strlen() which requires \0 termination.
  // plaintext_string = StringValueCStr(rb_string_plaintext);
  plaintext_string = RSTRING_PTR(rb_string_plaintext);
  printf("DEBUG: plaintext_string: %s\n", plaintext_string);

  encrypted_string = encrypt(plaintext_string, &encrypted_string_length_ptr);
  printf("DEBUG: encrypted_string: %s\n", encrypted_string);

  // return rb_str_new2("Encrypted message.");
  rb_encrypted_string = rb_str_new2(encrypted_string); // rb_str_new2 initializes from a signed char*.
  return rb_encrypted_string;
}

VALUE mEncrypter;

void Init_encrypter()
{
  mEncrypter = rb_define_module("Encrypter");

  // FIXME: Nice convention: prefix the C function name with the letter of the module, "e_encrypt".
  rb_define_singleton_method(mEncrypter, "encrypt", encrypter_encrypt, 1);
}

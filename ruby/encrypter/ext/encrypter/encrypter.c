#include <ruby.h>

static VALUE encrypt(VALUE module)
{
  return rb_str_new2("Encrypted message.");
}

void Init_encrypter()
{
  VALUE mEncrypter = rb_define_module("Encrypter");
  rb_define_singleton_method(mEncrypter, "encrypt", encrypt, 0);
}

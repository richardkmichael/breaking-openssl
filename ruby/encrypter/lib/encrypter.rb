require "encrypter/version"

# I don't know how dyld works, but this has no effect; export in the shell instead.
# dir_with_libencrypt = File.expand_path('../../c', File.dirname(__FILE__))
# ENV['DYLD_LIBRARY_PATH'] = dir_with_libencrypt

# Require our C extension "encrypter/encrypter.bundle".
require "encrypter/encrypter"

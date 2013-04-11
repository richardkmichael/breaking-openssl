require 'mkmf'

# TODO: This changes all the CFLAGS, as:
# $ diff Makefile*
# < CFLAGS   = -fno-common $(cflags)  -fno-common -pipe $(ARCH_FLAG)
# ---
# > CFLAGS   = -fno-common -Wall $(ARCH_FLAG)

# with_cflags '-Wall' do
#   create_makefile 'encrypter'
# end

# The test C library lives several directories up, beside this project.
LIBRARY_DIRS = [ File.join(RbConfig::CONFIG['srcdir'], '../../../../c') ]
HEADER_DIRS  = [ File.join(RbConfig::CONFIG['srcdir'], '../../../../c') ]

dir_config('encrypt', HEADER_DIRS, LIBRARY_DIRS)

unless find_header('encrypt.h')
  abort "libencrypt headers not found in:\n" + HEADER_DIRS.join('\n')
end

unless find_library('encrypt', 'encrypt')
  abort "libencrypt shared library not found in:\n" + LIBRARY_DIRS.join('\n')
end

# TODO: create_makefile 'encrypter/encrypter' # ==> @tenderlove's convention. Why? Creates install
# point in a sub-directory.
create_makefile 'encrypter/encrypter'


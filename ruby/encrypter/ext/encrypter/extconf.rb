require 'mkmf'

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

# @tenderlove's convention. Creates install point in a sub-directory to group both Ruby and C
# library components under lib/encrypter.
# create_makefile 'encrypter/encrypter'

# TODO: This changes all the CFLAGS, as:
# $ diff Makefile*
# < CFLAGS   = -fno-common $(cflags)  -fno-common -pipe $(ARCH_FLAG)
# ---
# > CFLAGS   = -fno-common -Wall $(ARCH_FLAG)

# -ggdb debugging is always enabled, but this turns off optimizations which are -O3 by default.
with_cflags '-O0 $(debugflags) $(warnflags) -pipe' do
  create_makefile 'encrypter/encrypter'
end

# sleep 1000;

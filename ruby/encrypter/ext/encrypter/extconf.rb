require 'mkmf'

# TODO: This changes all the CFLAGS, as:
# $ diff Makefile*
# < CFLAGS   = -fno-common $(cflags)  -fno-common -pipe $(ARCH_FLAG)
# ---
# > CFLAGS   = -fno-common -Wall $(ARCH_FLAG)

# with_cflags '-Wall' do
#   create_makefile 'encrypter'
# end

# TODO: create_makefile 'encrypter/encrypter' # ==> @tenderlove's convention. Why? Creates install
# point in a sub-directory.
create_makefile 'encrypter'

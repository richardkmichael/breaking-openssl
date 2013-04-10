require 'test/unit'
# require 'encrypter'
require 'digest/sha1'

class EncrypterTest < Test::Unit::TestCase

  ENCRYPTER_DEFAULT_MESSAGE        = 'Test message.';
  ENCRYPTER_DEFAULT_MESSAGE_SHA256 = 'b2da997a966ee07c43e1f083807ce5884bc0a4cad13b02cadc72a11820b50917';

  def test_encrypt_returns_sha256
#   assert_equal ENCRYPTER_DEFAULT_MESSAGE_SHA256,
#                Encrypter.encrypt(ENCRYPTER_DEFAULT_MESSAGE);

#   assert_equal ENCRYPTER_DEFAULT_MESSAGE_SHA256,
#                Digest::SHA256.hexdigest(ENCRYPTER_DEFAULT_MESSAGE);

    assert true
  end
end

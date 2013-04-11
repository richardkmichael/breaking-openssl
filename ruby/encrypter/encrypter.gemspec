# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'encrypter/version'

Gem::Specification.new do |spec|
  spec.name          = "encrypter"
  spec.version       = Encrypter::VERSION
  spec.authors       = ['Richard Michael']
  spec.email         = ['rmichael@edgeofthenet.org']
  spec.description   = %q{A tiny test extension around a tiny C library.}
  spec.summary       = %q{A tiny test extension around a tiny C library.}
  spec.homepage      = ''
  spec.license       = 'MIT'

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ['lib']
  spec.extensions = ['ext/encrypter/extconf.rb']

  spec.add_development_dependency 'bundler', '~> 1.3'
  spec.add_development_dependency 'rake'
  spec.add_development_dependency 'rake-compiler'
  spec.add_development_dependency 'pry'
end

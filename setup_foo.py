from distutils.core import setup, Extension

foomodule = Extension('foo',
                    sources = ['foomodule.c'],
                    extra_compile_args = ['-g'])

setup (name = 'Foo',
       version = '0.1',
       description = 'This is a cazzo package',
       ext_modules = [foomodule])
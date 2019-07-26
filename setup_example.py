from distutils.core import setup, Extension

examplemodule = Extension('example',
                    sources = ['examplemodule.c'],
                    extra_compile_args = ['-g'])

setup (name = 'example',
       version = '0.1',
       description = 'This is a cazzo package',
       ext_modules = [examplemodule])
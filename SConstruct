# @COPYRIGHT@
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE

import os

def BuildVariant(env, variant_dir, src_dir, duplicate = 0, **kw):
    SConscript( '%s/SConscript' % variant_dir, exports = ['env'] )

env = Environment( ENV = os.environ, tools =  [ 'default' , 'textfile' , 'doxygen' ] )

# import some environment variables
for key in ['CC', 'CXX']:
  try:
    env[key] = env['ENV'][key]
  except KeyError:
    pass

# NOTE: Use only libstdc++ (gcc lib), because boost test shared lib is compiled
# against it. If you force libc++ here, then test will fail with segfault.
#if env['CXX'] == 'clang++':
#  env.Append(CXXFLAGS = ['-stdlib=libc++'])
#  env.Append(LIBS = ['c++'])

# Variant directories
variants = [
  { 'variant_dir' : 'build', 
    'src_dir' : 'src', 
    'duplicate' : 0,
    'env' : env.Clone() }
]

# Prepare variants
for v in variants:
    kw = { k: v[k] for k in v if k in ('variant_dir', 'src_dir', 'duplicate')}
    VariantDir(**kw)
# Build variants
for v in variants:
    BuildVariant(**v)
    
# Global targets
api_doc = env.AlwaysBuild(env.Alias('api-doc'))
env.Depends(api_doc, env.Glob('bin/doxy*'))

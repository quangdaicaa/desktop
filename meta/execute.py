import os, sys, subprocess, uuid
from subprocess import run

def breakpath(path:str) -> tuple[str,str,str]:
  '''return folder, filname, ext'''
  path=path.split('/')
  folder = '/'.join(path[:-1])
  filename = path[-1].split('.')
  len_ = len(filename)
  if len_ == 1: return folder, filename[0], ''
  elif len_ == 2: return folder, filename[0], filename[-1]
  else: return folder, '.'.join(filename[:-1]), filename[-1]

# def exe(code:str|list) -> None:
#   if isinstance(code, str): subprocess.run(code.split(' '))
#   else: subprocess.run(code)

# --------------------------------------------------
CWD = os.getcwd()
VER_PYTHON = '.'.join(sys.version.split('.')[:2])
INCLUDE = f'/usr/include/python{VER_PYTHON}'

PATH, MODE, *_ = sys.argv[1:]
DIR, NAME, EXT = breakpath(PATH)

if EXT == 'txt' and NAME == 'requirements':
  run(['pip', 'install', '--upgrade', '-r', '~/env/python/requirements.txt'])
if MODE == 'exe':
  if EXT == 'py':
    run(['python3', PATH])
  elif EXT == 'sh':
    run(['chmod', 'x', PATH])
    run(['zsh', PATH])
  elif EXT == 'pl':
    run(['perl', PATH])
  elif EXT == 'java':
    run(['javac', PATH])
    os.chdir(DIR)
    run(['java', NAME])
    os.chdir(CWD)
  elif EXT == 'scala':
    run(['scalac', PATH])
    os.chdir(DIR)
    run(['scala', NAME])
    os.chdir(CWD)
  elif EXT == 'go':
    run(['go', 'build', '-o', f'{DIR}/{NAME}.so', {PATH}])
    run([f'{DIR}/{NAME}.so'])
  elif EXT == 'rs':
    run(['rustc', '-o', f'{DIR}/{NAME}.so', PATH])
    run([f'{DIR}/{NAME}.so'])
  elif EXT == 'cpp':
    run(['g++', '-I', INCLUDE, f'{DIR}/{NAME}.cpp', '-o', f'{DIR}/{NAME}.so'])
    run([f'{DIR}/{NAME}.so'])
  elif EXT == 'js':
    run(['node', PATH])
  elif EXT == 'ts':
    run(['node', '$(which tsc)', PATH])
    run(['node', f'{DIR}/{NAME}.js'])
  elif EXT == 'rb':
    run(['ruby', PATH])
  elif EXT == 'lua':
    run(['lua', PATH])
  elif EXT == 'php':
    run(['php', PATH])
  elif EXT == 'hs':
    run(['ghc', PATH])
    run(['rm', f'{DIR}/{NAME}.hi', f'{DIR}/{NAME}.o'])
    run(['mv', f'{DIR}/{NAME}', '{DIR}/{NAME}.so'])
    run([f'{DIR}/{NAME}.so'])
  elif EXT == 'pyx':
    from distutils.core import setup
    from Cython.Build import cythonize
    import importlib.util
    version = VER_PYTHON.replace('.', '')
    so = f'{NAME}.cpython-{VER_PYTHON}-x86_64-linux-gnu.so'
    try:
      setup(
        EXT_modules=cythonize(PATH, annotate=True), 
        script_args=['build_ext'],                                        
        options={'build_ext':{'inplace':True}},
        include_dirs=[INCLUDE]
        )
    except:
      run(['rm', f'{DIR}/{NAME}.c'])
      run(['rm', f'{DIR}/{NAME}.html'])
    run(['mv', so, f'{DIR}/{so}'])
    run(['rm', '-rf', 'build'])
    pyx = importlib.util.spec_from_file_location(NAME, f'{DIR}/{so}')
    pyx.loader.exec_module(importlib.util.module_from_spec(pyx))
  elif EXT == 'dock':
    run(['sudo', 'docker', 'image', 'rm', '-f', NAME])
    run(['sudo', 'docker', 'build', DIR, '-f', PATH, '-t', NAME])
  elif EXT == 'yml' or EXT == 'yaml':
    if '.play' in NAME: pass
      # inventory= '~/Desktop/system/terraform/inventory.yml'
      # exe(f'ansible-playbook -i {inventory} {PATH}')


if MODE == 'test':
  if EXT == 'py' or EXT =='pyx':
    filetest = f'{DIR}/{NAME}_test.py'
    if os.path.exists(filetest):
      run(['python3', filetest])
    else:
      open(filetest, 'w').write(f'''\
import unittest
import {NAME}

class {NAME}_test(unittest.TestCase):
  def test_func(self):
    # self.assertEqual(func(*arg), ret)
    pass

if __name__ == '__main__':
  unittest.main()
''')
      run(['python3', filetest])

if MODE == 'add':
  run(['git', 'branch', '-M', 'main'])
  run(['git', 'add', PATH])
  run(['git', 'commit', '-m', uuid.uuid4()])
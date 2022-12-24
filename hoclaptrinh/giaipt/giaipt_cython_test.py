import unittest
import numpy as np
import giaipt_cython #pyright:ignore

# --------------------------------------------------
n = 100000
class giaipt_python_test(unittest.TestCase):
  def test_bac2(self):
    func = giaipt_cython.bac2
    args = np.random.uniform(-1000,1000,(n,2))
    for a,b in args:
      n0 = func(a,b)
      if n0[0]>0:
        for x in n0[1]:
          self.assertEqual(round(x*x+a*x+b,4), 0)


  def test_bac3(self):
    func = giaipt_cython.bac3
    args = np.random.uniform(-1000,1000,(n,3))
    for a,b,c in args:
      n0 = func(a,b,c)
      if n0[0]>0:
        for x in n0[1]:
          self.assertEqual(round(x**3+a*x*x+b*x+c,4), 0)

if __name__ == '__main__':
  unittest.main(verbosity=2)
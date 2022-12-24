from libc.math cimport sqrt, cbrt, cos, acos, copysign
from cython cimport cdivision
cimport numpy as np
import numpy as np

np.import_array()

cdef double PI = 3.141592653589793

@cdivision(True)
cpdef tuple bac2(double a, double b):
  '''x^2 + ax + b = 0'''
  delta = a*a-4*b
  if delta == 0:
    x0 = -a/2
    return 1, [x0]
  elif delta < 0:
    return 0, []
  else:
    delta = sqrt(delta)
    x1 = (-delta-a)/2
    x2 = (delta-a)/2
    return 2, [x1, x2]

@cdivision(True)
cpdef tuple bac3(double a, double b, double c):
  '''x^3 + ax^2 + bx + c = 0'''
  cdef double k
  delta = a*a-3*b
  if delta == 0:
    a /= 3
    x0 = cbrt(a*a*a-c)-a
    return 1, [x0]
  elif delta < 0:
    delta = sqrt(-delta)
    k = 4.5*a*b-a*a*a-13.5*c
    k /= delta*delta*delta
    k2 = sqrt(k*k+1)
    x0 = (delta*(cbrt(k+k2)+cbrt(k-k2))-a)/3
    return 1, [x0]
  else:
    delta = sqrt(delta)
    k = 4.5*a*b-a*a*a-13.5*c
    k /= delta*delta*delta
    a /= 3
    delta /= 3
    if k == -1:
      x1 = delta-a
      x2 = -2*delta-a
      return 2, [x1, x2]
    elif k == 1:
      x1 = -delta-a
      x2 = 2*delta-a
      return 2, [x1, x2]
    elif abs(k) < 1:
      k = acos(k)/3
      delta *= 2
      pii = PI*2/3
      x1 = delta*cos(k)-a
      x2 = delta*cos(k-pii)-a
      x3 = delta*cos(k+pii)-a
      return 3, [x1, x2, x3]
    else:
      delta = copysign(delta, k)
      k = abs(k)
      k2 = sqrt(k*k-1)
      x0 = delta*(cbrt(k+k2)+cbrt(k-k2))-a
      return 1, [x0]

cpdef np.ndarray hebac1(np.ndarray a, np.ndarray b):
  '''ax = b'''
  return np.linalg.solve(a,b)
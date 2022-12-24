package main

import (
  "fmt"
  "math"
)

const PI float64 = 3.141592653589793

type nghiem struct {
  so_nghiem int
  tap_nghiem []float64
}

func bac2(a float64, b float64) nghiem {
  // x^2 + ax + b = 0
  var delta = a*a-4*b
  if delta == 0 {
    return nghiem {
      so_nghiem: 1,
      tap_nghiem: []float64{-a/2},
    }
  } else if delta < 0 {
    return nghiem {
      so_nghiem: 0,
    }
  } else {
    delta = math.Sqrt(delta);
    return nghiem {
      so_nghiem: 2,
      tap_nghiem: []float64{(-delta-a)/2, (delta-a)/2},
    }
  }
}

func bac3(a float64, b float64, c float64) nghiem {
  // x^3 + ax^2 + bx + c = 0
  var delta = a*a-3*b
  if delta == 0 {
    a /= 3
    return nghiem {
      so_nghiem: 1,
      tap_nghiem: []float64{math.Cbrt(a*a*a-c)-a},
    }
  } else if delta < 0 {
    delta = math.Sqrt(-delta)
    var k = 4.5*a*b-a*a*a-13.5*c
    k /= delta*delta*delta
    var k2 = math.Sqrt(k*k+1)
    return nghiem {
      so_nghiem: 1,
      tap_nghiem: []float64{(delta*(math.Cbrt(k+k2)+math.Cbrt(k-k2))-a)/3},
    }
  } else {
    delta = math.Sqrt(delta)
    var k = 4.5*a*b-a*a*a-13.5*c
    k /= delta*delta*delta
    a /= 3
    delta /= 3
    if k == -1 {
      return nghiem {
        so_nghiem: 2,
        tap_nghiem: []float64{delta-a, -2*delta-a},
      }
    } else if (k == 1) {
      return nghiem {
        so_nghiem: 2,
        tap_nghiem: []float64{-delta-a, 2*delta-a},
      }
    } else if math.Abs(k) < 1 {
      k = math.Acos(k)/3
      delta *= 2
      var pii = PI*2/3
      return nghiem {
        so_nghiem: 3,
        tap_nghiem: []float64{
          delta*math.Cos(k)-a,
          delta*math.Cos(k-pii)-a,
          delta*math.Cos(k+pii)-a,
        },
      }
    } else {
      delta = math.Copysign(delta, k)
      k = math.Abs(k)
      var k2 = math.Sqrt(k*k-1)
      return nghiem {
        so_nghiem: 1,
        tap_nghiem: []float64{delta*(math.Cbrt(k+k2)+math.Cbrt(k-k2))-a},
      }
    }
  }
}

func main() {
  fmt.Println(bac2(-2, 10))
}
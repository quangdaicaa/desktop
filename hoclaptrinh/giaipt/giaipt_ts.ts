const PI = 3.141592653589793

function bac2(a:number, b:number) {
  // x^2 + ax + b = 0
  var delta = a*a-4*b
  if (delta == 0) return [1, [-a/2]]
  else if (delta < 0) return [0, []]
  else {
    delta = Math.sqrt(delta)
    return [2, [(-delta-a)/2, (delta-a)/2]]
  }
}

function bac3(a:number, b:number, c:number) {
  // x^3 + ax^2 + bx + c = 0
  var delta = a*a-3*b
  if (delta == 0) {
    a /= 3
    return [1, [Math.pow(a*a*a-c, 1/3)-a]]
  } else if (delta < 0) {
    delta = Math.sqrt(-delta)
    var k = 4.5*a*b-a*a*a-13.5*c
    k /= delta*delta*delta
    let k2 = Math.sqrt(k*k+1)
    return [1, [(delta*(Math.pow(k+k2,1/3)+Math.pow(k-k2,1/3))-a)/3]]
  } else {
    delta = Math.sqrt(delta)
    var k = 4.5*a*b-a*a*a-13.5*c
    k /= delta*delta*delta
    a /= 3
    delta /= 3
    if (k == -1) return [2, [delta-a, -2*delta-a]]
    else if (k == 1) return [2, [-delta-a, 2*delta-a]]
    else if (Math.abs(k) < 1) {
      k = Math.acos(k)/3
      delta *= 2
      let pii = PI*2/3
      return [3, [
        delta*Math.cos(k)-a,
        delta*Math.cos(k-pii)-a,
        delta*Math.cos(k+pii)-a
      ]]
    } else {
      if (k < 0) delta *= -1
      k = Math.abs(k)
      let k2 = Math.sqrt(k*k-1);
      return [1, [delta*(Math.pow(k+k2,1/3)+Math.pow(k-k2,1/3))-a]]
    }
  }
}

export {}
package giaipt;
import java.lang.Math;
public class giaipt {
  static public double PI = 3.141592653589793;
  static public nghiem bac2(double a, double b) {
    // x^2 + ax + b = 0
    nghiem res = new nghiem();
    double delta = a*a-4*b;
    if (delta == 0) {
      double[] tap_nghiem = {-a/2};
      res.so_nghiem = 1;
      res.tap_nghiem = tap_nghiem;
      return res;
    } else if (delta < 0) {
      res.so_nghiem = 0;
      return res;
    } else {
      delta = Math.sqrt(delta);
      double[] tap_nghiem = {(-delta-a)/2, (delta-a)/2};
      res.so_nghiem = 2;
      res.tap_nghiem = tap_nghiem;
      return res;
    }
  };
  
  static public nghiem bac3(double a, double b, double c) {
    // x^3 + ax^2 + bx + c = 0
    nghiem res = new nghiem();
    double delta = a*a-3*b;
    if (delta == 0) {
      a /= 3;
      double[] tap_nghiem = {Math.cbrt(a*a*a-c)-a};
      res.so_nghiem = 1;
      res.tap_nghiem = tap_nghiem;
      return res;
    } else if (delta < 0) {
      delta = Math.sqrt(-delta);
      double k = 4.5*a*b-a*a*a-13.5*c;
      k /= delta*delta*delta;
      double k2 = Math.sqrt(k*k+1);
      double[] tap_nghiem = {(delta*(Math.cbrt(k+k2)+Math.cbrt(k-k2))-a)/3};
      res.so_nghiem = 1;
      res.tap_nghiem = tap_nghiem;
      return res;
    } else {
      delta = Math.sqrt(delta);
      double k = 4.5*a*b-a*a*a-13.5*c;
      k /= delta*delta*delta;
      a /= 3;
      delta /= 3;
      if (k == -1) {
        double[] tap_nghiem = {delta-a, -2*delta-a};
        res.so_nghiem = 2;
        res.tap_nghiem = tap_nghiem;
        return res;
      } else if (k == 1) {
        double[] tap_nghiem = {-delta-a, 2*delta-a};
        res.so_nghiem = 2;
        res.tap_nghiem = tap_nghiem;
        return res;
      } else if (Math.abs(k) < 1) {
        k = Math.acos(k)/3;
        delta *= 2;
        double pii = PI*2/3;
        double[] tap_nghiem = {
          delta*Math.cos(k)-a,
          delta*Math.cos(k-pii)-a,
          delta*Math.cos(k+pii)-a
        };
        res.so_nghiem = 3;
        res.tap_nghiem = tap_nghiem;
        return res;
      } else {
        delta = Math.copySign(delta, k);
        k = Math.abs(k);
        double k2 = Math.sqrt(k*k-1);
        double[] tap_nghiem = {delta*(Math.cbrt(k+k2)+Math.cbrt(k-k2))-a};
        res.so_nghiem = 1;
        res.tap_nghiem = tap_nghiem;
        return res;
      }
    }
  }
}
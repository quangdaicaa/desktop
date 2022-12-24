#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double PI = 3.141592653589793;

int arr_len(double* arr) {
  return (int) *arr;
}

void arr_print(double* arr) {
  int len_ = (int) *arr;
  if (len_ == 0) cout << "[]" << endl;
  else {
    cout << "[ ";
    for (uint i=1; i<=len_; i++)
      cout << *(arr+i) << "  ";
    cout << "]\n";
  }
}

double* bac2(double a, double b) {
  // x^2 + ax + b = 0
  double delta = a*a-4*b;
  if (delta == 0) {
    static double tap_nghiem[2] = {1, -a/2};
    return tap_nghiem;
  } else if (delta < 0) {
    static double tap_nghiem[1] = {0};
    return tap_nghiem;
  } else {
    delta = sqrt(delta);
    static double tap_nghiem[3] = {2, (-delta-a)/2, (delta-a)/2};
    return tap_nghiem;
  }
}

double* bac3(double a, double b, double c) {
  // x^3 + ax^2 + bx + c = 0
  double delta = a*a-3*b;
  if (delta == 0) {
    a /= 3;
    static double tap_nghiem[2] = {1, cbrt(a*a*a-c)-a};
    return tap_nghiem;
  } else if (delta < 0) {
    delta = sqrt(-delta);
    double k = 4.5*a*b-a*a*a-13.5*c;
    k /= delta*delta*delta;
    double k2 = sqrt(k*k+1);
    static double tap_nghiem[2] = {1, (delta*(cbrt(k+k2)+cbrt(k-k2))-a)/3};
    return tap_nghiem;
  } else {
    delta = sqrt(delta);
    double k = 4.5*a*b-a*a*a-13.5*c;
    k /= delta*delta*delta;
    a /= 3;
    delta /= 3;
    if (k == -1) {
      static double tap_nghiem[3] = {2, delta-a, -2*delta-a};
      return tap_nghiem;
    } else if (k == 1) {
      static double tap_nghiem[3] = {2, -delta-a, 2*delta-a};
      return tap_nghiem;
    } else if (abs(k) < 1) {
      k = acos(k)/3;
      delta *= 2;
      double pii = PI*2/3;
      static double tap_nghiem[4] = {
        3,
        delta*cos(k)-a,
        delta*cos(k-pii)-a,
        delta*cos(k+pii)-a
      };
      return tap_nghiem;
    } else {
      delta = copysign(delta, k);
      k = abs(k);
      double k2 = sqrt(k*k-1);
      static double tap_nghiem[2] = {1, delta*(cbrt(k+k2)+cbrt(k-k2))-a};
      return tap_nghiem;
    }
  }
}

double det(double* arr) {
  int len_ = (int) *arr;
  switch (len_) {
  case 1: return *(arr+1);
  case 4: return (*(arr+1))*(*(arr+4))-(*(arr+2))*(*(arr+3));
  case 9: {
    double a10 = *(arr+4);
    double a11 = *(arr+5);
    double a12 = *(arr+6);
    double a20 = *(arr+7);
    double a21 = *(arr+8);
    double a22 = *(arr+9);
    return
    + *(arr+1)*(a11*a22-a12*a21)
    + *(arr+2)*(a12*a20-a10*a22)
    + *(arr+3)*(a10*a21-a11*a20);
  }
  case 16: {
    double a00 = *(arr+1);
    double a01 = *(arr+2);
    double a02 = *(arr+3);
    double a03 = *(arr+4);
    double a10 = *(arr+5);
    double a11 = *(arr+6);
    double a12 = *(arr+7);
    double a13 = *(arr+8);
    double a20 = *(arr+9);
    double a21 = *(arr+10);
    double a22 = *(arr+11);
    double a23 = *(arr+12);
    double a30 = *(arr+13);
    double a31 = *(arr+14);
    double a32 = *(arr+15);
    double a33 = *(arr+16);
    return 
    + (a00*a11-a01*a10)*(a22*a33-a23*a32) + (a00*a12-a02*a10)*(a23*a31-a21*a33)
    + (a00*a13-a03*a10)*(a21*a32-a22*a31) + (a01*a12-a02*a11)*(a20*a33-a23*a30)
    + (a01*a13-a03*a11)*(a22*a30-a20*a32) + (a02*a13-a03*a12)*(a20*a31-a21*a30);
  }
  case 25: {
    double a00 = *(arr+1);
    double a01 = *(arr+2);
    double a02 = *(arr+3);
    double a03 = *(arr+4);
    double a04 = *(arr+5);
    double a10 = *(arr+6);
    double a11 = *(arr+7);
    double a12 = *(arr+8);
    double a13 = *(arr+9);
    double a14 = *(arr+10);
    double a20 = *(arr+11);
    double a21 = *(arr+12);
    double a22 = *(arr+13);
    double a23 = *(arr+14);
    double a24 = *(arr+15);
    double a30 = *(arr+16);
    double a31 = *(arr+17);
    double a32 = *(arr+18);
    double a33 = *(arr+19);
    double a34 = *(arr+20);
    double a40 = *(arr+21);
    double a41 = *(arr+22);
    double a42 = *(arr+23);
    double a43 = *(arr+24);
    double a44 = *(arr+25);

    double b0 = a00*a11 - a01*a10;
    double b1 = a01*a12 - a02*a11;
    double b2 = a02*a13 - a03*a12;
    double b3 = a03*a14 - a04*a13;
    double b4 = a00*a12 - a02*a10;
    double b5 = a01*a13 - a03*a11;
    double b6 = a02*a14 - a04*a12;
    double b7 = a03*a10 - a00*a13;
    double b8 = a04*a11 - a01*a14;
    double b9 = a04*a10 - a00*a14;

    return
    + (a24*a32-a22*a34)*(a43*b0+a41*b7+a40*b5) + (a20*a33-a23*a30)*(a44*b1+a42*b8+a41*b6)
    + (a21*a34-a24*a31)*(a40*b2+a43*b4+a42*b7) + (a22*a30-a20*a32)*(a41*b3+a44*b5+a43*b8)
    + (a23*a31-a21*a33)*(a42*b9+a40*b6+a44*b4) + (a22*a33-a23*a32)*(a44*b0+a41*b9-a40*b8)
    + (a23*a34-a24*a33)*(a40*b1+a42*b0-a41*b4) + (a24*a30-a20*a34)*(a41*b2+a43*b1-a42*b5)
    + (a20*a31-a21*a30)*(a42*b3+a44*b2-a43*b6) + (a21*a32-a22*a31)*(a43*b9+a40*b3-a44*b7);
  }
  case 36: {
    double a00 = *(arr+1);
    double a01 = *(arr+2);
    double a02 = *(arr+3);
    double a03 = *(arr+4);
    double a04 = *(arr+5);
    double a05 = *(arr+6);
    double a10 = *(arr+7);
    double a11 = *(arr+8);
    double a12 = *(arr+9);
    double a13 = *(arr+10);
    double a14 = *(arr+11);
    double a15 = *(arr+12);
    double a20 = *(arr+13);
    double a21 = *(arr+14);
    double a22 = *(arr+15);
    double a23 = *(arr+16);
    double a24 = *(arr+17);
    double a25 = *(arr+18);
    double a30 = *(arr+19);
    double a31 = *(arr+20);
    double a32 = *(arr+21);
    double a33 = *(arr+22);
    double a34 = *(arr+23);
    double a35 = *(arr+24);
    double a40 = *(arr+25);
    double a41 = *(arr+26);
    double a42 = *(arr+27);
    double a43 = *(arr+28);
    double a44 = *(arr+29);
    double a45 = *(arr+30);
    double a50 = *(arr+31);
    double a51 = *(arr+32);
    double a52 = *(arr+33);
    double a53 = *(arr+34);
    double a54 = *(arr+35);
    double a55 = *(arr+36);

    double b00 = a00*a11 - a01*a10;
    double b01 = a00*a13 - a03*a10;
    double b02 = a00*a14 - a04*a10;
    double b03 = a01*a12 - a02*a11;
    double b04 = a01*a13 - a03*a11;
    double b05 = a02*a10 - a00*a12;
    double b06 = a02*a13 - a03*a12;
    double b07 = a02*a14 - a04*a12;
    double b08 = a02*a15 - a05*a12;
    double b09 = a04*a11 - a01*a14;
    double b10 = a04*a13 - a03*a14;
    double b11 = a04*a15 - a05*a14;
    double b12 = a05*a10 - a00*a15;
    double b13 = a05*a11 - a01*a15;
    double b14 = a05*a13 - a03*a15;
    double b15 = a20*a31 - a21*a30;
    double b16 = a20*a32 - a22*a30;
    double b17 = a20*a33 - a23*a30;
    double b18 = a20*a34 - a24*a30;
    double b19 = a21*a32 - a22*a31;
    double b20 = a21*a33 - a23*a31;
    double b21 = a21*a35 - a25*a31;
    double b22 = a22*a33 - a23*a32;
    double b23 = a22*a34 - a24*a32;
    double b24 = a22*a35 - a25*a32;
    double b25 = a23*a34 - a24*a33;
    double b26 = a24*a31 - a21*a34;
    double b27 = a24*a35 - a25*a34;
    double b28 = a25*a30 - a20*a35;
    double b29 = a25*a33 - a23*a35;

    return
    + (a40*a51-a41*a50)*(b22*b11+b23*b14+b25*b08+b27*b06+b29*b07-b24*b10)
    + (a40*a52-a42*a50)*(b21*b10+b25*b13+b26*b14+b29*b09-b20*b11-b27*b04)
    + (a40*a53-a43*a50)*(b19*b11+b21*b07+b24*b09+b26*b08+b27*b03-b23*b13)
    + (a40*a54-a44*a50)*(b19*b14+b20*b08+b22*b13+b24*b04+b29*b03-b21*b06)
    + (a41*a52-a42*a51)*(b17*b11+b18*b14+b27*b01+b28*b10+b29*b02-b25*b12)
    + (a41*a53-a43*a51)*(b18*b08+b23*b12+b24*b02+b27*b05+b28*b07-b16*b11)
    + (a41*a55-a45*a51)*(b16*b10+b17*b07+b23*b01+b25*b05-b18*b06-b22*b02)
    + (a42*a53-a43*a52)*(b15*b11+b18*b13+b26*b12+b27*b00+b28*b09-b21*b02)
    + (a42*a54-a44*a52)*(b15*b14+b20*b12+b21*b01+b28*b04+b29*b00-b17*b13)
    + (a42*a55-a45*a52)*(b17*b09+b18*b04+b20*b02+b25*b00+b26*b01-b15*b10)
    + (a43*a54-a44*a53)*(b15*b08+b16*b13+b21*b05+b24*b00-b28*b03-b19*b12)
    + (a44*a51-a41*a54)*(b16*b14+b17*b08+b22*b12+b24*b01+b28*b06-b29*b05)
    + (a44*a55-a45*a54)*(b15*b06+b17*b03+b19*b01+b20*b05+b22*b00-b16*b04)
    + (a45*a50-a40*a55)*(b19*b10+b20*b07+b22*b09+b23*b04+b26*b06-b25*b03)
    + (a45*a53-a43*a55)*(b15*b07+b16*b09+b18*b03+b19*b02+b23*b00-b26*b05);
  }
  default:

    return 0;
  }
}

double* arr_pop(double* arr, int loc) {
  int len_ = (int) *arr - 1;
  double* res = new double[len_];
  *res = len_;
  if (loc == 0)
    for (uint i=1; i<=len_; i++)
      *(res+i) = *(arr+i+1);
  else if (loc == len_)
    for (uint i=1; i<=len_; i++)
      *(res+i) = *(arr+i);
  else {
    for (uint i=0; i<loc; i++) {
      *(res+i) = *(arr+i);
    }
    for (uint i=loc; i<len_; i++) {
      *(res+i) = *(arr+i+1);
    }
  }
  return res;
}

// double* arr_pop(double* arr, int* loc) {
//   int len_loc = *loc;
//   int len_ = (int) *arr - len_loc;
//   double* res = new double[len_];
//   *res = len_;
//   int loc_begin = 1;
//   int loc_end = *(loc+1);
//   for (uint i=loc_begin; i<loc_end; i++)
//     *(res+i) = *(loc+i);
//   loc_begin = loc_end+1;
//   return 0;
// }


int main() {
  cout << setprecision(3) << fixed;
  srand(time(NULL));
  int min = -20;
  int max = 20;
  double x00 = rand() % (max - min + 1) + min;
  
  double test_arr[5] = {4.0, 0.0, 1.0, 2.0, 3.0};
  double* test2 = arr_pop(test_arr, 1);
  arr_print(test2);
  return 0;  
}
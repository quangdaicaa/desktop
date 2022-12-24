#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;



template<typename T>
class arr {
public:
  uint len=0;
  T* ptr;

  arr(T* ptr_, uint len_=0) {
    len = len_;
    ptr = ptr_;
  }

  void print(int precision=3) {
    cout << setprecision(precision) << "[  ";
    for (T* e=ptr; e<ptr+len; e++)
      cout << *e << "  ";
    cout << "]\n";
  }

  T &operator[](int loc) {
    if (loc<0) loc=loc%len+len;
    if (loc>=len) loc%=len;
    return *(ptr+loc);
  }
};


int main() {
  double b[5] = {7.0/3, 8.0/3, 10.0/3, 11.0/3, 13.0/3};
  arr<double> a1 = arr(b, 5);
  a1.print(4);
  // a1[-5] = 2000;
  cout << a1[-10] << endl;
  return 0;
}
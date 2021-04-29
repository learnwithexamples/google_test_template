#include "class_a.h"
#include "class_b.h"
#include <iostream>
using namespace std;

int main() {
  cout << "(3 + 4) * 5 = " << class_b::mul(class_a::sum(3, 4), 5) << endl;
  return 0;
}
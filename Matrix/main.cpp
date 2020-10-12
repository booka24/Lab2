#include <iostream>
#include "MyVector.h"
#include "Matrix.h"

int main()
{
    Vector<int> A(3, 3);
    TMatrix<int> a(3);
    TMatrix<int> B = a;
    TMatrix<int> C(3);

  a + B;

  return 0;
}

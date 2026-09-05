#include <iostream>
#include <schur/matrix/Matrix>

int main(int argc, char* argv[])
{
  using namespace schur;
  Matrix<float, Dynamic, Dynamic> a = {{1, 2}, {3, 4}};
  Matrix<float, 2, Dynamic> b = a;

  return 0;
}
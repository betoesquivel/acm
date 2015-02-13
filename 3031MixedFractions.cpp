#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
{
  int num, den, mixed;

   scanf("%d %d", &num, &den);

  while (!( num == 0 && den == 0 )){
     mixed = 0;

     mixed = num / den;
     num  = num % den;

     printf("%d %d / %d\n", mixed, num, den);
     scanf("%d %d", &num, &den);
  }

  return 0;
}

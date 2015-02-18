#include <set>
#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
{
  int T;
  int N;
  int num;
  set<int> repeated;
  bool notFound;

  scanf("%d", &T);
  while(T > 0){
    scanf("%d", &N);
    notFound = true;
    repeated.clear();
    while(N > 0){
      scanf("%d", &num);
      if(repeated.count(num) > 0){
        printf("%d\n", num);
        notFound = false;
      }else{
        repeated.insert(num);
      }
      N--;
    }
    if (notFound) {
      printf("Not found!\n");
    }
    T--;
  }

  return 0;
}

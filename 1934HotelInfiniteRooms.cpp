#include <cstdio>
#include <cmath>

using namespace std;

long long calc(long long s, long long d) {
  while(d > 0){
    d -= s;
    s++;
  }
  return s-1;
}

int main(int argc, const char *argv[])
{
  long long int s;
  long long int d;
  long long int ans;

  while(scanf("%lld %lld", &s, &d) == 2){
    ans = calc(s, d);
    printf("%lld\n", ans);
  }

  return 0;
}

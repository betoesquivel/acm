#include <cstdio>
#include <cmath>

using namespace std;

long long calc(long long s, long long d) {
  double c = d + (s*s - s) / 2.0;
  return ceil( (sqrt(8*c + 1) - 1) / 2.0 );
}

int main(int argc, const char *argv[])
{
  long long int s;
  long long int d;
  long long int ans;

  while(scanf("%lld %lld", &s, &d) != 1){
    ans = calc(s, d);
    printf("%lld\n", ans);
  }

  return 0;
}

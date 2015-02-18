#include <cmath>
#include <iostream>

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
  std::ios::sync_with_stdio(false);
  while(cin >> s >> d){
    ans = calc(s, d);
    cout << ans << endl;
  }

  return 0;
}

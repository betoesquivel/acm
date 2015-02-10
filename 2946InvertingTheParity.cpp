#include <iostream>
#include <map>

using namespace std;

// converts int to binary
void Convert(unsigned int val)
{
     unsigned int mask = 1 << (sizeof(int) * 8 - 1);

        for(int i = 0; i < sizeof(int) * 8; i++) {
                     if( (val & mask) == 0 )
                                cout << '0' ;
                           else
                                      cout << '1' ;

                                 mask  >>= 1;
        }
           cout << endl ;
}

map<int, int> shiftFor;
map<int, int>::iterator it;
int invertParity(int n){
  int extra_shifts = 0;
  if ((n & 1) == 1){
    return n<<1;
  }else {
    unsigned int inverted = n;
    int shift = 1; // for 2
    while ((inverted & 1) == 0){
      if (shiftFor.count(inverted) == 1){
        shift = shiftFor[inverted];
        if (extra_shifts > 0){
            extra_shifts += shift;
            shiftFor[n] = extra_shifts;
            extra_shifts = 0;
        }
        return inverted>>shift;
      }else{
        it = shiftFor.lower_bound(inverted);
        if (it != shiftFor.begin()){
          --it;
        }
        shift = shiftFor[inverted % it->first];
        extra_shifts += shift;
      }
      inverted>>=shift;
    }
    return inverted;
  }
}
int main(int argc, const char *argv[])
{
  int T, num;
  shiftFor[2] = 1;
  shiftFor[4] = 2;
  shiftFor[8] = 3;
  shiftFor[16] = 4;
  shiftFor[32] = 5;
  shiftFor[64] = 6;
  cin>>T;
  while(T > 0){
    cin>>num;
    cout << invertParity(num) << endl;

    T--;
  }
  return 0;
}

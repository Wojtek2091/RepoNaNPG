
#include <iostream>

using namespace std;

typedef unsigned long long ulong;

// Funkcja mno¿y a i b mod n
//--------------------------
ulong MnozModulo(ulong a, ulong b, ulong n)
{
  ulong m,w;

  w = 0; m = 1;
  while(m)
  {
    if(b & m) w = (w + a) % n;
    a = (a << 1) % n;
    m <<= 1;
  }
  return w;
}

int main()
{
  ulong e,n,m,p,w;

  cin >> e >> n;
  p = 2; w = m = 1;
  while(m)
  {
    if(e & m) w = MnozModulo(w,p,n);
    p = MnozModulo(p,p,n);
    m <<= 1;
  }
  cout << w << endl;
  return 0;
} 
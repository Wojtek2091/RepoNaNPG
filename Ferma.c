
#include <iostream>
#include <cmath>

using namespace std;

void Fermat(unsigned int p)
{
  unsigned long long x,y,z,m,n;

  x = (unsigned long long)ceil(sqrt(p));
  do
  {
    z = x * x - p;
    y = (unsigned long long)floor(sqrt(z));
    if(z == y * y)
    {
      m = x + y;
      n = x - y;
      if(n == 1) break;
      Fermat(m);
      Fermat(n);
      return;
    }
    x++;
  } while(x + y < p);
  cout << p << " ";
}

int main()
{
  unsigned int p;

  cin >> p;
  while(p % 2 == 0)
  {
    p /= 2;
    cout << 2 << " ";
  }
  if(p > 1) Fermat(p);
  cout << endl;
  return 0;
}
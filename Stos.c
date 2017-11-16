#include <iostream>

using namespace std;

int main()
{
  int * SL, * SP;                     // stosy
  int SLp = 0,SPp = 0;                // indeksy szczytów stosów
  int n;                              // liczba elementów wejœciowych
  int v;                              // wartoœæ elementu

  cin >> n;                           // odczytujemy liczbê elementów

  SL = new int[n+2];                  // tworzymy stosy
  SP = new int[n+2];

  SLp = SPp = 1;                      // inicjujemy stosy

  SL[0] = -2147483648;                // najmniejsza wartoœæ
  SP[0] =  2147483647;                // najwiêksza wartoœæ

  for(int i = 0; i < n; i++)          // przetwarzamy dane wejœciowe
  {
    cin >> v;                         // odczytujemy dan¹ z wejœcia

    while(SL[SLp-1] > v)
      SP[SPp++] = SL[--SLp];          // przenosimy z SL do SP wszystkie
                                      // elementy wiêksze od v
    while(SP[SPp-1] < v)
      SL[SLp++] = SP[--SPp];          // przenosimy z SP do SL wszystkie
                                      // elementy mniejsze od v
    SL[SLp++] = v;                    // v umieszczamy w SL
  }

  while(SLp) SP[SPp++] = SL[--SLp];   // przenosimy stos SL do SP

  SPp--;                              // usuwamy stra¿nika

  do                                  // przesy³amy SP na wyjœcie
  {
    v = SP[--SPp];
    if(SPp) cout << v << " ";
  } while(SPp);

  cout << endl;

  delete [] SL;                       // usuwamy stosy
  delete [] SP;

  return 0;
} 
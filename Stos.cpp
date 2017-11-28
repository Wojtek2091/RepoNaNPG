#include <iostream>

using namespace std;

int main()
{
  int * SL, * SP;                     // stosy
  int SLp = 0,SPp = 0;                // indeksy szczyt�w stos�w
  int n;                              // liczba element�w wej�ciowych
  int v;                              // warto�� elementu

  cin >> n;                           // odczytujemy liczb� element�w

  SL = new int[n+2];                  // tworzymy stosy
  SP = new int[n+2];

  SLp = SPp = 1;                      // inicjujemy stosy

  SL[0] = -2147483648;                // najmniejsza warto��
  SP[0] =  2147483647;                // najwi�ksza warto��

  for(int i = 0; i < n; i++)          // przetwarzamy dane wej�ciowe
  {
    cin >> v;                         // odczytujemy dan� z wej�cia

    while(SL[SLp-1] > v)
      SP[SPp++] = SL[--SLp];          // przenosimy z SL do SP wszystkie
                                      // elementy wi�ksze od v
    while(SP[SPp-1] < v)
      SL[SLp++] = SP[--SPp];          // przenosimy z SP do SL wszystkie
                                      // elementy mniejsze od v
    SL[SLp++] = v;                    // v umieszczamy w SL
  }

  while(SLp) SP[SPp++] = SL[--SLp];   // przenosimy stos SL do SP

  SPp--;                              // usuwamy stra�nika

  do                                  // przesy�amy SP na wyj�cie
  {
    v = SP[--SPp];
    if(SPp) cout << v << " ";
  } while(SPp);

  cout << endl;

  delete [] SL;                       // usuwamy stosy
  delete [] SP;

  return 0;
} 
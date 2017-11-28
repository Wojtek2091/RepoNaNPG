// Wyszukiwanie w drzewie BST
// Data: 24.04.2013
// (C)2013 mgr Jerzy Wa�aszek
//------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// Typ w�z��w drzewa BST

struct BSTNode
{
  BSTNode * left;
  BSTNode * right;
  int key;
};

// Funkcja wczytuje drzewo BST ze standardowego
// wej�cia i zwraca wskazanie korzenia.
//-----------------------------------------------
BSTNode * readBST()
{
  BSTNode ** vp;    // Tablica wskaza� w�z��w
  int key,l,r,i,n;

  cin >> n;                 // Odczytujemy liczb� w�z��w drzewa

  vp = new BSTNode * [n];   // Tworzymy dynamiczn� tablic� wskaza� w�z��w

  // Tablic� dynamiczn� wype�niamy wskazaniami w�z��w,
  // kt�re r�wnie� tworzymy dynamicznie

  for(i = 0; i < n; i++) vp[i] = new BSTNode;

  // Teraz wczytujemy definicj� drzewa i tworzymy jego struktur�
  // w pami�ci wype�niaj�c odpowiednie pola w�z��w.

  for(i = 0; i < n; i++)
  {
    cin >> key >> l >> r;   // Czytamy klucz, numer lewego i prawego syna

    vp[i]->key = key;       // Ustawiamy klucz

    vp[i]->left  = l ? vp[l]: NULL;  // Ustawiamy lewego syna

    vp[i]->right = r ? vp[r]: NULL;  // Ustawiamy prawego syna

  }

  BSTNode * p = vp[0];      // Zapami�tujemy korze�

  delete [] vp;             // Usuwamy tablic� dynamiczn�

  return p;
}

// Funkcja szuka w drzewie BST w�z�a o zadanym kluczu.
// Je�li go znajdzie, zwraca jego wskazanie. Je�eli nie,
// to zwraca wskazanie puste.
// Parametrami s�:
// p - wskazanie korzenia drzewa BST
// k - klucz poszukiwanego w�z�a
//----------------------------------------------------
BSTNode * findBST(BSTNode * p, int k)
{
  while(p && p->key != k)
    p = (k < p->key) ? p->left: p->right;

  return p;
}

// Funkcja zwraca wskazanie w�z�a o najmniejszym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * minBST(BSTNode * p)
{
  if(p) while(p->left) p = p->left;

  return p;
}

// Funkcja zwraca wskazanie w�z�a o najwi�kszym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * maxBST(BSTNode * p)
{
  if(p) while(p->right) p = p->right;

  return p;
}
BSTNode * maxBST(BSTNode * p)
{
  if(p) while(p->right) p = p->right;

  return p;
}

BSTNode * maxBST(BSTNode * p)
{
  if(p) while(p->right) p = p->right;

  return p;
}

BSTNode * maxBST(BSTNode * p)
{
  if(p) while(p->right) p = p->right;

  return p;
}


// Procedura DFS:postorder usuwaj�ca drzewo
//-----------------------------------------
void DFSRelease(BSTNode * v)
{
  if(v)
  {
    DFSRelease(v->left);   // usuwamy lewe poddrzewo
    DFSRelease(v->right);  // usuwamy prawe poddrzewo
    delete v;              // usuwamy sam w�ze�
  }
}

// **********************
// *** PROGRAM G��WNY ***
// **********************

int main()
{
  BSTNode * root, * p;
  int k, mink, maxk;

  root = readBST();     // Odczytujemy drzewo BST

  if(root)
  {
    mink = minBST(root)->key; // Odczytujemy klucz minimalny
    maxk = maxBST(root)->key; // Odczytujemy klucz maksymalny

    // Przechodzimy przez kolejne warto�ci kluczy

    for(k = mink; k <= maxk; k++)
    {
      p = findBST(root,k);    // szukamy w�z�a o kluczu k

      cout << "KEY = " << setw(3) <<  k << " : ";

      if(p)
      {
        if (!p->left && !p->right) cout << "LEAF";
        else                       cout << "INNER NODE";
      }
      else cout << "NONE";

      cout << endl;
    }
  }
  else cout << "BST is empty!!!" << endl;

  DFSRelease(root);    // usuwamy drzewo z pami�ci

  return 0;
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
} 

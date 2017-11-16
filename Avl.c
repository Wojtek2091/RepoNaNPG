// Drzewo AVL
// Data: 22.05.2013
// (C)2013 mgr Jerzy Wa�aszek
//------------------------------

#include <wcalenieiostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definicja typu w�z��w drzewa AVL
//---------------------------------
struct AVLNode
{
  AVLNode * up, * left, * right;
  int key, bf;
};

// Zmienne globalne
//-----------------

string cr,cl,cp;      // �a�cuchy do znak�w ramek

// Procedura wypisuje drzewo
//--------------------------
void printBT(string sp, string sn, AVLNode * v)
{
  string s;

  if(v)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printBT(s + cp, cr, v->right);

    s = s.substr(0,sp.length()-2);
    cout << s << sn << v->key << ":" << v->bf << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printBT(s + cp, cl, v->left);
  }
}

// Procedura DFS:postorder usuwaj�ca drzewo
//-----------------------------------------
void DFSRelease(AVLNode * v)
{
  if(v)
  {
    DFSRelease(v->left);   // usuwamy lewe poddrzewo
    DFSRelease(v->right);  // usuwamy prawe poddrzewo
    delete v;              // usuwamy sam w�ze�
  }
}

// Rotacja RR
//-----------
void RR(AVLNode * & root, AVLNode * A)
{
  AVLNode * B = A->right, * p = A->up;

  A->right = B->left;
  if(A->right) A->right->up = A;

  B->left = A;
  B->up = p;
  A->up = B;

  if(p)
  {
    if(p->left == A) p->left = B; else p->right = B;
  }
  else root = B;

  if(B->bf == -1) A->bf = B->bf = 0;
  else
  {
    A->bf = -1; B->bf = 1;
  }
}

// Rotacja LL
//-----------
void LL(AVLNode * & root, AVLNode * A)
{
  AVLNode * B = A->left, * p = A->up;

  A->left = B->right;
  if(A->left) A->left->up = A;

  B->right = A;
  B->up = p;
  A->up = B;

  if(p)
  {
    if(p->left == A) p->left = B; else p->right = B;
  }
  else root = B;

  if(B->bf == 1) A->bf = B->bf = 0;
  else
  {
    A->bf = 1; B->bf = -1;
  }
}

// Rotacja RL
//-----------
void RL(AVLNode * & root, AVLNode * A)
{
  AVLNode * B = A->right, * C = B->left, * p  = A->up;

  B->left = C->right;
  if(B->left) B->left->up = B;

  A->right = C->left;
  if(A->right) A->right->up = A;

  C->left = A;
  C->right = B;
  A->up = B->up = C;
  C->up = p;

  if(p)
  {
    if(p->left == A) p->left = C; else p->right = C;
  }
  else root = C;

  if(C->bf == -1) A->bf =  1; else A->bf = 0;
  if(C->bf ==  1) B->bf = -1; else B->bf = 0;

  C->bf = 0;
}

// Rotacja LR
//-----------
void LR(AVLNode * & root, AVLNode * A)
{
  AVLNode * B = A->left, * C = B->right, * p = A->up;

  B->right = C->left;
  if(B->right) B->right->up = B;

  A->left = C->right;
  if(A->left) A->left->up = A;

  C->right = A;
  C->left = B;
  A->up = B->up = C;
  C->up = p;

  if(p)
  {
    if(p->left == A) p->left = C; else p->right = C;
  }
  else root = C;

  if(C->bf ==  1) A->bf = -1; else A->bf = 0;
  if(C->bf == -1) B->bf =  1; else B->bf = 0;

  C->bf = 0;
}

// Wstawia nowy w�ze� do drzewa AVL
// root - referencja korzenia
// k    - klucz nowego w�z�a
//---------------------------------
void insertAVL(AVLNode * & root, int k)
{
  AVLNode * w,* p,* r;
  bool t;

  w = new AVLNode;        // tworzymy dynamicznie nowy w�ze�
  w->left = w->right = w->up = NULL;
  w->key  = k;
  w->bf  = 0;

  //----------------------------------------
  // FAZA 1 - wstawienie w�z�a do drzewa AVL
  //----------------------------------------

  p = root;              // rozpoczynamy od korzenia

  if(!p) root = w;       // je�li drzewo jest puste, to w�ze� w umieszczamy w korzeniu
  else
  {                      // inaczej szukamy miejsce dla w
    while(true)
      if(k < p->key)     // por�wnujemy klucze
      {
        if(!p->left)     // je�li p nie posiada lewego syna, to
        {
          p->left = w;   // lewym synem p staje si� w�ze� w
          break;         // wychodzimy z p�tli
        }
        p = p->left;     // inaczej przechodzimy do lewego syna
      }
      else
      {
        if(!p->right)    // je�li p nie posiada prawego syna, to
        {
          p->right = w;  // prawym synem staje si� w�ze� w
          break;         // wychodzimy z p�tli
        }
        p = p->right;    // inaczej przechodzimy do prawego syna
      }

    w->up = p;           // ojcem w jest p

    //---------------------------------
    // FAZA 2 - r�wnowa�enie drzewa AVL
    //---------------------------------

    if(p->bf) p->bf = 0; // UWAGA NR 1
    else
    {
      if(p->left == w)   // UWAGA NR 2
        p->bf = 1;
      else
        p->bf = -1;

      r = p->up;        // b�dziemy szli w g�r� drzewa w kierunku korzenia
                        // r i p wskazuj� ojca i syna na tej �cie�ce
      t = false;
      while(r)
      {
        if(r->bf)
        {
          t = true;     // ustalamy wynik p�tli
          break;        // przerywamy p�tl�
        };
                        // inaczej modyfikujemy r.bf
        if(r->left == p) r->bf =  1;
        else             r->bf = -1;

        p = r;          // przechodzimy w g�r� na wy�szy poziom
        r = r->up;
      }

      if(t)             // je�li r.bf = +/- 1, to musimy
      {                 // r�wnowa�y� drzewo
        if(r->bf == 1)
        {
          if(r->right == p) r->bf = 0;  // ga��zie si� r�wnowa��
          else if(p->bf == -1) LR(root,r);
          else                 LL(root,r);
        }
        else
        {              // r.bf = -1
          if(r->left == p) r->bf = 0;  // ga��zie si� r�wnowa��
          else if(p->bf == 1) RL(root,r);
          else                RR(root,r);
        }
      }
    }
  }
}

// Funkcja znajduje poprzednik w�z�a p
//------------------------------------
AVLNode * predAVL(AVLNode * p)
{
  AVLNode * r;

  if(p)
  {
    if(p->left)
    {
      p = p->left;
      while(p->right) p = p->right;
    }
    else
      do
      {
        r = p;
        p = p->up;
      } while(p && p->right != r);
  }
  return p;
}

// Funkcja szuka w drzewie AVL w�z�a o zadanym kluczu.
// Je�li go znajdzie, zwraca jego wskazanie. Je�eli nie,
// to zwraca wskazanie puste.
// Parametrami s�:
// p - wskazanie korzenia drzewa AVL
// k - klucz poszukiwanego w�z�a
//----------------------------------------------------
AVLNode * findAVL(AVLNode * p, int k)
{
  while(p && p->key != k)
    p = (k < p->key) ? p->left: p->right;

  return p;
}

// Funkcja usuwa rekurencyjnie w�ze� x
// root - referencja do zmiennej z adresem korzenia
// x - wskazanie usuwanego w�z�a
//-------------------------------------------------
AVLNode * removeAVL(AVLNode * & root, AVLNode * x)
{
  AVLNode  *t,*y,*z;
  bool nest;

  if(x->left && x->right)
  {
    y    = removeAVL(root,predAVL(x));
    nest = false;
  }
  else
  {
    if(x->left)
    {
      y = x->left; x->left = NULL;
    }
    else
    {
      y = x->right; x->right = NULL;
    }
    x->bf = 0;
    nest  = true;
  }

  if(y)
  {
    y->up    = x->up;
    y->left  = x->left;  if(y->left)  y->left->up  = y;
    y->right = x->right; if(y->right)  y->right->up = y;
    y->bf    = x->bf;
  }

  if(x->up)
  {
    if(x->up->left == x) x->up->left = y; else x->up->right = y;
  }
  else root = y;

  if(nest)
  {
    z = y;
    y = x->up;
    while(y)
    {
      if(!y->bf)
      {              // Przypadek nr 1
        if(y->left == z)  y->bf = -1; else y->bf = 1;
        break;
      }
      else
      {
        if(((y->bf == 1) && (y->left == z)) || ((y->bf == -1) && (y->right == z)))
        {           // Przypadek nr 2
          y->bf = 0;
          z = y; y = y->up;
        }
        else
        {
          if(y->left == z)  t = y->right; else t = y->left;
          if(!t->bf)
          {         // Przypadek 3A
            if(y->bf == 1) LL(root,y); else RR(root,y);
            break;
          }
          else if(y->bf == t->bf)
          {         // Przypadek 3B
            if(y->bf == 1) LL(root,y); else RR(root,y);
            z = t; y = t->up;
          }
          else
          {         // Przypadek 3C
            if(y->bf == 1) LR(root,y); else RL(root,y);
            z = y->up; y = z->up;
          }
        }
      }
    }
  }
  return x;
}

//**********************
//*** PROGRAM G��WNY ***
//**********************

int main()
{
  int Tk[32];   // tablica kluczy w�z��w
  int i,x,i1,i2;
  AVLNode * root = NULL;

  // ustawiamy �a�cuchy znakowe, poniewa� nie wszystkie edytory pozwalaj�
  // wstawia� znaki konsoli do tworzenia ramek.
  // cr = +--
  //      |

  // cl = |
  //      +--

  // cp = |
  //      |

  cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;

  srand(time(NULL));        // inicjujemy generator pseudolosowy

  for(i = 0; i < 32; i++)   // Tablic� wype�niamy warto�ciami kluczy
    Tk[i] = i + 1;

  for(i = 0; i < 300; i++)  // Mieszamy tablic�
  {
    i1 = rand() % 32;       // Losujemy 2 indeksy
    i2 = rand() % 32;

    x = Tk[i1];             // Wymieniamy Tk[i1] <--> Tk[i2]
    Tk[i1] = Tk[i2];
    Tk[i2] = x;
  }

  for(i = 0; i < 32; i++)   // Na podstawie tablicy tworzymy drzewo AVL
  {
    cout << Tk[i] << " ";
    insertAVL(root,Tk[i]);
  }

  cout << endl << endl;

  printBT("","",root);      // Wy�wietlamy zawarto�� drzewa AVL

  cout << endl << endl;

  for(i = 0; i < 300; i++)  // Ponownie mieszamy tablic�
  {
    i1 = rand() % 32; i2 = rand() % 32;
    x = Tk[i1]; Tk[i1] = Tk[i2]; Tk[i2] = x;
  }

  for(i = 0; i < 15; i++)    // Usuwamy 15 w�z��w
  {
    cout << Tk[i] << " ";
    removeAVL(root,findAVL(root,Tk[i]));
  }

  cout << endl << endl;

  printBT("","",root);      // Wy�wietlamy zawarto�� drzewa AVL

  DFSRelease(root);         // Usuwamy drzewo AVL z pami�ci

  return 0;
}

type
  PBTNode = ^BTNode;
  BTNode  = record
    left  : PBTNode;
    right : PBTNode;
    data  : char;
  end;

// Typ tablicy wskaza� w�z��w

  TBTNode = array of PBTNode;

// Definicja typu obiektowego queue
//---------------------------------

  queue = object
    private
      n    : integer;    // rozmiar tablicy
      qptr : integer;    // wska�nik pocz�tku kolejki
      qcnt : integer;    // licznik element�w
      Q    : TBTNode; // tablica dynamiczna wskaza� w�z��w drzewa

    public
      constructor init(x : integer);
      destructor destroy;
      function empty : boolean;
      function front : PBTNode;
      procedure push(v : PBTNode);
      procedure pop;
  end;

//---------------------
// Metody obiektu queue
//---------------------

// Konstruktor - tworzy tablic� dla kolejki
//-----------------------------------------
constructor queue.init(x : integer);
begin
  n := x;
  SetLength(Q,x);
  qptr := 0;  // pocz�tek kolejki na pocz�tku tablicy
  qcnt := 0;  // pusta kolejka
end;


destructor queue.destroy;
begin
  SetLength(Q,0);
end;

// Sprawdza, czy kolejka jest pusta
//---------------------------------
function queue.empty : boolean;
begin
  if qcnt = 0 then empty := true
  else empty := false;
end;

// Zwraca pocz�tek kolejki.
// Warto�� specjalna to nil
//-----------------------------
function queue.front : PBTNode;
begin
  if qcnt = 0 then front := nil
  else             front := Q[qptr];

end;

// Zapisuje do kolejki
//--------------------
procedure queue.push(v : PBTNode);
var
  i : integer;
begin
  if qcnt < n then
  begin
    i := qptr + qcnt;
    if i >= n then dec(i,n);
    Q[i] := v;
    inc(qcnt);
  end;
end;

// Usuwa z kolejki
//----------------
procedure queue.pop;
begin
  if qcnt > 0 then
  begin
    dec(qcnt);
    inc(qptr);
    if qptr = n then qptr := 0;
  end;
end;

// Tworzenie struktury drzewa rozpoczynamy od li�ci

var

  G : BTNode = (left:nil; right:nil; data:'G');
  H : BTNode = (left:nil; right:nil; data:'H');
  I : BTNode = (left:nil; right:nil; data:'I');
  J : BTNode = (left:nil; right:nil; data:'J');
  K : BTNode = (left:nil; right:nil; data:'K');

// Tworzymy kolejnych ojc�w

  D : BTNode = (left: @H; right: @I; data:'D');
  E : BTNode = (left: @J; right:nil; data:'E');
  F : BTNode = (left: @K; right:nil; data:'F');
  B : BTNode = (left: @D; right: @E; data:'B');
  C : BTNode = (left: @F; right: @G; data:'C');

// Korze� drzewa

  A : BTNode = (left: @B; right: @C; data:'A');

  Q : queue;      // kolejka

  v : PBTNode; // wskazanie w�z�a

begin

  Q.init(8);   // rozmiar kolejki r�wny 2^3, gdzie 3 jest wysoko�ci� drzewa

  Q.push(@A);  // w kolejce umieszczamy wskazanie w�z�a A

  while not Q.empty do
  begin

    v := Q.front;  // pobieramy element z kolejki

    Q.pop;         // pobrany element usuwamy z kolejki

    write(v^.data,' '); // odwiedzamy w�ze�

    // w kolejce umieszczamy syn�w w�z�a wskazywanego przez v

    if v^.left  <> nil then Q.push(v^.left);  // lewy syn

    if v^.right <> nil then Q.push(v^.right); // prawy syn

  end;

  writeln;

  Q.destroy;

end. 
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------
// Destruktor - zwalnia tablic� dynamiczn�
//----------------------------------------


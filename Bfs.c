
type
  PBTNode = ^BTNode;
  BTNode  = record
    left  : PBTNode;
    right : PBTNode;
    data  : char;
  end;

// Typ tablicy wskazañ wêz³ów

  TBTNode = array of PBTNode;

// Definicja typu obiektowego queue
//---------------------------------

  queue = object
    private
      n    : integer;    // rozmiar tablicy
      qptr : integer;    // wskaŸnik pocz¹tku kolejki
      qcnt : integer;    // licznik elementów
      Q    : TBTNode; // tablica dynamiczna wskazañ wêz³ów drzewa

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

// Konstruktor - tworzy tablicê dla kolejki
//-----------------------------------------
constructor queue.init(x : integer);
begin
  n := x;
  SetLength(Q,x);
  qptr := 0;  // pocz¹tek kolejki na pocz¹tku tablicy
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

// Zwraca pocz¹tek kolejki.
// Wartoœæ specjalna to nil
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

// Tworzenie struktury drzewa rozpoczynamy od liœci

var

  G : BTNode = (left:nil; right:nil; data:'G');
  H : BTNode = (left:nil; right:nil; data:'H');
  I : BTNode = (left:nil; right:nil; data:'I');
  J : BTNode = (left:nil; right:nil; data:'J');
  K : BTNode = (left:nil; right:nil; data:'K');

// Tworzymy kolejnych ojców

  D : BTNode = (left: @H; right: @I; data:'D');
  E : BTNode = (left: @J; right:nil; data:'E');
  F : BTNode = (left: @K; right:nil; data:'F');
  B : BTNode = (left: @D; right: @E; data:'B');
  C : BTNode = (left: @F; right: @G; data:'C');

// Korzeñ drzewa

  A : BTNode = (left: @B; right: @C; data:'A');

  Q : queue;      // kolejka

  v : PBTNode; // wskazanie wêz³a

begin

  Q.init(8);   // rozmiar kolejki równy 2^3, gdzie 3 jest wysokoœci¹ drzewa

  Q.push(@A);  // w kolejce umieszczamy wskazanie wêz³a A

  while not Q.empty do
  begin

    v := Q.front;  // pobieramy element z kolejki

    Q.pop;         // pobrany element usuwamy z kolejki

    write(v^.data,' '); // odwiedzamy wêze³

    // w kolejce umieszczamy synów wêz³a wskazywanego przez v

    if v^.left  <> nil then Q.push(v^.left);  // lewy syn

    if v^.right <> nil then Q.push(v^.right); // prawy syn

  end;

  writeln;

  Q.destroy;

end. 

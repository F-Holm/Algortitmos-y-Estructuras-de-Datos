program SumaDePolinomios;
{
  Id.Programa: SumaPoli.Pas
  Autor......: Prof. Hugo Cuello
  Fecha......: nov-2013
  Comentario.: Genera en forma arbitraria y al azar
               polinomios P y Q, ord. x expo descendente.
               Se pide:
                 Realizar la suma de P + Q --> R
}

uses
  crt,
  DSumPoli;

const
  LOW_VALUE = -1;

procedure ObTerPoli(var valor : tInfo; NomPoli : char);
begin
  clrscr;
  gotoxy(10,1);
  write('Datos de un termino del Polinomio ',NomPoli);
  gotoxy(15,5);
  write('expo: ');
  readln(valor.expo);
  gotoxy(15,7);
  write('coef: ');
  readln(valor.coef)
end; { ObTerPoli }

function Menu : char;
var
  opc : char;

begin
  clrscr;
  gotoxy(10,1);
  write('Suma de polinomios');
  gotoxy(15,5);
  write('1: Termino P');
  gotoxy(15,7);
  write('2: Termino Q');
  gotoxy(15,9);
  write('3: Salir');
  gotoxy(20,12);
  write('Su opcion: ');
  repeat
    opc:= readkey
  until opc in ['1'..'3'];
  Menu:= opc
end; { Menu }

procedure LecEspLst(var Px : tLista; var valor : tInfo);
begin
  if Px <> nil then
    SacarPrimerNodo(Px,valor)
  else
    valor.expo:= LOW_VALUE
end; { LecEspLst }

procedure SumarPoli(var P,Q,R : tLista);
var
  RFin   : tLista;
  rInfoP,
  rInfoQ,
  rInfoR : tInfo;

begin
  RFin:= nil;
  LecEspLst(P,rInfoP);
  LecEspLst(Q,rInfoQ);
  while (rInfoP.expo <> LOW_VALUE) or (rInfoQ.expo <> LOW_VALUE) do
    if rInfoP.expo = rInfoQ.expo then begin
      rInfoR.expo:= rInfoP.expo;
      rInfoR.coef:= rInfoP.coef + rInfoQ.coef;
      AgregarNodo(R,RFin,rInfoR);
      LecEspLst(P,rInfoP);
      LecEspLst(Q,rInfoQ)
    end
    else
      if rInfoP.expo > rInfoQ.expo then begin
        AgregarNodo(R,RFin,rInfoP);
        LecEspLst(P,rInfoP)
      end
      else begin
        AgregarNodo(R,RFin,rInfoQ);
        LecEspLst(Q,rInfoQ)
      end
end; { SumaPoli }

procedure EmitirPoli(var Px : tLista; NomPoli : char);
var
  PxAux : tLista;

begin
  writeln;
  write(NomPoli,' = ');
  PxAux:= Px;
  while PxAux <> nil do begin
    write(PxAux^.Info.coef:6:2,' ');
    if PxAux^.Info.expo > 0 then
      write('x^',PxAux^.Info.expo,' +');
    PxAux:= PxAux^.Sgte
  end;
  writeln(chr(8),' Enter para continuar...');
  readln
end; { EmitirPoli }

procedure LiberarNodos(var Px : tLista);
var
  valor : tInfo;

begin
  while Px <> nil do
    SacarPrimerNodo(Px,valor)
end; { LiberarNodos }

var { Globales }
  P, Q, R : tLista;
  valor   : tInfo;
  opc     : char;

begin { Bloque Ppal }
  P:= nil;
  Q:= nil;
  R:= nil;
  repeat
    opc:= Menu;
    case opc of
      '1': begin
             ObTerPoli(valor,'P');
             InsertaNodo(P,valor);
           end;
      '2': begin
             ObTerPoli(valor,'Q');
             InsertaNodo(Q,valor)
           end
    end
  until opc = '3';
  EmitirPoli(P,'P');
  EmitirPoli(Q,'Q');
  SumarPoli(P,Q,R);
  EmitirPoli(R,'R');
  LiberarNodos(R)
end. { Bloque Ppal }

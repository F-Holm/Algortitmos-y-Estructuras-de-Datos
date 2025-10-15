
unit DSumPoli;

interface { Parte Publica }

type
  tInfo = record
    expo : shortint;
    coef : real
  end;
  tLista = ^tNodo;
  tNodo = record
    Info : tInfo;
    Sgte : tLista
  end;

procedure InsertaNodo(var Lista:tLista; Info:tInfo);
procedure AgregarNodo(var Lista,ListaFin:tLista;Info:tInfo);
procedure SacarPrimerNodo(var Lista:tLista; var Info:tInfo);

implementation { Parte Privada }

procedure InsertaInicio(var Lista:tLista; Info:tInfo);
var        { Enlaza el nvoNodo al inicio de la Lista }
  pNvoNodo: tLista;

begin
  new(pNvoNodo);
  pNvoNodo^.Info:= Info;
  pNvoNodo^.Sgte:= Lista;
  Lista:= pNvoNodo
end; {InsertaInicio}

procedure InsertaEnMedio(var Lista:tLista; Info:tInfo);
var        { Enlaza el nvoNodo despues del primer nodo en adelante }
  pAct,
  pNvoNodo:tLista;

begin
  new(pNvoNodo);
  pNvoNodo^.Info:= Info;
  pAct:= Lista;
  while (pAct^.Sgte <> nil) and (Info.expo<pAct^.Sgte^.Info.expo) do
    pAct:= pAct^.Sgte;
  pNvoNodo^.Sgte:= pAct^.Sgte;
  pAct^.Sgte:= pNvoNodo
end; {InsertaEnMedio}

procedure InsertaNodo(var Lista:tLista; Info:tInfo);
begin      { Modulo despachador a InsertaInicio o InsertaEnMedio }
  if (Lista = nil) or (Info.expo > Lista^.Info.expo) then
    InsertaInicio(Lista,Info)
  else
    InsertaEnMedio(Lista,Info)
end; {InsertaNodo}

procedure AgregarNodo(var Lista,ListaFin:tLista;Info:tInfo);
var            { Enlaza el nvoNodo al final de la Lista sin recorrerla }
  pNvoNodo:tLista; { Lista tratada como Cola al incorporar un elemento }

begin
  new(pNvoNodo);
  pNvoNodo^.Info:= Info;
  pNvoNodo^.Sgte:= nil;
  if Lista = nil then
    Lista:= pNvoNodo
  else
    ListaFin^.Sgte:= pNvoNodo;
  ListaFin:= pNvoNodo
end; {AgregarNodo}

procedure SacarPrimerNodo(var Lista:tLista; var Info:tInfo);
var        { Elimina el primer nodo de la Lista }
  pLib:tLista;

begin
  pLib:= Lista;
  Info:= Lista^.Info;
  Lista:= Lista^.Sgte;
  dispose(pLib)
end; {SacarPrimerNodo}

begin { Parte de Inicializacion de la Unidad }

end.


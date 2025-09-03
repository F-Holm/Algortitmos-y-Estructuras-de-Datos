/*
    Id.Programa: G4Ej07DiscoEnc.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: jun-2014
    Comentario.: Ranking de temas musicales (1..30).
                    1. Listado de Ranking.
                    2. Nro.Tema +Votado por H30+.
                    3. Nros. de Temas no votados por las Mujeres.
*/

#include <iomanip>
#include <iostream>
using namespace std;

const MAX_TEMAS = 30;

typedef unsigned char byte;
typedef unsigned short word;

struct trEnc {
  char Sexo;
  byte Edad, NroTemas[3];
};
struct trRank {
  byte NroTema;
  word Votos, H30;
  bool Mujer;
};

typedef trRank
    tvrRank[MAX_TEMAS + 1];  // tvrRank es el tipo arreglo de registro
                             // el +1 es un ajuste para no empezar pos. 0.

// Prototipos ---------------------
void Abrir(FILE **);
void IniTbl(tvrRank);
void AcumVotos(tvrRank, trEnc);
void IntCmb(trRank &, trRank &);
void OrdxBur(tvrRank, byte);
byte MayNroTemaH30(tvrRank);
void EmitePtoB(byte);
void EmitePtoC(tvrRank);
void EmitePtoA(tvrRank);
// Fin Prototipos -----------------

void Abrir(FILE **Enc) {
  *Enc = fopen("Encuestas.Dat", "rb");
}  // Abrir

void IniTbl(tvrRank vrRank) {
  trRank rRank;

  rRank.Votos = rRank.H30 = 0;
  rRank.Mujer = false;
  for (byte i = 1; i <= MAX_TEMAS;
       i++) {  // pos.0 en vrRank no se toma en cuenta.
    rRank.NroTema = i;
    vrRank[i] = rRank;
  }
}  // IniTbl

void AcumVotos(tvrRank vrRank, trEnc rEnc) {
  byte nTema;

  for (byte i = 0; i <= 2; i++) {
    nTema = rEnc.NroTemas[i];
    vrRank[nTema].Votos++;
    if (rEnc.Sexo == 'F')
      vrRank[nTema].Mujer = true;
    else if (rEnc.Edad >= 30)
      vrRank[nTema].H30++;
  }
}  // AcumVotos

void IntCmb(trRank &elem1, trRank &elem2) {
  trRank aux = elem1;

  elem1 = elem2;
  elem2 = aux;
}  // IntCmb

void OrdxBur(tvrRank vrRank, byte card) {
  bool ordenado;
  byte k = 0;

  do {
    ordenado = true;
    k++;
    for (byte i = 1; i <= card - k; i++)
      if (vrRank[i].Votos < vrRank[i + 1].Votos) {
        ordenado = false;
        IntCmb(vrRank[i], vrRank[i + 1]);
      }
  } while (!ordenado);
}  // OrdxBur

byte MayNroTemaH30(tvrRank vrRank) {
  byte nTema = 1;

  for (byte i = 2; i <= MAX_TEMAS; i++)
    if (vrRank[i].H30 > vrRank[nTema].H30)
      nTema = i;
  return nTema;
}  // MayNroTemaH30

void EmitePtoB(byte nTema) {
  freopen("Encuestas30TemasDisco.Lst", "w", stdout);
  cout << "El nro. de tema + votado por los H30+: " << (short)nTema << endl;
}  // EmitePtoB

void EmitePtoC(tvrRank vrRank) {
  cout << endl << "Nros. de temas no votados por Mujeres" << endl;
  cout << "   Nro.Tema" << endl;
  for (byte i = 1; i <= MAX_TEMAS; i++)
    if (!vrRank[i].Mujer)
      cout << "     " << setw(2) << (short)i << endl;
}  // EmitePtoC

void EmitePtoA(tvrRank vrRank) {
  cout << endl << "Listado de Ranking de Temas Musicales" << endl;
  cout << "  Nro.Ord.  Nro.Tema Cant.Votos" << endl;
  for (byte i = 1; i <= MAX_TEMAS; i++)
    cout << "     " << setw(2) << (short)i << "        " << setw(2)
         << (short)vrRank[i].NroTema << setw(6) << "" << setw(4)
         << vrRank[i].Votos << endl;
  freopen("CON", "w", stdout);
}  // EmitePtoA

int main() {
  FILE *Encuestas;
  trEnc rEncuesta;
  tvrRank vrRanking;

  Abrir(&Encuestas);
  IniTbl(vrRanking);
  while (fread(&rEncuesta, sizeof(rEncuesta), 1, Encuestas))
    AcumVotos(vrRanking, rEncuesta);
  EmitePtoB(MayNroTemaH30(vrRanking));
  EmitePtoC(vrRanking);
  OrdxBur(vrRanking, MAX_TEMAS);
  EmitePtoA(vrRanking);
  fclose(Encuestas);

  return 0;
}

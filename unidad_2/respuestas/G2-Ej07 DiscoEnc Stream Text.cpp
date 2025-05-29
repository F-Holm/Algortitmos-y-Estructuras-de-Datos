/*
    Id.Programa: G2-Ej07 DiscoEnc Stream Text.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: jun-2014
    Comentario.: Ranking de temas musicales (1..30).
                    1. Listado de Ranking.
                    2. Nro.Tema +Votado por Hom30+.
                    3. Nros. de Temas no votados por las Mujeres.
    Lenguaje...: Borland V. 5.5.
*/

#include<iomanip>
#include<fstream>
using namespace std;

const
  MAX_TEMAS = 30;

typedef unsigned short ushort;

struct tsEnc {
  char  Sexo;
  short Edad,
        NroTemas[3];
};

struct tsRank {
  short NroTema;
  ushort Votos,
       Hom30;
  bool Mujer;
};

typedef tsRank tvsRank[MAX_TEMAS + 1]; // tvsRank es el tipo arreglo de registro
                                       // el +1 ajuste para no empezar pos. 0.

// Prototipos ---------------------
void IniTbl(tvsRank);
void AcumVotos(tvsRank , tsEnc );
void IntCmb(tsRank &,tsRank &);
void OrdxBur(tvsRank ,short );
short MayNroTemaHom30(tvsRank );
void EmitePtoB(short );
void EmitePtoC(tvsRank );
void EmitePtoA(tvsRank );
// Fin Prototipos -----------------

void IniTbl(tvsRank vrRank) {
  tsRank rRank;

  rRank.Votos = rRank.Hom30 = 0;
  rRank.Mujer = false;
  for (short i = 1; i <= MAX_TEMAS; i++) { //pos.0 vrRank no se toma en cuenta.
    rRank.NroTema = i;
    vrRank[i] = rRank;
  }
} //IniTbl

bool LeeUnReg(ifstream &Enc, tsEnc &rEnc){
  Enc >> rEnc.Sexo >> rEnc.Edad;
  for (short i = 0; i <= 2; i++)
    Enc >> rEnc.NroTemas[i];
  cout << rEnc.Sexo << ' ' << rEnc.Edad << ' '
       << rEnc.NroTemas[0] << ' '
       << rEnc.NroTemas[1] << ' '
       << rEnc.NroTemas[2] << endl;
  // Enc.ignore();
  return Enc.good();
} // LeeUnReg

void AcumVotos(tvsRank vrRank, tsEnc rEnc) {
  short nTema;

  for (short i = 0; i <= 2; i++) {
    nTema = rEnc.NroTemas[i]; // haciendo una copia
    vrRank[nTema].Votos++;
    if (rEnc.Sexo == 'F')
      vrRank[nTema].Mujer = true;
    else
      if (rEnc.Edad >= 30)
        vrRank[nTema].Hom30++;
  }
} //AcumVotos

void IntCmb(tsRank &elem1,tsRank &elem2) {
  tsRank aux = elem1;

  elem1 = elem2;
  elem2 = aux;
} // IntCmb

void OrdxBur(tvsRank vrRank,short card) {
  bool ordenado;
  short  k = 0;

  do {
    ordenado = true;
    k++;
    for (short i = 1; i <= card - k; i++)
      if (vrRank[i].Votos < vrRank[i + 1].Votos) {
        ordenado = false;
        IntCmb(vrRank[i],vrRank[i + 1]);
      }
  }
  while (!ordenado);
} // OrdxBur

short MayNroTemaHom30(tvsRank vrRank) {
  short nTema = 1;

  for (short i = 2; i <= MAX_TEMAS; i++)
    if (vrRank[i].Hom30 > vrRank[nTema].Hom30)
      nTema = i;
  return nTema;
} //MayNroTemaHom30

void EmitePtoB(short nTema) {

  cout << "Por ahora sale en la Pantalla" << endl;
  freopen("Encuestas30TemasDisco.Lst","w",stdout);
  cout << "El nro. de tema + votado por los Hom30+: " << (short) nTema << endl;
} //EmitePtoB

void EmitePtoC(tvsRank vrRank) {

  cout << endl << "Nros. de temas no votados por Mujeres" << endl;
  cout << "   Nro.Tema" << endl;
  for (short i = 1; i <= MAX_TEMAS; i++)
    if (!vrRank[i].Mujer)
      cout << "     " << setw(2) << (short) i << endl;
} //EmitePtoC

void EmitePtoA(tvsRank vrRank) {

  cout << endl << "Listado de Ranking de Temas Musicales" << endl;
  cout << "  Nro.Ord.  Nro.Tema Cant.Votos" << endl;
  for (short i = 1; i <= MAX_TEMAS; i++)
    cout << "     " << setw(2) << (short) i << "        "
                    << setw(2) << (short) vrRank[i].NroTema << setw(6) << ""
                    << setw(4) << vrRank[i].Votos << endl;
  freopen("CON","w",stdout);
  cout <<"Vuelvo a la pantalla";
} //EmitePtoA

int main() {
  ifstream Encuestas("Encuestas.Txt");
  tsEnc   rEncuesta;
  tvsRank vrRanking; //tsRank  vrRanking[MAX_TEMAS+1];

  IniTbl(vrRanking); // NroTema: Pos i, Votos: 0, Hom30: 0, Mujer: false.
  while (LeeUnReg(Encuestas,rEncuesta))
    AcumVotos(vrRanking,rEncuesta);
  EmitePtoB(MayNroTemaHom30(vrRanking));
  EmitePtoC(vrRanking);
  OrdxBur(vrRanking,MAX_TEMAS);
  EmitePtoA(vrRanking);
  Encuestas.close();
  return 0;
}

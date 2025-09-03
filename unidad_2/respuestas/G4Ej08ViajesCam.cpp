/*
    Id.Programa: G4Ej08ViajesCam.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: agosto-2014
    Comentario.: Viajes de Camioneros con material fragil (1..Max.100).
                    1. Listado de Camioneros ord. x Cant.Unid.Rotas asc.

*/

#include <fstream>
#include <iomanip>
using namespace std;

const MAX_CAM = 100;

typedef char str5[6];
typedef unsigned char byte;
typedef unsigned short word;

struct trVia {
  str5 CodLeg;
  byte CodPcia;
  word CantRotas;
};

struct trCam {
  str5 CodLeg;
  byte CantVjes;
  word CantUniRotas;
};

typedef trCam tvrCam[MAX_CAM + 1];  // tvrRank es el tipo arreglo de registro

// Prototipos ------------------------------
void Abrir(FILE **);
void AcumViajes(tvrCam, trVia, byte &);
void IntCmb(trCam &, trCam &);
void OrdxBur(tvrCam, byte);
void Listado(tvrCam, byte);
// Fin Prototipos --------------------------

void Abrir(FILE **Vje) {
  *Vje = fopen("Viajes.Dat", "rb");
}  // Abrir

byte BusLinVec(tvrCam vrCam, str5 nLeg, byte card) {
  byte i = 1;

  while (i <= card && strcmp(nLeg, vrCam[i].CodLeg) != 0)
    i++;
  return i;
}  // BusLinVec

void AcumViajes(tvrCam vrCam, trVia rVia, byte &cCam) {
  byte posCam;

  posCam = BusLinVec(vrCam, rVia.CodLeg, cCam);
  if (posCam > cCam) {
    cCam++;
    strcpy(vrCam[posCam].CodLeg, rVia.CodLeg);
    vrCam[posCam].CantVjes = 0;
    vrCam[posCam].CantUniRotas = 0;
  }
  vrCam[posCam].CantVjes++;
  vrCam[posCam].CantUniRotas += rVia.CantRotas;
}  // AcumViajes

void IntCmb(trCam &elem1, trCam &elem2) {
  trCam aux = elem1;

  elem1 = elem2;
  elem2 = aux;
}  // IntCmb

void OrdxBur(tvrCam vrCam, byte card) {
  bool ordenado;
  byte k = 0;

  do {
    ordenado = true;
    k++;
    for (byte i = 1; i <= card - k; i++)
      if (vrCam[i].CantUniRotas > vrCam[i + 1].CantUniRotas) {
        ordenado = false;
        IntCmb(vrCam[i], vrCam[i + 1]);
      }
  } while (!ordenado);
}  // OrdxBur

void Listado(tvrCam vrCam, byte cCam) {
  freopen("ViajesCamioneros.Lst", "w", stdout);
  cout << setw(5) << ""
       << "Listado de Camioneros ordenado por Cant. Unid. rotas" << endl
       << endl;
  cout << "        Cod. Leg.     Cant. Viajes       Cant.Uni.Rotas" << endl;
  for (byte i = 1; i <= cCam; i++) {
    cout.setf(ios::left);
    cout << setw(10) << "" << setw(5) << vrCam[i].CodLeg;
    cout.unsetf(ios::left);
    cout << setw(15) << (short)vrCam[i].CantVjes << setw(19)
         << vrCam[i].CantUniRotas << endl;
  }
  freopen("CON", "w", stdout);
}  // Listado

main() {
  FILE *Viajes;
  trVia rViaje;
  tvrCam vrCamioneros;
  byte canCam = 0;

  Abrir(&Viajes);
  while (fread(&rViaje, sizeof(rViaje), 1, Viajes))
    AcumViajes(vrCamioneros, rViaje, canCam);
  OrdxBur(vrCamioneros, canCam);
  Listado(vrCamioneros, canCam);
  fclose(Viajes);
  return 0;
}

/*
    Id.Programa: G2-Ej08 ViajesCam stream Text.cpp
    Autor......: Lic. Hugo A. Cuello
    Fecha......: agosto-2014
    Comentario.: Viajes de Camioneros con material fragil (1..Max.100).
                    1. Listado de Camioneros ord. x Cant.Unid.Rotas asc.
    Lenguaje...: Borland V. 5.5.
*/

#include<iomanip>
#include<fstream>
using namespace std;

typedef unsigned short ushort;

const
  MAX_CAM = 100;

typedef char str5[6];

struct trVia {
  str5   CodLeg;
  short  CodPcia;
  ushort CantRotas;
};

struct trCam {
  str5   CodLeg;
  short  CantVjes;
  ushort CantUniRotas;
};

typedef trCam tvrCam[MAX_CAM+1]; //tvrCam es el tipo arreglo de registro
                                 //si usa pos. 0 [MAX_CAM], sino [MAX_CAM + 1]
// Prototipos ------------------------------
void AcumViajes(tvrCam trVia, short &);
void IntCmb(trCam &, trCam &);
void OrdxBur(tvrCam , short );
void Listado(tvrCam , short );
// Fin Prototipos --------------------------

bool LeeUnReg(ifstream &Via, trVia &rVia) {
  Via.get(rVia.CodLeg,6);
  Via >> rVia.CodPcia >> rVia.CantRotas;
  Via.ignore();
  return Via.good();
} // LeeUnReg

short BusLinVec(tvrCam vrCam, str5 nLeg, short card) {
  short i = 1; // i = 0 si se usa pos. 0, sino pos. 1

  while (i <= card && strcmp(nLeg,vrCam[i].CodLeg) != 0)
    i++;  // i < card si se usa pos. 0, sino <=
  return i;
} //BusLinVec

void AcumViajes(tvrCam vrCam, trVia rVia, short &cCam) {
  short posCam;

  posCam = BusLinVec(vrCam,rVia.CodLeg,cCam);
  if (posCam > cCam) { // posCam >= cCam si usa pos. 0, sino >
    cCam++;
    strcpy(vrCam[posCam].CodLeg ,rVia.CodLeg);
    vrCam[posCam].CantVjes = 0;
    vrCam[posCam].CantUniRotas = 0;
  }
  vrCam[posCam].CantVjes++;
  vrCam[posCam].CantUniRotas += rVia.CantRotas;
} // AcumViajes

void IntCmb(trCam &elem1,trCam &elem2) {
  trCam aux = elem1;

  elem1 = elem2;
  elem2 = aux;
} // IntCmb

void OrdxBur(tvrCam vrCam, short card) {
  bool ordenado;
  short k = 0;

  do {
    ordenado = true;
    k++;                                  //si usa pos. 0 <, sino <=
    for (short i = 1; i <= card - k; i++) //si usa pos. 0 i=0, sino i=1
      if (vrCam[i].CantUniRotas > vrCam[i + 1].CantUniRotas) {
        ordenado = false;
        IntCmb(vrCam[i],vrCam[i + 1]);
      }
  }
  while (!ordenado);
} // OrdxBur

void OrdListado(tvrCam vrCam, short cCam) {

  OrdxBur(vrCam,cCam);
  freopen("ViajesCamioneros.Lst","w",stdout);
  cout << setw(5) << ""
       << "Listado de Camioneros ordenado por Cant. Unid. rotas"
       << endl << endl;
  cout << "        Cod. Leg.     Cant. Viajes       Cant.Uni.Rotas" << endl;
  for (short i = 1; i <= cCam; i++) { //si usa pos. 0 i=0 y <, sino i=1 y <=
    cout.setf(ios::left);
    cout << setw(10) << "" << setw(5) << vrCam[i].CodLeg;
    cout.unsetf(ios::left);
    cout << setw(15) << (short) vrCam[i].CantVjes
         << setw(19) << vrCam[i].CantUniRotas << endl;
  }
  freopen("CON","w",stdout);
} // Listado

int main() {
  ifstream Viajes("Viajes.Txt");
  trVia  rViaje;
  tvrCam vrCamioneros;
  short   canCam = 0;

  while (LeeUnReg(Viajes, rViaje))
    AcumViajes(vrCamioneros,rViaje,canCam);
  OrdListado(vrCamioneros,canCam);
  Viajes.close();
  return 0;
}

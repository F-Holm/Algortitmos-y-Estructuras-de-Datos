/*
    Id.Programa: G4Ej08ViajesCam.cpp  Adaptado para usar puntero a funcion.
    Autor......: Lic. Hugo A. Cuello
    Fecha......: agosto-2014
    Comentario.: Viajes de Camioneros con material fragil (1..Max.100).
                    1. Listado de Camioneros ord. x Cant.Unid.Rotas asc.
                    2. Listado de Camioneros ord. x Cod.Leg asc.
    Observacion: Para ordenar por los 2 criterios se utiliza puntero a
                  funcion, esto permite que solo se escriba una sola vez
                  el módulo de OrdxBur, en cada una de las llamadas a esta
                  funcion se pasa una función de criterio direrente la
                  cual ordena en cada caso por los criterios indicados
                  anteriormente.
*/

#include<iomanip>
#include<fstream>
using namespace std;

const
  MAX_CAM = 100;

typedef char str5[6];
typedef unsigned short word;

struct trVia {
  str5  CodLeg;
  short CodPcia;
  word  CantRotas;
};

struct trCam {
  str5 CodLeg;
  short CantVjes;
  word CantUniRotas;
};

typedef trCam tvrCam[MAX_CAM + 1]; //tvrCam es el tipo arreglo de registro

// Prototipos ------------------------------
void Abrir(FILE **);
void AcumViajes(tvrCam , trVia , short &);
void IntCmb(trCam &, trCam &);
void OrdxBur(tvrCam , short, bool (*criterio) (void *, void*));
void Listado(tvrCam , short );
// Fin Prototipos --------------------------

bool fcantUniRotas(trCam &elem1, trCam &elem2) {
  return elem1.CantUniRotas > elem2.CantUniRotas;
}

bool fnroLeg(trCam &elem1, trCam &elem2) {
  return strcmp(elem1.CodLeg,elem2.CodLeg) > 0;
}

short BusLinVec(tvrCam vrCam, str5 nLeg, short card) {
  short i = 1;

  while (i <= card && strcmp(nLeg,vrCam[i].CodLeg) != 0)
    i++;
  return i;
} //BusLinVec

void AcumViajes(tvrCam vrCam, trVia rVia, short &cCam) {
  short posCam;

  posCam = BusLinVec(vrCam,rVia.CodLeg,cCam);
  if (posCam > cCam) {
    cCam++;
    strcpy(vrCam[posCam].CodLeg ,rVia.CodLeg);
    vrCam[posCam].CantVjes = 0;
    vrCam[posCam].CantUniRotas = 0;
  }
  vrCam[posCam].CantVjes++;
  vrCam[posCam].CantUniRotas += rVia.CantRotas;
} //AcumViajes

void IntCmb(trCam &elem1,trCam &elem2) {
  trCam aux = elem1;

  elem1 = elem2;
  elem2 = aux;
} // IntCmb

void OrdxBur(tvrCam vrCam, short card, bool (*criterio) (void *, void *)) {
  bool ordenado;
  short k = 0;

  do {
    ordenado = true;
    k++;

    for (short i = 1; i <= card - k; i++)
      //if (vrCam[i].CantUniRotas > vrCam[i + 1].CantUniRotas) {
      if (criterio(&vrCam[i],&vrCam[i+1])) {
        ordenado = false;
        IntCmb(vrCam[i],vrCam[i + 1]);
      }
  }
  while (!ordenado);
} // OrdxBur

void Listado(tvrCam vrCam, short cCam) {
static bool x = true;
  string cmpOrd;
  if (x) {
    freopen("ViajesCamionerosCantUR.Lst","w",stdout);
    cmpOrd = "Cant. Unid. Rotas";
  }
  else {
    freopen("ViajesCamionerosCodLeg.Lst","w",stdout);
    cmpOrd = "Cod. Leg.";
  }
  x = false;
  cout << setw(5) << ""
       << "Listado de Camioneros ordenado por " << cmpOrd << endl << endl;
  cout << "        Cod. Leg.     Cant. Viajes       Cant.Uni.Rotas" << endl;
  for (short i = 1; i <= cCam; i++) {
    cout.setf(ios::left);
    cout << setw(10) << "" << setw(5) << vrCam[i].CodLeg;
    cout.unsetf(ios::left);
    cout << setw(15) << (short) vrCam[i].CantVjes
         << setw(19) << vrCam[i].CantUniRotas << endl;
  }
  freopen("CON","w",stdout);
} //Listado

main() {
  ifstream Viajes("Viajes.Dat",ios::binary);
  trVia  rViaje;
  tvrCam vrCamioneros;
  short  canCam = 0;

  while (Viajes.read((char *) &rViaje,sizeof (rViaje)))
    AcumViajes(vrCamioneros,rViaje,canCam);
  OrdxBur(vrCamioneros,canCam, (bool (*) (void *, void * )) (fcantUniRotas) );
  Listado(vrCamioneros,canCam);
  OrdxBur(vrCamioneros,canCam, (bool (*) (void *, void * )) (fnroLeg) );
  Listado(vrCamioneros,canCam);
  Viajes.close();
  return 0;
}

// Genera archivo de datos Viajes.Dat a partir de Viajes.Txt

#include<iostream>
using namespace std;

typedef unsigned char byte;
typedef unsigned short word;

const
  MAX_CAM = 100;

typedef char str5[6];

struct sViaje {
  str5  CodLeg;
  short CodPcia;
  word  CantRotas;
};

int main () {
  sViaje rViaje;
  FILE   *Viajes,
         *ViajesT;

  ViajesT = fopen("Viajes.Txt","r");
  Viajes  = fopen("Viajes.Dat","wb");
   while (!feof(ViajesT)) {
    //fgets(rViaje.CodLeg,6,ViajesT);
    fscanf(ViajesT,"%5s%d%d\n",rViaje.CodLeg,
                              &rViaje.CodPcia,
                              &rViaje.CantRotas);
    cout << rViaje.CodLeg << " " << (short) rViaje.CodPcia << " " << rViaje.CantRotas << endl;
    fwrite(&rViaje,sizeof(rViaje),1,Viajes);
  }
  fclose(ViajesT);
  fclose(Viajes);

  return 0;
}

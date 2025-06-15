// Unidad 2 - Ejercicio 8
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

typedef unsigned short ushort;
const ushort kMaxCamiones = 100;
typedef char str5[6];

struct Viaje {
  str5 nro_leg;
  short cod_provincia;
  ushort cant_rotas;
};

struct Camionero {
  str5 nro_leg;
  short cant_viajes;
  ushort cantUni_rotas;
};

typedef Camionero Camioneros[kMaxCamiones + 1];

bool LeeUnaLinea(ifstream& archivo, Viaje& viaje);
void ProcesarViaje(Camioneros& camioneros, Viaje& viaje, const short& cant_cam);
void Ordenar(Camioneros& camioneros, const short& cant_cam);
void Emitir(Camioneros& camioneros, const short& cant_cam);
short ObtenerIndice(Camioneros& camioneros, str5& nro_leg);

int main() {
  ifstream viajes("Viajes.Txt");
  Viaje viaje;
  Camioneros camioneros;
  short cant_cam = 0;

  while (LeeUnaLinea(viajes, viaje))
    ProcesarViaje(camioneros, viaje, cant_cam);
  Ordenar(camioneros, cant_cam);
  Emitir(camioneros, cant_cam);
  viajes.close();
  return 0;
}

bool LeeUnaLinea(ifstream& archivo, Viaje& viaje) {
  archivo.get(viaje.nro_leg, 6);
  archivo >> viaje.cod_provincia >> viaje.cant_rotas;
  archivo.ignore();
  return archivo.good();
}

void ProcesarViaje(Camioneros& camioneros, Viaje& viaje,
                   const short& cant_cam) {
  return;
}

void Ordenar(Camioneros& camioneros, const short& cant_cam) {
}

void Emitir(Camioneros& camioneros, const short& cant_cam) {
}

short ObtenerIndice(Camioneros& camioneros, str5& nro_leg) {
  for (short i = 0; i < kMaxCamiones; i++) {
    if (strcmp(camioneros[i].nro_leg, nro_leg) == 0) {
      return i;
    }
  }
  return -1;
}
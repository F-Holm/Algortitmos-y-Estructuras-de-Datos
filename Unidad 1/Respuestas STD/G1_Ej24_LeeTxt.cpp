/*
	Id.Programa: G1_Ej24_LeeTxt.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: marzo-2024
	Comentario.: Datos lectura desde archivo de texto "VentasFerreteria.Txt"
	                ventas de vendedores agrupados por Cod.Ven.
                    Emitir por cada vendedor c/u. de sus ventas y al
					finalizar un vendedor el Importe Total vendido, y
					por fin del proceso el Importe General vendido y el
					Cod.Ven. que mas vendio en Importe.
					La salida en archivo de texto "Sld.Txt".
	Lenguaje...: cygwin64 g++ 64bits for windows
*/

#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

typedef unsigned short ushort;
typedef char str20[21];

struct sVen {
  ushort codVen,
         cant;
  str20  descrip; // cadena de caracteres al estilo Leng. C
  float  preUni;
};

string Replicate (ushort n, char car) {
  string str;

  for (ushort i = 0; i < n; i++)
    str += car; // str = str + car; -  str = car + str;
  return str;
} // Replicate

void EmiteInic (ofstream &Sld, float &tGral, float &iMaxVta) {
  Sld << "--> Ventas de vendedores agrupados por codVen" << endl;
  Sld << "Totales por codVen y Total General + codVenMaxVta" << endl;
  Sld << Replicate(80,'-') << endl;
  tGral = iMaxVta = 0.0;
} // EmiteInic

void ObtDatos (ifstream &Vtas, sVen & rVen) {
  Vtas >> rVen.codVen;
  if (rVen.codVen) {
    Vtas >> rVen.cant;
    Vtas.ignore();
    Vtas.get(rVen.descrip,21);
    Vtas >> rVen.preUni;
  }
} // ObtDatos

void EmiteInicCabVen (ofstream &Sld, ushort cVen, ushort &cVenAnt,
                     float & tVen) {
  Sld << "Cod.Ven.: " << cVen << endl;
  Sld << "   Cant. Descripcion            Pre.Uni.    Tot.Item     Tot.Ven."
      << endl;
  Sld << Replicate(80,'-');
  tVen = 0.0;
  cVenAnt = cVen;
} // EmiteINicCabVen

void CalcDet (sVen rVen,float & tItm, float & tVen) {
  tItm = rVen.cant * rVen.preUni;
  tVen += tItm;
} // CalcDet

void EmiteDet (ofstream &Sld, sVen rVen, float tItm) {
  Sld << endl << setw(4) << "" << setw(4) << rVen.cant
      << setw(1) << "" << setw(20) << rVen.descrip
      << setw(3) << "" << setw(8) << rVen.preUni
      << setw(3) << "" << setw(9) << tItm;
} // EmitDet

void CalcVerifMaxVtaPieVen(float tVen, float &tGral, float &iVtaMax,
                           ushort &cVenMax, ushort cVenAnt) {
  tGral += tVen;
  if (tVen > iVtaMax) {
    iVtaMax = tVen;
    cVenMax = cVenAnt;
  }
} // CalcPieVen

void EmitePieVen (ofstream &Sld, float tVen) {
  Sld << setw (5) << '$' << setw(8)
      << setfill(' ') << tVen << endl;
  Sld << Replicate(80,'-') << endl;
} // EmitePieVen

void EmitePieLst (ofstream &Sld, float tGral, ushort cVenMax) {
  Sld << "Total General: " << setfill('.') << setw(56) << '$' << setw(9)
                           << setfill(' ') << tGral << endl;
  Sld << "Cod.Ven.Max.Vta.: " << setfill ('.') << setw(54) << cVenMax;
} // EmitePieLst

main() {
  float    totVen,
           totGral,
           impMaxVta,
           totItem;
  ushort   codVenAnt,
           codVenMax;
  sVen     rVendedor;
  ifstream Ventas ("VentasFerreteria.Txt");
  ofstream Salida ("Sld.Txt");

  Salida.precision(2); //Sld << setprecision(2); // o Sld.precision(2);
  Salida << fixed; // o Sld.setf(ios::fixed);
  Salida.fill(' '); // o Sld << setfill('+'); 	//Sld.setf(ios::showpoint);
  EmiteInic(Salida,totGral,impMaxVta);
  ObtDatos(Ventas,rVendedor);
  while (rVendedor.codVen) {
    EmiteInicCabVen (Salida,rVendedor.codVen,codVenAnt,totVen);
    while (rVendedor.codVen == codVenAnt) {
      CalcDet(rVendedor,totItem,totVen);
      EmiteDet(Salida,rVendedor,totItem);
      ObtDatos(Ventas,rVendedor);
    }
    CalcVerifMaxVtaPieVen(totVen,totGral,impMaxVta,codVenMax,codVenAnt);
    EmitePieVen(Salida,totVen);
  }
  EmitePieLst(Salida,totGral,codVenMax);
  Ventas.close();
  Salida.close();
  return 0;
}

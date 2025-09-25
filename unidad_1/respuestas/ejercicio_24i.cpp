/*
	Id.Programa: G1-Ej24 Ing x Teclado
	.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Datos ingreso por teclado ventas de vendedores agrupados
	                por Cod.Ven.
                    Emitir por cada vendedor c/u. de sus ventas y al
					finalizar un vendedor el Importe Total vendido, y
					por fin del proceso el Importe General vendido y el
					Cod.Ven. que mas vendio en Importe.
	Lenguaje...: Borland V.5.5
*/

#define record struct

#include <iomanip>
#include <iostream>

using namespace std;

typedef unsigned short ushort;
typedef char str20[21];


record sVen {
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

void EmiteInic (float & tGral, float &iMaxVta) {
  cout << "*** Ventas de vendedores agrupados por codVen" << endl;
  cout << "Totales por codVen y Total General + codVenMaxVta" << endl;
  cout << Replicate(80,'-') << endl;
  tGral = iMaxVta = 0.0;
} // EmiteInic

void ObtDatos (sVen &rVen) {
  cout << "Datos de Vendedor: ";
  cout << "Cod.Ven. FIN = 0: ";
  cin >> rVen.codVen;
  if (rVen.codVen) {
    cout << "Cantidad........: ";
    cin >> rVen.cant;
    cin.ignore();
    cout << "Descripcion.....: ";
    cin.get(rVen.descrip,21);
    cin.ignore(1000,'\n'); //si se pegan los datos quitar esta sentencia ignore.
    cout << "Precio Unitario.: ";
    cin >> rVen.preUni;
            //cin.ignore(numeric_limits<int>::max(),'\n');
		    //scanf("%20[^\n]",rVen.descrip); fflush(stdin);
		    //fgets(rVen.descrip,21,stdin); fflush(stdin);
		      // si len -1='\n' cmb x '\0'
		    //cin.getline(rVen.descrip,21,'\n');
		    //cin.ignore(numeric_limits<int>::max(),'\n');
		    //getline(cin,rVen.descrip,'\n');
		    //rVen.descrip.assign(rVen.descrip,0,20);
            //cin.with(sizeof(rVen.descrip)); //evita si se escriben
              // + de sizeof(cadena) cars.
		    //cin >> cadena;
		    //cin >> rVen.descrip;
	}
} // ObtDatos

void EmiteInicCabVen (ushort cVen, ushort &cVenAnt, float &tVen) {
  cout << "Cod.Ven.: " << cVen << endl;
  cout << "   Cant. Descripcion            Pre.Uni.    Tot.Item" << endl;
  cout << Replicate(80,'-');
  tVen = 0.0;
  cVenAnt = cVen;
} // EmiteINicCabVen

void CalcDet (sVen rVen,float &tItm, float &tVen) {
  tItm = rVen.cant * rVen.preUni;
  tVen += tItm;
} // CalcDet

void EmiteDet (sVen rVen, float tItm) {
  cout << endl << setw(4) << "" << setw(4) << rVen.cant
       << setw(1) << "" << setw(20) << rVen.descrip
       << setw(3) << "" << setw(8) << rVen.preUni
       << setw(3) << "" << setw(9) << tItm << endl;
} // EmitDet

void CalcVerifMaxVtaPieVen (float tVen, float &tGral, float &iVtaMax,
                            ushort &cVenMax, ushort cVenAnt) {
  tGral += tVen;
  if (tVen > iVtaMax) {
    iVtaMax = tVen;
    cVenMax = cVenAnt;
  }
} // CalcPieVen

void EmitePieVen (float tVen) {
  cout << "Total Vendedor: " << setw(47) << '$' << setw(8)
       << setfill(' ') << tVen << endl;
  cout << Replicate(80,'-') << endl;
} // EmitePieVen

void EmitePieLst (float tGral, ushort cVenMax) {
	cout << "Total General: " << setfill('.') << setw(57) << '$' << setw(9)
         << setfill(' ') << tGral << endl;
	cout << "Cod.Ven.Max.Vta.: " << setfill('.') << setw(55) << cVenMax;
} // EmitePieLst

int main() {
  float  totVen,
         totGral,
         impMaxVta,
         totItem;
  ushort codVenAnt,
         codVenMax;
  sVen   rVendedor;

  cout.precision(2); //cout << setprecision(2); // o cout.precision(2);
  cout << fixed; // o cout.setf(ios::fixed);
  cout.fill(' '); // o cout << setfill('+'); 	//cout.setf(ios::showpoint);
  EmiteInic(totGral,impMaxVta);
  ObtDatos(rVendedor); // Obtener primer item.
  while (rVendedor.codVen) {
    EmiteInicCabVen(rVendedor.codVen,codVenAnt,totVen);
    while (rVendedor.codVen == codVenAnt) {
      CalcDet(rVendedor,totItem,totVen);
      EmiteDet(rVendedor,totItem);
      ObtDatos(rVendedor); // Obtener proximos items.
    }
    CalcVerifMaxVtaPieVen(totVen,totGral,impMaxVta,codVenMax,codVenAnt);
    EmitePieVen(totVen);
  }
  EmitePieLst(totGral,codVenMax);
  return 0;
}

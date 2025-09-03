/*
	Id.Programa: G1Ej24.cpp
	Autor......: Lic. Hugo Cuello
	Fecha......: julio-2013
	Comentario.: Datos ventas de vendedores agrupados por Cod.Ven.
                    Emitir por cada vendedor c/u. de sus ventas y al
					finalizar un vendedor el Importe Total vendido, y
					por fin del proceso el Importe General vendido y el
					Cod.Ven. que mas vendio en Importe.
*/

#include <iomanip>
#include <iostream>
using namespace std;

typedef unsigned short ushort;
typedef char str20[21];

struct sVen {
	ushort codVen,
           cant;
	str20  descrip;
	float  preUni;
};

void EmiteInic(float & tGral, float & iMaxVta) {

	cout << "Ventas de vendedores agrupados por codVen" << endl;
	cout << "Totales por codVen y Total General + codVenMaxVta" << endl;
	tGral = iMaxVta = 0.0;
} // EmiteInic

void ObtDatos(sVen & rVen) {

	cout << "Datos de Vendedor: ";
	cout << "Cod.Ven. FIN = 0: ";
	cin >> rVen.codVen;
	if(rVen.codVen) {
		cout << "Cantidad........: ";
		cin >> rVen.cant;
		cout << "Descripcion.....: ";
		//cin.get(rVen.descrip,20);
        ///cin.ignore(numeric_limits<int>::max(),'\n');
        cin.ignore();
		//scanf("%20[^\n]",rVen.descrip); fflush(stdin);
		//fgets(rVen.descrip,21,stdin); fflush(stdin); // si len -1='\n' cmb x '\0'
		//cin.getline(rVen.descrip,21,'\n');
		//cin.ignore(numeric_limits<int>::max(),'\n');
		///getline(cin,rVen.descrip,'\n');
		///rVen.descrip.assign(rVen.descrip,0,20);
		////cin.with(sizeof(cadena)); evita si se escriben + de sizeof(cadena) cars.
		////cin >> cadena;
		cin.get(rVen.descrip,21);
		cout << "Precio Unitario.: ";
		cin >> rVen.preUni;
	}
} // ObtDatos

void EmiteInicCabVen(ushort cVen, ushort & cVenAnt, float & tVen) {

	cout << "Cod.Ven.: " << cVen << endl;
	cout << "   Cant. Descripcion            Pre.Uni.    Tot.Item" << endl;
	tVen = 0.0;
	cVenAnt = cVen;
} // EmiteINicCabVen

void CalcDet(sVen rVen,float & tItm, float & tVen) {

	tItm = rVen.cant * rVen.preUni;
	tVen += tItm;
} // CalcDet

void EmiteDet(sVen rVen, float tItm) {

	cout << setw(4) << "" << setw(4) << rVen.cant
	     << setw(1) << "" << setw(3) << rVen.descrip
	     << setw(7) << "" << setw(8) << rVen.preUni
	     << setw(3) << "" << setw(9) << tItm << endl;
} // EmitDet

void CalcVerifMaxVtaPieVen(float tVen, float & tGral, float & iVtaMax,
                           ushort & cVenMax, ushort cVenAnt) {

	tGral += tVen;
	if(tVen > iVtaMax) {
		iVtaMax = tVen;
		cVenMax = cVenAnt;
	}
} // CalcPieVen

void EmitePieVen(float tVen) {

	cout << "Total Vendedor:" << tVen << endl;
} // EmitePieVen

void EmitePieLst(float tGral, ushort cVenMax) {

	cout << "Total General: " << tGral << endl;
	cout << "Cod.Ven.Max.Vta.: " << cVenMax;
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
	cout.fill(' '); // o cout << setfill('+');
	//cout.setf(ios::showpoint);

	EmiteInic(totGral,impMaxVta);
	ObtDatos(rVendedor);
	while(rVendedor.codVen) {
		EmiteInicCabVen(rVendedor.codVen,codVenAnt,totVen);
		while(rVendedor.codVen == codVenAnt) {
			CalcDet(rVendedor,totItem,totVen);
			EmiteDet(rVendedor,totItem);
			ObtDatos(rVendedor);
		}
		CalcVerifMaxVtaPieVen(totVen,totGral,impMaxVta,codVenMax,codVenAnt);
		EmitePieVen(totVen);
	}
	EmitePieLst(totGral,codVenMax);
	return 0;
}

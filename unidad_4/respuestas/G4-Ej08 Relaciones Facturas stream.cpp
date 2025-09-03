/*
    Id.Programa: G4-Ej08 Relaciones Facturas stream.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: ago-2014
    Comentario.: Emision de Facturas a Clientes en Cta.Cte.
                 Relaciones entre archivos.
    Lenguaje...: Borland C++ V. 5.5.

    ----> O j O: No estan los archivos de datos <----
*/

#include <fstream>
#include <iomanip>
using namespace std;

#define IVA 0.21
#define not !
#define and &&

typedef char str5[6];
typedef char str10[11];
typedef char str15[16];
typedef char str20[21];
typedef unsigned short byte;
typedef unsigned word;

struct sPed {
  long codCli;  // Ord. por codCli (con repeticion) + codArt (sin repeticion)
  byte codArt;
  word cant;
};

struct sCli {   // Ord. por codCli
  long codCli;  // 8 digitos.
  str20 razSoc, domic, local;
  word codPos;
  char codPcia;
  str15 nroCUIT;
  str20 formaPago;
  word codVen;
  float saldo;  // Actualizar el saldo
};

struct sArt {   // Relacion 1:1 clv = dir.
  byte codArt;  // 1..100
  str20 marca, descrip;
  float precio;
  word stockAct,  // Actualizar el stockAct.
      stockMin, ptoRep;
  str10 uniMed;
  char estado;
};

struct sVen {   // desordenado
  word codVen;  // 1..999
  str20 nomVen;
  float porcCom,
      impAcumCom;  // Actualizar el impAcumCom.
};

struct sNro {  // desordenado
  str5 tipoDoc;
  long nroDoc;  // Actuaizar nroDoc.
};

struct sFecF {
  byte dia, mes;
  word year;
};

struct sFac {  // Ord.cronologico. El archivo existe y
               // se deben agregar + registros.
  long nroFac;
  sFecF fecFac;
  long codCli;
  float impo;
  char estado;  //'A' = Adeuda, 'P' = Pagada.
};

struct sFec {
  int year, mes, dia, dsem;
};

struct sHor {
  int Hora, Min, Seg;
};

// Prototipos -------------------------------------------------------------
void Abrir(FILE **, FILE **, FILE **, FILE **, FILE **, FILE **, FILE **);
void ArmarAuxVen(FILE *, FILE *);
long GetDate(int &, int &, int &, int &);
void EmiteTapaObtFecha(sFec &);
void BusLinNrosInic(FILE *, str5, sNro &);
void InicCabCli(byte &, float &, long &nDoc);
bool BusBinCli(FILE *, long, sCli &);
void BusDDVen(FILE *, word, sVen &, FILE *);
void EmiteCabCli(sCli, str20, sFec, sHor, long);
void BusDDArt(FILE *, byte, sArt &);
void CalcDetFac(word, sArt &, byte &, float &, float &);
void ActArt(FILE *, sArt);
void EmiteDetFac(byte, sArt, word, float);
void CalcPieCli(float, float &, float &, float &, sVen &);
void ActCli(FILE *, sCli);
void ActVen(FILE *, sVen);
void AgregarRegFac(FILE *, long, sFec, long, float);
void EmitePieFac(byte, float, float, float);
void ActNroI(FILE *, sNro);
void CerrarEliminar();
// Fin Prototipos ---------------------------------------------------------

void Abrir(ifstream &Ped, fstream &Cli, fstream &Art, fstream &Ven,
           fstream &nInic, ofstream &Fac, fstream &AuxVen) {
  Ped.open("Pedidos.Dat", ios::binary);
  Fac.open("Facturas.Dat", ios::app | ios::binary);
  Cli.open("Clientes.Dat", ios::in | ios::out | ios::binary);
  Art.open("Articulos.Dat", ios::in | ios::out | ios::binary);
  Ven.open("Vendedores.Dat", ios::in | ios::out | ios::binary);
  nInic.open("NrosInic.Dat", ios::in | ios::out | ios::binary);
  AuxVen.open("AuxVen.Tmp", ios::in | ios::out | ios::binary);
}  // Abrir

void ArmarAuxVen(fstream &Ven, fstream &AuxVen) {
  int refVen = -1;
  sVen rVen;

  for (int i = 0; i <= 999; i++)
    AuxVen.write((char *)&refVen, sizeof(int));
  while (Ven.read((char *)&rVen, sizeof rVen)) {
    AuxVen.seekg(rVen.codVen * sizeof rVen, ios::beg);
    refVen = (Ven.tellg() - (int)sizeof rVen) / sizeof rVen;
    AuxVen.write((char *)&refVen, sizeof refVen);
  }
}  // ArmarAuxVen

long GetDate(int &year, int &mes, int &dia, int &ds) {
  time_t rawtime;
  tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  year = 1900 + timeinfo->tm_year;
  mes = 1 + timeinfo->tm_mon;
  dia = timeinfo->tm_mday;
  ds = 1 + timeinfo->tm_wday;
  return (1900 + timeinfo->tm_year) * 10000 + (1 + timeinfo->tm_mon) * 100 +
         timeinfo->tm_mday;
}  // GetDate

long GetTime(int &hh, int &mm, int &ss) {
  time_t rawtime;
  tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  hh = timeinfo->tm_hour;
  mm = timeinfo->tm_min;
  ss = timeinfo->tm_sec;
  return timeinfo->tm_hour * 10000 + timeinfo->tm_min * 100 + timeinfo->tm_sec;
}  // GetTime

void EmiteTapaObtFecha(sFec &rFec) {
  cout << "FACTURACION A CLIENTES" << endl;
  cout << " EN CUENTA CORRIENTE" << endl;
  GetDate(rFec.year, rFec.mes, rFec.dia, rFec.dsem);
}  // EmiteTapaObtFecha

void BusLinNrosInic(fstream &nInic, str5 tDoc, sNro &rNroI) {
  bool sigo = true;

  while (sigo) {
    nInic.read((char *)&rNroI, sizeof rNroI);
    if (strcmp(rNroI.tipoDoc, tDoc) == 0)
      sigo = false;
  }
}  // BusLinNrosInic

void InicCabCli(byte &nItem, float &tFac, long &nDoc) {
  nItem = 0;
  tFac = 0.0;
  nDoc++;
}  // InicCabCli

void ObtHora(sHor &rHor) {
  cout << "FACTURACION A CLIENTES" << endl;
  cout << " EN CUENTA CORRIENTE" << endl;
  GetTime(rHor.Hora, rHor.Min, rHor.Seg);
}  // ObtHora

bool BusBinCli(fstream &Cli, long cCli, sCli &rCli) {
  int pri, ult, med;

  pri = 0;
  Cli.seekg(0L, ios::end);
  ult = Cli.tellg() / sizeof(rCli) - 1;
  while (pri <= ult) {
    med = (pri + ult) / 2;
    Cli.seekg(med * sizeof(rCli), ios::beg);
    Cli.read((char *)&rCli, sizeof rCli);
    if (rCli.codCli == cCli)
      return true;
    else if (rCli.codCli < cCli)
      pri = med + 1;
    else
      ult = med - 1;
  }
  return false;
}  // BusBinCli

void BusDDVen(fstream &Ven, word cVen, sVen &rVen, fstream &AuxiV) {
  word refVen;

  AuxiV.seekg(cVen * sizeof rVen, ios::beg);
  AuxiV.read((char *)&refVen, sizeof refVen);
  Ven.seekg(refVen * sizeof rVen, ios::beg);
  Ven.read((char *)&rVen, sizeof rVen);
}  // BusDDVen

void EmiteCabCli(sCli rCli, str20 nVen, sFec rFec, sHor rHor, long nDoc) {
  cout << setw(38) << " " << "FACTURA: " << nDoc << endl;
  cout << setw(38) << " " << "FECHA..: " << setw(2) << rFec.dia << '-'
       << setw(2) << rFec.mes << '-' << setw(4) << rFec.year << endl;
  cout << setw(38) << " " << "HORA...: " << setw(2) << rHor.Hora << '-'
       << setw(2) << rHor.Min << '-' << setw(4) << rHor.Seg << endl;
  cout << "Cod. Cliente.: " << setw(8) << rCli.codCli
       << "Raz. Social..: " << setw(20) << rCli.razSoc
       << "Domicilio....: " << setw(20) << rCli.domic
       << "Forma de Pago: " << setw(20) << rCli.formaPago
       << "Cod. Vendedor: " << setw(3) << nVen << endl;
  cout << endl;
  cout << setw(40) << "-" << endl;
  cout << "Item  Cant.  Cod.Art. Descripcion       Pre.Uni.    T.Item" << endl;
  cout << setw(40) << "-" << endl;
}  // EmiteCabCli

void BusDDArt(fstream &Art, byte cArt, sArt &rArt) {
  Art.seekg(cArt * sizeof rArt, ios::beg);
  Art.read((char *)&rArt, sizeof rArt);
}  // BusDDArt

void CalcDetFac(word cant, sArt &rArt, byte &nItem, float &tItem,
                float &totFac) {
  nItem++;
  tItem = cant * rArt.precio;
  rArt.stockAct -= cant;
  totFac += tItem;
}  // CalcDetFac

void ActArt(fstream &Art, sArt rArt) {
  Art.seekg(Art.tellg() - (int)sizeof rArt, ios::beg);
  Art.read((char *)&rArt, sizeof rArt);
}  // ActArt

void EmiteDetFac(byte nItem, sArt rArt, word cant, float tItem) {
  cout << setw(2) << nItem << setw(5) << cant << setw(3) << rArt.codArt
       << setw(20) << rArt.descrip << setw(8) << rArt.precio << setw(8) << tItem
       << endl;
}  // EmiteDetFac

void CalcPieCli(float tBruFac, float &impIVA, float &tNetoFac, float &saldo,
                sVen &rVen) {
  impIVA = tBruFac * IVA;
  tNetoFac = tBruFac + impIVA;
  saldo += tNetoFac;
  rVen.impAcumCom += tBruFac * rVen.porcCom / 100;
}  // CalcPieCli

void ActCli(fstream &Cli, sCli rCli) {
  Cli.seekg(Cli.tellg() - (int)sizeof rCli, ios::beg);
  Cli.write((char *)&rCli, sizeof rCli);
}  // ActCli

void ActVen(fstream &Ven, sVen rVen) {
  Ven.seekg(Ven.tellg() - (int)sizeof rVen, ios::beg);
  Ven.write((char *)&rVen, sizeof rVen);
}  // ActVen

void AgregarRegFac(ofstream &Fac, long nFac, sFec rFec, long cCli,
                   float tNetoFac) {
  sFac rFac;

  rFac.nroFac = nFac;
  rFac.fecFac.dia = rFec.dia;
  rFac.fecFac.mes = rFec.mes;
  rFac.fecFac.year = rFec.year;
  rFac.codCli = cCli;
  rFac.impo = tNetoFac;
  rFac.estado = 'A';
  Fac.write((char *)&rFac, sizeof rFac);
}  // AgregarRegFac

void EmitePieFac(byte nItem, float tBruFac, float impIVA, float tNetoFac) {
  byte i;

  for (i = 1; i <= 10 - nItem; i++)
    cout << endl;
  cout << setw(38) << " " << "Sub-Total.: " << setw(8) << tBruFac << setw(38)
       << " " << "I.V.A.....: " << setw(8) << impIVA << setw(38) << " "
       << "Total Neto: " << setw(8) << tNetoFac << endl;
}  // EmitePieFac

void ActNroI(fstream &nInic, sNro rNroI) {
  nInic.seekg(nInic.tellg() - (int)sizeof rNroI, ios::beg);
  nInic.write((char *)&rNroI, sizeof rNroI);
}  // ActNroI

void CerrarEliminar() {  // FILE *Ped, FILE *Cli, FILE *Art, FILE *Ven,
                         // FILE *nInic, FILE *Fac, FILE *AuxVen)

  fcloseall();
  remove("AuxVen.Tmp");
}  // CerrarEliminar

main() {
  ifstream Pedidos;
  ofstream Facturas;
  fstream Clientes, Articulos, Vendedores, NrosInic, AuxVendedores;
  sFec rFecha;
  sHor rHora;
  sPed rPedido;
  sNro rNroInic;
  sCli rCliente;
  sVen rVendedor;
  sArt rArticulo;
  byte nroItem;
  float totItem, totBrutoFac, impIVA, totNetoFac;

  Abrir(Pedidos, Clientes, Articulos, Vendedores, NrosInic, Facturas,
        AuxVendedores);
  freopen("FacturasCtaCteCli.Lst", "w", stdout);
  ArmarAuxVen(Vendedores, AuxVendedores);
  EmiteTapaObtFecha(rFecha);
  BusLinNrosInic(NrosInic, "FAC", rNroInic);
  Pedidos.read((char *)&rPedido, sizeof rPedido);
  while (not Pedidos.eof()) {
    InicCabCli(nroItem, totBrutoFac, rNroInic.nroDoc);
    ObtHora(rHora);
    BusBinCli(Clientes, rPedido.codCli, rCliente);
    BusDDVen(Vendedores, rCliente.codVen, rVendedor, AuxVendedores);
    EmiteCabCli(rCliente, rVendedor.nomVen, rFecha, rHora, rNroInic.nroDoc);
    while (not Pedidos.eof() and rPedido.codCli == rCliente.codCli) {
      BusDDArt(Articulos, rPedido.codArt, rArticulo);
      CalcDetFac(rPedido.cant, rArticulo, nroItem, totItem, totBrutoFac);
      ActArt(Articulos, rArticulo);
      EmiteDetFac(nroItem, rArticulo, rPedido.cant, totItem);
      Pedidos.read((char *)&rPedido, sizeof rPedido);
    }
    CalcPieCli(totBrutoFac, impIVA, totNetoFac, rCliente.saldo, rVendedor);
    ActCli(Clientes, rCliente);
    ActVen(Vendedores, rVendedor);
    AgregarRegFac(Facturas, rNroInic.nroDoc, rFecha, rCliente.codCli,
                  totNetoFac);
    EmitePieFac(nroItem, totBrutoFac, impIVA, totNetoFac);
  }
  ActNroI(NrosInic, rNroInic);
  freopen("CON", "w", stdout);
  CerrarEliminar();  // usa fcloseall() Pedidos,Clientes,Articulos,Vendedores,
                     // NrosInic,Facturas,AuxVendedores);
  return 0;
}

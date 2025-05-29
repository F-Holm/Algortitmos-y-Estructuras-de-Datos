/*
    Id. Programa: MisLibsCad.cpp
    Autor.......: Lic. Hugo Cuello
    Fecha.......: ago-2014
    Comentario..: Funciones para el tratamiento de cadenas
*/


  // Operaciones con string en C y C++ mayo-2017 (2)

  /*
     *****************************************
     * Revoltijo de cadenas de caracteres... *
     *****************************************
  */


#include<iostream>
using namespace std;

typedef unsigned short ushort;
typedef char str20[51];

char *mesCad[] = {"","ENERO","FEBRERO","MARZO","ABRIL",
                     "MAYO","JUNIO","JULIO","AGOSTO",
                     "SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"
                 };



char LowCase(char car);

int a2i(char s[]) {   //atoi
    int i = 0,                               // 0:48 .......  9:57
        n = 0;
                                              //0123
    for ( ; s[i] >= '0' && s[i] <= '9'; i++) // 743a...
        n = 10 * n + (s[i] - '0'); // codASCII 7 es 55, 0 es 48
    return n;
} // a2i

char* CmbCar(char* cad, char car1, char car2) {
    int longCad = strlen(cad);

    for(int i=0; i < longCad; i++)
        if(cad[i] == car1)
            cad[i] = car2;
    return cad;
} // CmbCar

char *CnvMin(char *cad) {
  for (unsigned i = 0; i < strlen(cad); i++)
    cad[i] = LowCase(cad[i]);
  return cad;
} // strlCat

char* Concat(char* cad1, const char* cad2) {
    int i = 0,
        j = 0;

    for( ; cad1[i]; i++);
    for( ; (cad1[i] = cad2[j]) != NULL; i++,j++);
    return cad1;
} // Concat

ushort ContarVocales(char *cad) {
  ushort cantVoc = 0;
  char vocales[] = "aAeEiIoOuU", *pcar;

  pcar = strpbrk(cad,vocales);
  while (pcar) {
    cantVoc++;
    pcar = strpbrk(pcar+1,vocales);
  }
  return cantVoc;
}

char* ElimCar(char* cad, int car) {
    int i = 0,
        j = 0;

    for( ; cad[i]; i++)
        if(cad[i] != car)
            cad[j++] = cad[i];
    cad[j] = '\0';
    return cad;
} // ElimCar

bool EsOtraPalabra(char *cad, char *dicci) {
  return strstr(dicci,cad);
}

char *FillBlank(char cad[]) {
	long longLogCad = strlen(cad),
	     longFisCad = sizeof (str20),
	     longLlenar = longFisCad - longLogCad - 1,
	     i = longLogCad;

	for (; i < longLlenar+longLogCad; i++)
		cad[i] = ' ';
	cad[i] = '\0';
	return cad;
} // FillBlank

void IntCmb(char & car1, char & car2) {
    char aux = car1;

    car1 = car2;
    car2 = aux;
} // IntCmb

char* InvPal(char cad[]) {
    int i = 0,
        j = strlen(cad) - 1;

    for( ; i <= j; i++, j--)
        IntCmb(cad[i],cad[j]);
    return cad;
} // InvPal

char *InvPalV(char pal[]) {
  char *pcad,
       *pcadF,
       aux;
  int j;

  pcadF = pal;
  while (*pcadF)
    pcadF++; //recorre pal hasta el final
  pcadF--;
  for (pcad = pal; pcad < pcadF; pcad++, pcadF--) {
    aux = *pcad;
    *pcad = *pcadF;
    *pcadF = aux;
  }
  return pal;
} //InvPalV

int LongCad(const char* cad) {
    int i = 0;

    for( ; cad[i]; i++);   //  '\0' = NULL
    return i;
} // LongCad

int Largo(const char sarta[]) {
	int i = 0;

	while(sarta[i++]);
	return --i;
} // Largo

char LowCase(char car) {

  if (car >= 'A' && car <= 'Z')
    return car + 'a' - 'A';
  else
    return car;
} // LowCase

char *MesStr(short mes) {

  switch (mes) {
    case  1: return "Enero";
    case  2: return "Febrero";
    case  3: return "Marzo";
    case  4: return "Abril";
    case  5: return "Mayo";
    case  6: return "Junio";
    case  7: return "Julio";
    case  8: return "Agosto";
    case  9: return "Septiembre";
    case 10: return "Octubre";
    case 11: return "Noviembre";
    case 12: return "Diciembre";
    default: return "";
  }
} // MesStr

char*strCpy(char *cadD, char *cadO) {
  char* pCadD = cadD;
  while ((*cadD++ = *cadO++) != NULL);
  return pCadD;
}

char* strlCat(char* cadD, const char* cadO) {
    char *pCadAux = new char [strlen(cadD) + strlen(cadO) + 1];

    strcpy(pCadAux,cadO);
    strcat(pCadAux,cadD);
    strcpy(cadD,pCadAux);
    delete(pCadAux);
    return cadD;
} // strlCat

char *replicate(char car, ushort n) {
  char *pcad;
  char unCar[2];

  unCar[0] = car;
  unCar[1] = '\0';
  pcad = new char[n+1];
  strcpy(pcad,"");
  for (ushort i = 0; i < n; i++)
    strcat(pcad,unCar);
  return  pcad;
} // replicate

char *replicate(ushort n, char car) {
  static char cad[81], unCar[2];

  unCar[0] = car;
  unCar[1] = '\0';
  strcpy(cad,"");
  for (ushort i = 0; i < n; i++)
    strcat(cad,unCar);
  return cad;
} // replicate

char* Replicate(char car, int n ) {
    char repCar[1001],
         carCad[2],
         *pCad = repCar;

    strcpy(repCar,"");
    carCad[0] = car;
    carCad[1] = '\0';
    for (int i = 1; i <= n; i++)
        strcat(repCar,carCad);
    return pCad;
} // Replicate

char *Replicate(char car, short n) {
	char *pca2;
	short i = 0;

	pca2 = new char [n+1];
	strcpy(pca2,"");
	for (; i < n; i++)
		pca2[i] = car;
	pca2[i] = '\0';
	return pca2;
} // Replicate

char *Replicate (char *sarta,char car, short n) {
                    // sarta[]

	sarta = new char [n+1];
	strcpy(sarta,"");
	for (short i = 0; i < n; i++)
		*(sarta+i) = car; // sarta[i] = car;
	sarta[n] = '\0';
	return sarta;
} // Replicate

char *replicate(char car, int n) {
  char *cad;
  int i = 0;

  cad = new char [n + 1];
  for ( ; i < n; i++)
    cad[i] = car;
  cad[i] = '\0';
  return cad;
} //replicate

char *Space(int n) {
  char *cad;
  int i = 0;

  cad = new char [n + 1];
  for ( ; i < n; i++)
    cad[i] = ' ';
  cad[i] = '\0';
  return cad;
} //space

char *Space(ushort n) {
  static char cad[81];

  strcpy(cad,"");
  for (ushort i = 0; i < n; ++i)
    strcat(cad," "); // o cad[i] = ' ';
  return cad;
}

char *Strlcat(char *cadDes, char *cadOri) {
  char *cadAux;

  cadAux = new char [strlen(cadDes) + strlen(cadOri) + 1];
  strcpy(cadAux,cadOri);
  strcat(cadAux,cadDes);
  strcpy(cadDes,cadAux);
  delete cadAux;
  return cadDes;
} //strlcat

// ***************************

// Convertir cadena a entero con verificacion

int fatoi(char s[], int &cod) {
  int sign,
      i,
      n;

  for (i = 0; isspace(s[i]); i++ ); // ignora espacio en blanco
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-') // ignora el signo
    i++;
  for (n = 0 ; isdigit(s[i]); i++ )
    n = 10 * n + (s[i] - '0');
  if(s[i] == '\0')
     cod = 0;
  else
    cod = i+1;
  return sign * n;
} // fatoi


int main() {

  cout << MesStr(12);
  return 0;
}

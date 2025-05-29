/*
    Id.Programa: qSort bSearch struct cmp int.cpp
    Autor......: Lic. Hugo Cuello
    Fecha......: enero-2024
    Comentario.: Busca la clave de tipo int en el arreglo ordenado asc.
                 Para que la función bsearch funcione correctamente, el arreglo
                 debe encontrarse ordenado en forma ascendente, por lo que,
                 antes de buscar la clave en el arreglo, previamente es
                 ordenado por medio la funcion qsort en forma ascendente.
                 función bsearch de la libreria stdlib.
    Compilador.: Borland Vers. 5.5
*/

#include <iomanip>
#include <fstream>
using namespace std;

const
  CARD         = 10,
  MAX_SIZE_STR = 20;

typedef char str20[21];

struct sArt {
  int nLeg;
  str20 apeNom;
};

int f_cmp_int (const sArt &i, const sArt &j) {
  return i.nLeg - j.nLeg;
} // comp

void Emite(sArt n[]) {
  for (short i = 0; i < CARD; i++)
    cout << setw(2) << i << ' ' << setw(3) << n[i].nLeg
         << ' ' << n[i].apeNom << endl;
  cout << endl;
} // Emite

main() {
  sArt rArt[] = { 315,"HERNANDEZ",259,"ALVAEZ",812,"PEREZ",
                  127,"QUIROZ",402,"MARTINEZ",706,"LOPEZ",
                  387,"PETROCCELLI",102,"RIOS",
                  321,"CASTILLO",543,"BARRIOS" };
  sArt * ptrItem;
  int   clave;

  clave = 543;
  Emite(rArt);
  qsort (rArt,10,sizeof(sArt),(int(*) (const void *,const void *)) f_cmp_int);
  cout << "Buscar el nro.leg. " << clave << endl;
  ptrItem = (sArt*) bsearch (&clave, rArt, 10, sizeof (sArt),
                             (int(*) (const void *, const void *)) f_cmp_int);
  Emite(rArt);
  if (ptrItem)
    cout << "El nro.leg. " << ptrItem->nLeg
         << " se encuentra en el arreglo en la posicion: "
         << ptrItem - &rArt[0] << endl;
  else
    cout << "El nro.leg. %d NO se encuentra en el arreglo.\n" << clave << endl;
  return 0;
}

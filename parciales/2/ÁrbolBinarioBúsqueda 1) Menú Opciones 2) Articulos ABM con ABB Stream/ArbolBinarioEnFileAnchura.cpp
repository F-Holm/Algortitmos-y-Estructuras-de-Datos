/*
   Id.Programa: ArbolBinarioEnFileAnchuraOtros.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: junio-2015 Fecha original en Pascal junio-2002. Actualiz. 2025-11.
   Comentario.: Insertar, Emitir (In-Orden, Pre-Orden, Pos-Orden, idem anterior
                  pero Inverso), Buscar, Eliminar, Vaciar en Estructura Dinamica
                  no lineal de Arbol Binario de Busqueda.
                  Ademas Lee Datos al inicio, para insertarlos al Arbol y al final
                  Graba los Datos recorriendo el Arbol en Anchura.
*/

typedef short tInfo;
typedef struct sNodo *tTree;
struct sNodo {
  tTree pIzq;
  tInfo Info;
  tTree pDer;
};

#include <conio.h>
#include <iomanip.h>
#include <fstream>
using namespace std;

void CrearArbol(tTree &Tree) {
  Tree = NULL;
} //CrearAbrol

bool ArbolVacio(tTree &Tree) {
  return Tree == NULL;
} //ArbolVacio

/*
bool ArboLleno(short MagnitudNodo) {
  return MagnitudNodo > 10000;
} //ArbolLleno
*/

void InsertarHoja(tTree &Tree, short valor) {
  if (ArbolVacio(Tree)) {
    tTree pNvo = new sNodo;
    pNvo->Info = valor;
    pNvo->pIzq = NULL;
    pNvo->pDer = NULL;
    Tree = pNvo;
  }
  else
    if (valor < Tree->Info)
      InsertarHoja(Tree->pIzq,valor);
    else
      InsertarHoja(Tree->pDer,valor);
} //InsertarHoja

void ListarInOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarInOrden(Tree->pIzq);
    cout << setw(4) << Tree->Info;
    ListarInOrden(Tree->pDer);
  }
} //ListarInOrden

void ListarInOrdenInv(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarInOrdenInv(Tree->pDer);
    cout << setw(4) << Tree->Info;
    ListarInOrdenInv(Tree->pIzq);
  }
} //ListarInOrdenInv

void ListarPreOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    cout << setw(4) << Tree->Info;
    ListarPreOrden(Tree->pIzq);
    ListarPreOrden(Tree->pDer);
  }
} //ListarPreOrden

void ListarPreOrdenInv(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    cout << setw(4) << Tree->Info;
    ListarPreOrdenInv(Tree->pDer);
    ListarPreOrdenInv(Tree->pIzq);
  }
} //ListarPreOrdenInv

void ListarPosOrden(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarPosOrden(Tree->pIzq);
    ListarPosOrden(Tree->pDer);
    cout << setw(4) << Tree->Info;
  }
} //ListarPosOrden

void ListarPosOrdenInv(tTree &Tree) {
  if (!ArbolVacio(Tree)) {
    ListarPosOrdenInv(Tree->pDer);
    ListarPosOrdenInv(Tree->pIzq);
    cout << setw(4) << Tree->Info;
  }
} //ListarPosOrdenInv

tTree BuscarNodo(tTree &Tree, tInfo valor) {
  if (ArbolVacio(Tree))
    return NULL;
  else
    if (valor == Tree->Info)
      return Tree;
    else
      if (valor < Tree->Info)
        return BuscarNodo(Tree->pIzq,valor);
      else
        return BuscarNodo(Tree->pDer,valor);
} //BuscarNodo

void EliminarNodo(tTree &Tree, tInfo valor) {
  tTree pAct,
        pAnt,
        pElim;

  if (!ArbolVacio(Tree))
    if (valor < Tree->Info)
      EliminarNodo(Tree->pIzq,valor);
    else
      if (valor > Tree->Info)
        EliminarNodo(Tree->pDer,valor);
      else {
        pElim = Tree;
        if (!pElim->pDer)
          Tree = pElim->pIzq;
        else
          if (!pElim->pIzq)
            Tree = pElim->pDer;
          else {
            pAct = pElim->pIzq;
            pAnt = pAct;
            while (pAct->pDer) {
              pAnt = pAct;
              pAct = pAct->pDer;
            }
            if (pAct == pAnt)
              pElim->pIzq = pAct->pIzq;
            pElim->Info = pAct->Info;
            pElim = pAct;
            pAnt->pDer = pAct->pIzq;
          }
        delete pElim;
        gotoxy(1,23); clreol();
        cout << "El elemento " << setw(3) << valor << " fue eliminado... ";
      }
  else {
    gotoxy(1,23); clreol();
    cout << "El elemento " << valor << " no existe... ";
  }
} //EliminarNodo

void EliminarPosOrden(tTree &Tree) {
  if (Tree) {
    EliminarPosOrden(Tree->pIzq);
    EliminarPosOrden(Tree->pDer);
    cout << "Elimina Info: " << Tree->Info << endl;
    delete(Tree);
  }
  Tree = NULL;
} // EliminarArbol

short IngElem(string mens) {
  short elem;

  gotoxy(14,13);
  cout << mens;
  gotoxy(10,25);
  cout << "Para finalizar ingresar un valor = 0...";
  gotoxy(1,14); clreol();
  cout << "Ing. valor: ";
  cin >> elem;
  return elem;
} //IngElem

void GrabarPorNiveles(fstream &Datos, tTree &Tree, int nivel) {
  if (Tree) {
    if (nivel == 0)
      Datos << Tree->Info << endl;
    GrabarPorNiveles(Datos,Tree->pIzq,nivel - 1);
    GrabarPorNiveles(Datos,Tree->pDer,nivel - 1);
  }
} // GrabarPorNiveles

bool Leer(fstream &Datos, short &elem) {
  Datos >> elem;
  Datos.ignore();
  return Datos.good();
} // Leer

void ListarPorNiveles(tTree &Tree, int nivel) {
  if (Tree) {
    if (nivel == 0)
      cout << setw(4) << Tree->Info << ' ';
    ListarPorNiveles(Tree->pIzq,nivel - 1);
    ListarPorNiveles(Tree->pDer,nivel - 1);
  }
} // ListarPorNiveles

int Nivel(tTree &Tree) {
  if (Tree) {
    int izq = Nivel(Tree->pIzq) + 1;
    int der = Nivel(Tree->pDer) + 1;
    if (izq > der)
      return izq;
    else
      return der;
  }
  return 0;
} // Nivel

void GrabarPreOrden(fstream &Datos, tTree &pRoot) {
  short Info;

  if (!ArbolVacio(pRoot)) {
    Datos << pRoot->Info << endl;       // R
    GrabarPreOrden(Datos,pRoot->pIzq);  // I
    GrabarPreOrden(Datos,pRoot->pDer);  // D
  }
} //GrabarPreOrden

void RecorrerNiveles(fstream &Datos, tTree &Tree) {
  for (int i = 0; i < Nivel(Tree); i++)
    GrabarPorNiveles(Datos,Tree,i);
} // RecorrerNiveles

void GrabarArbolNivel(fstream &Datos, tTree &Tree) {
  Datos.close();
  remove("Datos.Txt");
  Datos.open("Datos.Txt");
  RecorrerNiveles(Datos,Tree);
} // GrabarArbolNivel

int main() {
  tTree pRoot,
        pNodo;
  short  elem;
  char  opc;

  fstream Datos("Datos.Txt",ios::in | ios::out);
  CrearArbol(pRoot);
  while (Leer(Datos,elem))    // Datos iniciales en el archivo de Datos.Txt:
    InsertarHoja(pRoot,elem); // 15, 6, 9, 20, 24, 3, 18, 7, 17, 4, 1.
  Datos.clear();
  Datos.seekg(0);
  textcolor(WHITE);
  textbackground(BLUE);
  do {
    clrscr();
    cout << "1: Insertar" <<endl;
    cout << "2: Quitar" << endl;
    cout << "3: Listar In-Orden" << endl;           // I R D
    cout << "a: Listar In-Orden Inverso" << endl;   // D R I
    cout << "4: Listar Pre-Orden" << endl;          // R I D
    cout << "b: Listar Pre-Orden Inverso" << endl;  // R D I
    cout << "5: Listar Pos-Orden" << endl;          // I D R
    cout << "c: Listar Pos-Orden Inverso" << endl;  // D I R
    cout << "6: Listar por Anchura" << endl;        // Recorrer por niveles
    cout << "7: Buscar Elemento" << endl;
    cout << "8: Vaciar Arbol" << endl;
    cout << "9: Grabar Por Niveles" << endl;
    cout << "0: Finalizar" << endl;
    cout << "Su opcion: ";
    opc = getche();
    cout << endl;
    switch(opc) {
      case '1':
        gotoxy(14,13);
        while (elem = IngElem("Insertar"))
          InsertarHoja(pRoot,elem);
        break;
      case '2':
        gotoxy(14,13); clreol();
        elem = IngElem("Quitar");
        while (elem) {
          EliminarNodo(pRoot,elem);
          gotoxy(1,24); clreol();
          system("pause");
          gotoxy(1,23); clreol();
          gotoxy(1,24); clreol();
          elem = IngElem("Quitar");
        }
        break;
      case '3':
        gotoxy(14,13); clreol();
        cout << "Listar In-Orden...";
        gotoxy(1,16);
        ListarInOrden(pRoot);
        gotoxy(1,24); clreol();
        system("pause");
        break;
       case 'a':
        gotoxy(14,13); clreol();
        cout << "Listar In-Orden Inverso...";
        gotoxy(1,16);
        ListarInOrdenInv(pRoot);
        gotoxy(1,24); clreol();
        system("pause");
        break;
      case '4':
        gotoxy(14,13); clreol();
        cout << "Listar Pre-Orden...";
        gotoxy(1,16);
        ListarPreOrden(pRoot);
        gotoxy(1,24); clreol();
        system("pause");
        break;
      case 'b':
        gotoxy(14,13); clreol();
        cout << "Listar Pre-Orden Inverso...";
        gotoxy(1,16);
        ListarPreOrdenInv(pRoot);
        gotoxy(1,24); clreol();
        system("pause");
        break;
      case '5':
        gotoxy(14,13); clreol();
        cout << "Listar Pos-Orden...";
        gotoxy(1,16);
        ListarPosOrden(pRoot);
        gotoxy(1,24); clreol();
        system("pause");
        break;
      case 'c':
        gotoxy(14,13); clreol();
        cout << "Listar Pos-Orden Inverso...";
        gotoxy(1,16);
        ListarPosOrdenInv(pRoot);
        gotoxy(1,24); clreol();
        system("pause");
        break;
      case '6':
        gotoxy(14,13); clreol();
        cout << "Listar Por Niveles...";
        gotoxy(1,14);
        for (int i = 0; i < Nivel(pRoot); i++) {
          cout << "nivel " << i << ": ";
          ListarPorNiveles(pRoot,i);
          cout << endl;
        }
        gotoxy(1,24); clreol();
        system("pause");
        gotoxy(1,24); clreol();
        break;
      case '7':
        gotoxy(14,13); clreol();
        elem = IngElem("Buscar");
        while (elem) {
          pNodo = BuscarNodo(pRoot,elem);
          gotoxy(1,23); clreol();
          if (pNodo)
            cout << "El elemento " << pNodo->Info << " se encontro...";
          else
            cout << "El elemento " << elem << " no existe... ";
          gotoxy(1,24);
          system("pause");
          gotoxy(1,23); clreol();
          gotoxy(1,24); clreol();
          gotoxy(1,16); clreol();
          elem = IngElem("Buscar");
        }
        break;
      case '8':
        gotoxy(14,13); clreol();
        cout << "Vaciar Arbol RecorrerPosOrd..." << endl;
        EliminarPosOrden(pRoot);
        pRoot = NULL; // Asegura que el puntero externo al arbol no apunte a nada.
        gotoxy(1,24);
        system("pause");
        gotoxy(1,24); clreol();
        break;
      case '9':
        gotoxy(14,13); clreol();
        cout << "Grabar Por Niveles...";
        gotoxy(1,14);
        Datos.close();
        remove("Datos.Txt");
        Datos.open("Datos.Txt");       // Archivo de datos al GrabarArbolNivel.
        GrabarArbolNivel(Datos,pRoot); // 15, 6, 20, 3, 9, 18, 24, 1, 4, 7, 17.
        cout << endl;         // Asumiendo que NO se ingresan y eliminan datos.
        gotoxy(1,24); clreol();
        system("pause");
        gotoxy(1,24); clreol();
        break;
    }
  }
  while (opc != '0');
  Datos.close();
  remove("Datos.Txt");
  Datos.open("Datos.Txt");       // Archivo de datos al GrabarPreOrden.
  GrabarPreOrden(Datos,pRoot);   // 15, 6, 3, 1, 4, 9, 7, 20, 18, 17, 24.
  EliminarPosOrden(pRoot);       // Asumiendo que NO se ingresan y eliminan datos.
  Datos.close();
  return 0;
}


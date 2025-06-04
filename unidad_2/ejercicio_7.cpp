// Unidad 2 - Ejercicio 7
#include <fstream>
#include <iostream>

using namespace std;

const char kFemenino = 'F';
const char kMasculino = 'M';
const short kMaxTemas = 30;
const short kMaxEncuestados = 10000;

struct Rank {
  short tema;
  short votos = 0;
  short h30 = 0;  // cantidad hombre mayor a 30
  bool mujer = false;
};

struct Encuestado {
  char sexo;  // 'F' | 'M'
  short edad = -1;
  short temas[3];
};

void InicializarRanking(Rank* ranking);
void Ordenar(Rank* ranking);
void Swap(Rank& a, Rank& b);
void CargarEncuestas(Encuestado* encuestas);
void ProcesarEncuestas(Rank* ranking, Encuestado* encuestados);
void EmitirTemaMasVotadoH30(Rank* ranking);
void EmitirTemasNoElegidosMujeres(Rank* ranking);
void EmitirRanking(Rank* ranking);

int main() {
  Rank ranking[kMaxTemas + 1];
  Encuestado encuestas[kMaxEncuestados];

  InicializarRanking(ranking);
  CargarEncuestas(encuestas);
  ProcesarEncuestas(ranking, encuestas);
  EmitirTemaMasVotadoH30(ranking);
  EmitirTemasNoElegidosMujeres(ranking);
  Ordenar(ranking);
  EmitirRanking(ranking);
  return 0;
}

void InicializarRanking(Rank* ranking) {
  for (short i = 1; i <= kMaxTemas; i++) ranking[i].tema = i;
}

void Ordenar(Rank* ranking) {
  for (short i = 1; i <= kMaxTemas; i++) {
    short max = i;
    for (short j = i; j <= kMaxTemas; j++)
      if (ranking[max].votos < ranking[j].votos) max = j;
    if (i != max) Swap(ranking[i], ranking[max]);
  }
}

void Swap(Rank& a, Rank& b) {
  Rank t = a;
  a = b;
  b = t;
}

void CargarEncuestas(Encuestado* encuestas) {
  ifstream archivo("unidad_2/Encuestas.txt");
  short i = 0;
  do {
    archivo >> encuestas[i].sexo >> encuestas[i].edad;
    for (short j = 0; j <= 2; j++) archivo >> encuestas[i].temas[j];
    archivo.ignore();
    i++;
    cout << encuestas[i].sexo << endl;
  } while (archivo.good());
  cout << "i: " << i << endl;
  archivo.close();
}

void ProcesarEncuestas(Rank* ranking, Encuestado* encuestados) {
  for (short i = 0; i < kMaxEncuestados && encuestados[i].edad > 0; i++) {
    for (short j = 0; j < 3; j++) {
      ranking[encuestados[i].temas[j]].votos++;
      if (encuestados[i].sexo == kMasculino && encuestados[i].edad >= 30)
        ranking[encuestados[i].temas[j]].h30++;
      else if (encuestados[i].sexo == kFemenino)
        ranking[encuestados[i].temas[j]].mujer = true;
    }
  }
}

void EmitirTemaMasVotadoH30(Rank* ranking) {
  short max = 1;
  for (short i = 2; i <= kMaxTemas; i++)
    if (ranking[max].h30 < ranking[i].h30) max = i;
  cout << "El tema más votado por hombres de 30 años o más es '" << max
       << "' con '" << ranking[max].h30 << "' votos" << endl;
}

void EmitirTemasNoElegidosMujeres(Rank* ranking) {
  cout << "Temas no elegidos por ninguna mujer:\n";
  for (short i = 1; i <= kMaxTemas; i++)
    if (!ranking[i].mujer) cout << "- " << i << endl;
  cout << endl;
}

void EmitirRanking(Rank* ranking) {
  cout << "Ranking:\n";
  for (short i = 1; i <= kMaxTemas; i++)
    cout << i << ") " << ranking[i].tema << endl;
}
// Unidad 2 - Ejercicio 4
#include <iostream>

using namespace std;

#define TAMANO_P 38
#define TAMANO_Q 43
#define MAX 90

void Generar(short *v, const unsigned short &size);
void Ordenar();
short *Interseccion(short *p, short *q, short &tamano_i);
short *Union(short *p, short *q, short &tamano_u);
short *DiferenciaPQ(short *p, short *q, short &tamano_d);
short *DiferenciaSimPQ(short *p, short *q, short &tamano_ds);

int main() {
  short p[TAMANO_P];
  short q[TAMANO_Q];

  Generar(p, TAMANO_P);
  Generar(q, TAMANO_Q);

  // ordenar();

  Union(p, q);

  return 0;
}

void Generar(short *v, const unsigned short &size) {
  bool repetido[MAX];
  for (short i = 0; i < MAX; i++) repetido[i] = false;
  for (short i = 0; i < size; i++) {
    short n = rand() % MAX;
    if (!repetido[n]) {
      v[i] = n + 1;
      repetido[n] = true;
    }
  }
}

short *Interseccion(short *p, short *q, short &tamano_i) {
  short contador, x = 0;
  if (TAMANO_P < TAMANO_Q)
    contador = TAMANO_Q;
  else
    contador = TAMANO_P;
  short *intersec[contador];

  for (int i = 0; i < contador; i++) {
    if (p[i] == q[i]) {
      *intersec[x] = p[i];
      x++;
    }
  }

  return *intersec;
}

short *Union(short *p, short *q, short &tamano_u) {
  short uni[TAMANO_P + TAMANO_Q];

  short i = 0, j = 0, k = 0;
  while (i < TAMANO_P || j < TAMANO_Q) {
    if ((i < TAMANO_P && j == TAMANO_Q) || p[i] < q[j]) {
      uni[k] = p[i];
      i++;
    } else if ((i == TAMANO_P && j < TAMANO_Q) || p[i] > q[j]) {
      uni[k] = q[j];
      j++;
    } else {  // ==
      uni[k] = p[i];
      i++;
      j++;
    }
    k++;
  }

  tamano_u = k;
  short *ret = new short[tamano_u];
  for (int i = 0; i < tamano_u; i++) ret[i] = uni[i];
  return uni;
}

short *DiferenciaPQ(short *p, short *q, short &tamano_d) {
  short contador, x = 0;
  if (TAMANO_P < TAMANO_Q)
    contador = TAMANO_Q;
  else
    contador = TAMANO_P;
  short *dif[contador];

  for (int i = 0; i < contador; i++) {
    if (p[i] != q[i]) {
      *dif[x] = p[i];
      x++;
    }
  }

  return *dif;
}

short *DiferenciaSimPQ(short *p, short *q, short &tamano_ds) {
  short contador, x = 0;
  if (TAMANO_P < TAMANO_Q)
    contador = TAMANO_Q;
  else
    contador = TAMANO_P;
  short *difSim[contador];

  for (int i = 0; i < contador; i++) {
    if (p[i] != q[i]) {
      *difSim[x] = p[i];
      x++;
      *difSim[x] = q[i];
      x++;
    }
  }

  return *difSim;
}

short *ComplementoPuQ(short *p, short *q, short &tamano_c, short &tamano_u) {
  short x = 0;
  short *u[tamano_u], *c[tamano_c];
  *u = Union(p, q, tamano_u);
  for (short i = 0; i < 90; i++) {
    if (*u[i] != i) {
      *c[x] = i;
      x++;
    }
  }

  return *c;
}
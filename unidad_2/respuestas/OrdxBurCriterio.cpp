

void Ordenar(int v[], int n, int(*criterio(int, int))) {
  int k = 0;
  bool ordenado;

  do {
    k++;
    ordenado = true;
    for (int i = 0; i < n; i++)
      if (criterio(v[i] > v[i + 1])) {
        IntCmb(v[i], v[i + 1]) ordenado = false;
      }
  } while (!ordenado);
}  // Ordenar

main() {
  int vec[100];

  for (int i = 0; i < 100; i++)
    v[i] = random(900) + 100;
}

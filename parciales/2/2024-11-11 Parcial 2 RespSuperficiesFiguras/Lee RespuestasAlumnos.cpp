// Lee RespuestasAlumnos.Dat

#include <fstream>
using namespace std;

#define record struct
typedef char str20[21];
typedef char str10[11];

record sResp {
  str10 nomAlu;
  short cantRespCor,
        cantRespIncor;
  str20 nomFig;
};

main() {
  ifstream RespAlu("RespuestasAlumnos.Dat",ios::binary);
  sResp    rResp;

  while (RespAlu.read((char *) &rResp, sizeof rResp))
    cout << rResp.nomAlu << ' ' << rResp.cantRespCor << ' '
         << rResp.cantRespIncor << ' ' << rResp.nomFig << endl;
  RespAlu.close();
  return 0;
}

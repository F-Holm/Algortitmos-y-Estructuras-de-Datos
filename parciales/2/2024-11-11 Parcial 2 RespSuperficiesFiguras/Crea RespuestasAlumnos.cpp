// Crea RespuestasAlumnos.Dat a partir de RespuestasAlumnos.Txt

#include <fstream>
using namespace std;

#define record struct
typedef char str20[21];
typedef char str10[11];

record sResp {
  str10 nomAlu;
  bool  EsRespCor;
  str20 nomFig;
};

bool LeeResp(ifstream &Resp, sResp &rResp) {
  Resp.get(rResp.nomAlu,11);
  Resp >> rResp.EsRespCor;
  Resp.ignore();
  Resp.get(rResp.nomFig,21);
  Resp.ignore();
  return Resp.good();
} // LeeResp

main() {
  ifstream RespAluTxt("RespuestasAlumnos.Txt");
  ofstream RespAlu("RespuestasAlumnos.Dat", ios::binary);
  sResp    rResp;

  while (LeeResp(RespAluTxt,rResp))
    RespAlu.write((char *) &rResp, sizeof rResp);
  RespAluTxt.close();
  RespAlu.close();
  return 0;
}

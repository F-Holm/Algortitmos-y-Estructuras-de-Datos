/*
   Id.Programa: Cadenas Cpp.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: mayo-2016
   Comentario.: Tratamiento de cadenas en C++
*/

#include <iostream>
#include <string>
using namespace std;

int main () {
  string s0 ("Constructor de cadena");

  // constructores de cadenas:
  string s1;
  string s2 (s0);
  string s3 (s0, 8, 3);
  string s4 ("Una secuencia de caracteres");
  string s5 ("Otra secuencia de caracteres", 12);
  string s6a (10, 'x');
  string s7 (s0.begin(), s0.begin()+1);
  cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  cout << "\ns6b: " << "s6b" << "\ns7: " << s7 << '*' << '\n';
  string str ("Verificar cadena");
  for ( string::iterator it=str.begin()+3; it!=str.end()-2; ++it)
    cout << *it;
  cout << '\n';
  str = "lamina";
  for ( string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
    cout << *rit;
  cout << '\n';
  str = "Test string";
  std::cout << "size: " << str.size() << "\n";
  std::cout << "length: " << str.length() << "\n";
  std::cout << "capacity: " << str.capacity() << "\n";
  std::cout << "max_size: " << str.max_size() << "\n";
  str.push_back('*');
  cout << str << endl;
  str = "suman";
  str.insert(2,"per");
  cout << str << endl;
  str.erase(2,3);
  cout << str << endl;
  return 0;
}

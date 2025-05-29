/*
   Id.Programa: Cadenas C-Cpp.cpp
   Autor......: Lic. Hugo Cuello
   Fecha......: mayo-2016
   Comentario.: Tratamiento de cadenas en C / C++
*/

#include <fstream>
#include <iostream>
using namespace std;

void SplitFilename(const string& str){
  cout << "Splitting: " << str << endl;
  size_t found = str.find_last_of("/\\");
  cout << " path: " << str.substr(0,found) << endl;
  cout << " file: " << str.substr(found + 1) << endl;
} // SplitFilename

int main() {
  char cad1[51],cad2[51];
  char *pcad1, *pcad2;
  string str1,str2,str3;

  // ------------- Constructors ---------------------

  string s0 ("Initial string");
  string s1;
  string s2 (s0);
  string s3 (s0, 8, 3);
  string s4 ("A character sequence");
  string s5 ("Another character sequence");
  string s6a (10, 'x');
  string s6b (10, '*');      // 42 is the ASCII code for '*'
  string s7 (s0.begin(), s0.begin()+7);

  cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  cout << "\ns6b: " << s6b << "\ns7: " << s7 << endl;

  // ------------- Copiar cadena a una variable -----
  // --- =
  // ------------------------------------------------

  strcpy(cad1,"Algoritmos y Estructuras");
  pcad1 = new char[strlen(cad1) + 1];
  strcpy(pcad1,cad1);
  str1 = cad1;
  cout << "cad1: " << cad1 << endl;
  cout << "pcad1: " << pcad1 << endl;
  cout << "str1: " << str1 << endl;

  // ------------- Concatenar cadenas ---------------
  // --- +
  // ------------------------------------------------

  strcpy(cad2," de Datos");
  pcad2 = new char[strlen(cad2) + 1];
  strcpy(pcad2,cad2);
  delete pcad1;
  pcad1 = new char[strlen(cad1) + strlen(cad2) + 1];
  strcpy(pcad1,cad1);
  strcat(pcad1,pcad2);
  str2 = cad2;
  str1 = str1 + str2;
  cout << "cad1: " << cad1 << endl;
  cout << "pcad1: " << pcad1 << endl;
  cout << "str1: " << str1 << endl;

  // ------------- Comparar cadenas -----------------

  if (!strcmp(cad1,pcad1))
    cout << "cad1 = pcad1" << endl;
  else
    if (strcmp(cad1,pcad1) < 0)
      cout << "cad1 < pcad1" << endl;
    else
      cout << "cad1 > pcad1" << endl;

  // -------------- Operadores Relacionales --------
  // --- ==, !=, >, <, >=, <=
  // -----------------------------------------------

  if (str1 == str2)
    cout << "str1 = str2" << endl;
  else
    if (str1 < str2)
      cout << "str1 < str2" << endl;
    else
      cout << "str1 > str2" << endl;
  if (str1 <= str2)
    cout << "str1 <= str2" << endl;
  if (str1 >= str2)
    cout << "str1 >= str2" << endl;
  if (str1 != str2)
    cout << "str1 != str2" << endl;

  // ------------- Longitudes de cadenas en C -------

  cout << "Longitudes..." << endl;
  cout << strlen(cad1) << endl;
  cout << strlen(pcad1) << endl;

  // ------------- Capacity -------------------------
  // --- size(), length(), capacity(), max_size(),
  // --- resize(), reserve(), clear(), empty()
  // ------------------------------------------------

  cout << str1.size() << endl;
  cout << str1.length() << endl; // equivale a size
  cout << str1.capacity() << endl;
  cout << str1.max_size() << endl;
  cout << boolalpha << str1.empty() << endl;
  str1.clear();
  str1.reserve(51);
  str1.resize(str1.size() + 4,'+');
  cout << str1 << endl;

  // ------------- Acceso a elementos --------------
  // --- Op [], at()
  // -----------------------------------------------

  cout << cad1[2] << endl;
  cout << pcad1 << endl;
  cout << str1[3] << endl;
  cout << str1.at(2) << endl;

  // ------------- Modifiers ------------------------------------------
  // --- Op +=, append, assign, insert, erase, replace, swap, push_back
  // ------------------------------------------------------------------

  // ----- erase -----

  str1 = str1 + " concatena a der.";
  cout << str1 << endl;
  str1 = "Concatena a izq. " + str1;
  cout << str1 << endl;
  str1 += " + simple para concatenar a der.";
  cout << str1 << endl;
  str1.erase(str1.begin()+4,str1.end()-23);
  cout << str1 << endl;
  str1.erase(1,3);
  cout << str1 << endl;
  str1.erase(str1.begin()+10); // elimina un caracter
  cout << str1 << endl;
  str1.erase(); // elimina toda la cadena = clear()
  cout << str1 << endl;
  str1 = "Concatenar cadenas";
  str1 = str1 + ' ' + "de caracteres";
  cout << str1 << endl;

  // ----- replace -----

  string base = "this is a test string.";

  str2 = "n example";
  str3 = "sample phrase";

  string str4 = "useful";
  string str = base;

  str.replace(9,5,str2);
  str.replace(19,6,str3,7,6);
  str.replace(8,10,"just a");
  str.replace(8,6,"a shorty",7);
  str.replace(22,1,3,'!');
  str.replace(str.begin(),str.end() - 3,str3);
  str.replace(str.begin(),str.begin()+6,"replace");
  str.replace(str.begin() + 8,str.begin() + 14,"is coolness",7);
  cout << str << endl;
  str.replace(str.begin() + 12,str.end() - 4,4,'o');
  cout << str << endl;
  str.replace(str.begin() + 11,str.end(),str4.begin(),str4.end());
  cout << str << endl;

  // ----- append -----

  str = "";
  str2 = "Writing ";
  str3 = "print 10 and then 5 more";
  str.append(str2);
  cout << str << endl;
  str.append(str3,6,3);
  cout << str << endl;
  str.append("dots are cool",5);
  cout << str << endl;
  str.append("here: ");
  str.append(10u,'.');
  cout << str << endl;
  str.append(str3.begin() + 8,str3.end());
  cout << str << endl;

  // ----- assign -----

  str = "";
  base = "The quick brown fox jups over a lazy dog.";
  str.assign(base);
  cout << str << endl;
  str.assign(base,10,9);
  cout << str << endl;
  str.assign("pangrams are cool",7);
  cout << str << endl;
  str.assign("c-string");
  cout << str << endl;
  str.assign(10,'*');
  cout << str << endl;
  str.assign(base.begin() + 16,base.end() - 12);
  cout << str << endl;

  // ----- push_back -----

  str = "";
  ifstream file("FileTexto.cpp",ios::in);
  if (file)
    while (!file.eof())
      str.push_back(file.get());
  cout << str << endl;

  // ----- insert -----

  str = "to be question";
  str2 = "the ";
  str3 = "or not to be";
  str.insert(6,str2);
  str.insert(6,str3,3,4);
  str.insert(10,"that is cool",8);
  str.insert(10,"to be ");
  str.insert(15,1,':');
  cout << str << endl;
  str.insert(6,"or ");
  cout << str << endl;

  // ----- swap -----

  string buyer ("money");
  string seller ("goods");

  cout << "antes: buyer es " << buyer << endl;
  cout << " y seller es    " << seller << endl;
  seller.swap(buyer);
  cout << "despues: buyer es " << buyer << endl;
  cout << " y seller es      " << seller << endl;

  // ------------- Operaciones con String ------------------------
  // --- c_str(), copy(), find(), rfind(), find_first_of(),
  // --- find_last_of(), find_first_not_of(), find_last_not_of(),
  // --- substr(), compare()
  // -------------------------------------------------------------

  // ----- c_str -----

  str = ("Please split this sentence into tokens");
  char *cstr = new char[str.length() + 1];

  strcpy(cstr,str.c_str());
  char *p = strtok(cstr," ");
  while (p) {
    cout << p << endl;
    p = strtok(NULL, " ");
  }
  delete[] cstr;

  // ----- copy -----

  char buffer[20];

  str = "Test string...";
  size_t length = str.copy(buffer,6,5);
  buffer[length] = '\0';
  cout << "buffer contains: " << buffer << endl;

  // ----- substr -----

  str = "We think in generalitiees, but we live in details.";
  str2 = str.substr(3,5);
  cout << str2 << endl;

  size_t pos = str.find("live");

  str3 = str.substr(pos);
  cout << str2 << ' ' << str3 << endl;

  // ----- compare -----

  str1 = "green apple";
  str2 = "red apple";

  if (str1.compare(str2))
    cout << str1 << " no es " << str2 << endl;
  if (!str1.compare(6,5,"apple"))
    cout << "still, " << str1 << " es una manzana" << endl;
  if (!str2.compare(str2.size() - 5,5,"apple"))
    cout << "and " << str2 << " tambien es una manzana" << endl;
  if (!str1.compare(6,5,str2,4,5))
    cout << "por consiguiente, ambas son manzanas" << endl;

  // ----- find -----

  str = "There are two needles in this haystack with needles.";
  str2 = "needle";

  size_t found = str.find(str2);

  if (found != string::npos)
    cout << "first 'needle' found at: " << found << endl;
  found = str.find("needles are small",found + 1,6);
  if (found != string::npos)
    cout << "second 'needle' found at: " << found << endl;
  found = str.find("haystack");
  if (found != string::npos)
    cout << "'haystack' also found at: " << found << endl;
  found = str.find('.');
  if (found != string::npos)
    cout << "Period found at: " << found << endl;
  str.replace(str.find(str2),str2.length(),"preposition");
  cout << str << endl;

  // ----- rfind -----

  str = "The sixth sick sheik's sixth sheep's sick.";
  string key = "sixth";
  found = str.rfind(key);
  if (found != string::npos)
    str.replace(found,key.length(),"seventh");
  cout << str << endl;

  // ----- find_first_of -----

  str = "Please, replace the vowels in this sentence by asterisks.";
  found = str.find_first_of("aeiou");
  while (found != string::npos) {
    str[found] = '*';
    found = str.find_first_of("aeiou",found + 1);
  }
  cout << str << endl;

  // ----- find_last_of -----

  str1 = "/usr/bin/man";
  str2 = "c:\\windows\\winhelp.exe";
  SplitFilename(str1); // aca esta find_last_of
  SplitFilename(str2);

  // ----- find_first_not_of -----

  str = "look for non-alphabetic characters...";
  found = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
  if (found != string::npos)
    cout << "The first non-alphabetic character is " << str[found];
    cout << " at position " << found << endl;

  // ----- find_last_not_of -----

  str = "Please, erase trailing white-spacesd   \n";
  string whitespaces (" \t\f\v\n\r");
  found = str.find_last_not_of(whitespaces);
  if (found != string::npos)
    str.erase(found + 1);
  else
    str.clear();
  cout << '[' << str << ']' << endl;

  // ------------- Iterators ------------------------
  // ------------- begin() / end() ------------------

  str = "Test string";

  for (string::iterator it = str.begin(); it != str.end(); it++) {
    cout << *it; // emite solamente el caracter al que apunta
    cout << '\n';
  }

  for (string::iterator it = str.begin(); it != str.end(); it++) {
    cout << it; // emite desde donde apunta hasta el fin de la cadena
    cout << '\n';
  }

  //-------------- rbegin() / rend() ---------------

  for (string::reverse_iterator rit = str.rbegin(); rit != str.rend(); rit++) {
    cout << *rit; // emite solamente el caracter al que apunta
    cout << '\n';
  }
  cout << sizeof (char) << endl << sizeof (short) << endl << sizeof (unsigned) << endl;
  cout << sizeof (unsigned short) << endl;
  return 0;
}

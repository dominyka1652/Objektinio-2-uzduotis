#include "v0.3upgraded.h"

int main(){
int ndSkaicius = 0;
std::string arZinoKiek; // ar yra zinomas namu darbu skaicius
std::vector<Studentas> rezultatai;
rezultatai.reserve(1000);
rezultatai[1000].namuDarbai.reserve(200);
std::cout << "Ar norite duomenis ivesti ranka, ar nuskaityti is failo?\n Jei ivesti ranka, irasykite 'ivesti', kitu atveju irasykite 'nuskaityti': ";
duomenys(arZinoKiek,ndSkaicius,rezultatai);
std::cout << "\n Programa baigta vykdyti \n";
}

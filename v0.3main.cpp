#include "v0.3.h"

int main(){
std::string arZinoKiek; // ar yra zinomas namu darbu skaicius
std::vector<Studentas> rezultatai;
rezultatai.reserve(100);
std::cout << "Ar norite duomenis ivesti ranka, ar nuskaityti is failo?\n Jei ivesti ranka, irasykite 'ivesti', kitu atveju irasykite 'nuskaityti': ";
duomenys(arZinoKiek,rezultatai);
}

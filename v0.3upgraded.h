#ifndef V0_3UPGRADED_H_INCLUDED
#define V0_3UPGRADED_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>
#include <fstream>
#include <chrono>
struct Studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};

void ifFail ();
bool SortByPavarde(Studentas a, Studentas b);
Studentas pazymiuIvedimas (std::string kaipIvestiPazymius, int i, int ndSkaicius, Studentas b);
Studentas pazymiuIvedimas2(std::string kaipIvestiPazymius,int i,int ndSkaicius,Studentas b);
void vidurkisMediana (std::vector<Studentas> rezultatai, int kiekStudentu, int ndSkaicius);
void Skaitymas(std::vector<Studentas> rezultatai,int ndSkaicius, int kiekStudentu, Studentas (*kazkoksIvedimas)(std::string, int, int,Studentas));
void Ivedimas (std:: string arZinoKiek, int ndSkaicius, std::vector<Studentas> rezultatai, int kiekStudentu);
void NuskaitytiIsFailo(int &ndSkaicius,std::vector<Studentas> rezultatai);
void KiekyraStudentu(std::string arZinoKiek, int ndSkaicius, std::vector<Studentas> rezultatai);
void duomenys(std::string arZinoKiek, int ndSkaicius, std::vector<Studentas> rezultatai);

#endif // V0_3UPGRADED_H_INCLUDED

#ifndef V0_3_H_INCLUDED
#define V0_3_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <random>
#include <fstream>
#include <chrono>
struct Studentas{
    int ndSkaicius;
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};

void ifFail ();
bool SortByPavarde(Studentas a, Studentas b);
Studentas generavimas (int input, Studentas b);
Studentas pazymiuIvedimas (std::string kaipIvestiPazymius, int i,Studentas b);
Studentas pazymiuIvedimas2(std::string kaipIvestiPazymius,int i,Studentas b);
void vidurkisMediana (std::vector<Studentas> &rezultatai, int kiekStudentu);
void Skaitymas(std::vector<Studentas> &rezultatai,int kiekStudentu,int nd, Studentas (*kazkoksIvedimas)(std::string, int,Studentas));
void Ivedimas (std::string arZinoKiek,std::vector<Studentas> &rezultatai, int kiekStudentu);
void NuskaitytiIsFailo(std::vector<Studentas> &rezultatai);
void KiekyraStudentu(std::string arZinoKiek, std::vector<Studentas> rezultatai);
void duomenys(std::string arZinoKiek,std::vector<Studentas> rezultatai);

#endif // V0_3_H_INCLUDED

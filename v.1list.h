#ifndef V_1LIST_H_INCLUDED
#define V_1LIST_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <random>
#include <fstream>
#include <chrono>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
struct Studentas{
    int ndSkaicius;
    std::string vardas;
    std::string pavarde;
    std::list<int> namuDarbai;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;
};
void ifFail ();
bool SortByPavarde(Studentas& a, Studentas& b);
bool SortByVid(Studentas a, Studentas b);
bool SortByMed(Studentas a, Studentas b);
Studentas generavimas (int input, Studentas b);
Studentas pazymiuIvedimas (std::string kaipIvestiPazymius, int i,Studentas b);
Studentas pazymiuIvedimas2(std::string kaipIvestiPazymius,int i,Studentas b);
void Spausdinimas (std::string vidurkisArMediana, std::list<Studentas> &rezultatai, int kiekStudentu,std::string failas);
void SkirtytiStudentus (std::string vidurkisArMediana, std::list<Studentas> &rezultatai, int kiekStudentu);
void vidurkisMediana (std::list<Studentas> &rezultatai, int kiekStudentu, std::string sukurtiFailus, std::string vidurkisArMediana);
void Skaitymas(std::list<Studentas> &rezultatai,int kiekStudentu,int nd, Studentas (*kazkoksIvedimas)(std::string, int,Studentas),std::string sukurtiFailus, std::string vidurkisArMediana);
void Ivedimas (std::string arZinoKiek,std::list<Studentas> &rezultatai, int kiekStudentu,std::string sukurtiFailus, std::string vidurkisArMediana);
void NuskaitytiIsFailo(std::list<Studentas> &rezultatai, std::string pav, std::string sukurtiFailus, int &ndsk, std::string vidurkisArMediana);
void KiekyraStudentu(std::string arZinoKiek,std::list<Studentas> &rezultatai,std::string sukurtiFailus, std::string vidurkisArMediana);
void duomenys(std::string arZinoKiek,std::list<Studentas> &rezultatai,std::string sukurtiFailus);
void generuotiFailus (int& n, std::list<Studentas> &rezultatai, int& ndSk, std::string pav);


#endif // V_1LIST_H_INCLUDED

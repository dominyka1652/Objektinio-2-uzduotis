#include "v.1list.h"

void ifFail ()
{
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
std::cout << "Ivesta neteisingai, bandykite is naujo: ";
}

bool SortByPavarde(Studentas& a, Studentas& b) { return a.pavarde < b.pavarde; }
bool SortByVid(Studentas a, Studentas b) { return a.galutinisVid < b.galutinisVid; }
bool SortByMed(Studentas a, Studentas b) { return a.galutinisMed < b.galutinisMed; }

Studentas generavimas (int input, Studentas b){
    using hrClock = std::chrono::high_resolution_clock;
     std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
      std:: cout << "Namu darbu pazymiai: ";
      std::uniform_int_distribution<int> dist(1, 10);
     for(int k=0; k<b.ndSkaicius; k++){
        input = dist(mt);
        std:: cout  << input << " ";
        b.namuDarbai.push_back(input);
     }
                b.egzaminas = dist(mt);
                std::cout << "\nEgzamino pazymys: " << b.egzaminas << "\n";
    return b;
}

///Funkcija iskvieciama, jei nezinomas namu darbu skaicius
///Funkcija tikrina, ar pazymiu ivedimas parasytas tinkamai ir pagal pasirinkima, ar sugeneruoja pazymius, arba leidzia juos ivesti
Studentas pazymiuIvedimas (std::string kaipIvestiPazymius, int i,Studentas b)
{ int input; //ivedamas arba generuojamas skaicius
      if (kaipIvestiPazymius == "sugeneruoti" || kaipIvestiPazymius == "Sugeneruoti")
        {     std::cout << "Kiek pazymiu norite sugeneruoti?: ";
              std::cin >> b.ndSkaicius;
            while ( b.ndSkaicius <=0 || std::cin.fail())   {ifFail();  std::cin >> b.ndSkaicius;}
             if ( b.ndSkaicius > 0)
             b = generavimas(input,b);}

        else if (kaipIvestiPazymius == "Ivesti" || kaipIvestiPazymius == "ivesti"){
        b.ndSkaicius = 1;
        std::cout << "Namu darbu pazymiai (ivedus paskutini pazymi turi but parasomas 0):" ;
        for(int k=0; k<b.ndSkaicius; k++){ //sk paaiskinimas 198 eilutej
            std::cin >> input;
           while (input <0 || input > 10 || std::cin.fail())
            {ifFail();  std::cin >> input;}
               if (input != 0)
               {b.namuDarbai.push_back(input);
            b.ndSkaicius++;}
            }
            b.ndSkaicius--;
        std::cout << "Egzamino pazimys ";
        std::cin >> b.egzaminas;
         while (b.egzaminas <= 0 || b.egzaminas > 10 || std::cin.fail())
            {ifFail(); std::cin >> b.egzaminas;}
    }
     else {     ifFail();
                std::cin >> kaipIvestiPazymius;
                pazymiuIvedimas (kaipIvestiPazymius, i, b);}
        return b;
}

///Funkcija iskvieciama, kai zinomas namu darbu skaicius
///Funkcija tikrina, ar pazymiu ivedimas parasytas tinkamai ir pagal pasirinkima, ar sugeneruoja pazymius, arba leidzia juos ivesti
Studentas pazymiuIvedimas2(std::string kaipIvestiPazymius,int i,Studentas b){
int input; //ivestas arba sugeneruotas skaicius
      if (kaipIvestiPazymius == "sugeneruoti" || kaipIvestiPazymius == "Sugeneruoti")
        b = generavimas(input,b);

    else if (kaipIvestiPazymius == "Ivesti" || kaipIvestiPazymius == "ivesti"){
        std::cout << "Namu darbu pazymiai: ";
        for(int k=0; k<b.ndSkaicius; k++){
            std::cin >> input;
            while (input <= 0 || input > 10 || std::cin.fail()){
                ifFail();
                std::cin >> input;}
            b.namuDarbai.push_back(input);
            }
        std::cout << "Egzamino pazymys ";
        std::cin >> b.egzaminas;

        while (b.egzaminas <= 0 || b.egzaminas > 10 || std::cin.fail())
            {   ifFail();
                std::cin >> b.egzaminas;}
    }

     else {     ifFail();
                std::cin >> kaipIvestiPazymius;
                pazymiuIvedimas2(kaipIvestiPazymius, i, b);}
    return b;
}

void Spausdinimas (std::string vidurkisArMediana, std::list<Studentas> &rezultatai, int kiekStudentu,std::string failas){
        rezultatai.sort(SortByPavarde);
        std::ofstream fr(failas);
        std::list<Studentas>::iterator it;
        fr << std::left << std::setw(20) << "Pavarde ";
        fr << std::left << std::setw(20) << "Vardas ";
        if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "Vidurki")fr << std::left << std::setw(15) << "Galutinis (Vid.)\n";
        else if (vidurkisArMediana == "Mediana" || vidurkisArMediana == "mediana")fr << std::left << std::setw(15) << "Galutinis (Med.)\n";
        for ( it = rezultatai.begin(); it!=rezultatai.end(); ++it){
        fr << std::left << std::setw(20) << it->pavarde;
        fr<< std::left << std::setw(20) << it->vardas;
        if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "Vidurki")fr<< std::left << std::setw(20) << std::setprecision(3) << it->galutinisVid;
        else if (vidurkisArMediana == "Mediana" || vidurkisArMediana == "mediana")fr<< std::left << std::setw(20) << std::setprecision(3) << it->galutinisMed;
        fr<< std::endl;}
        fr.close();
}

void SkirtytiStudentus (std::string vidurkisArMediana, std::list<Studentas> &rezultatai, int kiekStudentu)
{   int kiek1 = 0, kiek2 = 0;
std::list<Studentas>::iterator it;
std::list<Studentas>::iterator k;
        if (vidurkisArMediana == "vidurki") rezultatai.sort(SortByVid);
        else if (vidurkisArMediana == "mediana") rezultatai.sort(SortByMed);
    std::list<Studentas> tinginiai;
        auto start = std::chrono::high_resolution_clock::now();
         for (it = rezultatai.begin(); it!=--rezultatai.end(); it++){
                if (vidurkisArMediana == "vidurki") {
            if (it->galutinisVid < 5)   k = it;
        }
        else if (vidurkisArMediana == "mediana"){
            if (it->galutinisMed < 5) k = it;
                    }
        }
        for(it = rezultatai.begin(); it!=k; ++it)
        tinginiai.push_back(*it);
        rezultatai.erase(rezultatai.begin(),k);
        kiek2 = tinginiai.size();
        kiek1 = rezultatai.size();
        int kiek = kiek1 + kiek2;
        auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> diff = end-start; // Skirtumas (s)
        std::cout << std::to_string(kiek) + " elementu isskirtymas i dvi grupes uztruko: "<< diff.count() << " s\n";

        std::string saunuoliukai = "Saunuoliai" + std::to_string(kiek) + ".txt";
        std:: string tinginukai = "Tinginiai" + std::to_string(kiek) + ".txt";
        ///start = std::chrono::high_resolution_clock::now();
        Spausdinimas(vidurkisArMediana,rezultatai,kiek1,saunuoliukai);
        Spausdinimas(vidurkisArMediana,tinginiai,kiek2,tinginukai);
        std::cout << std::endl;
    rezultatai = {}; tinginiai = {};
}

///Funkcija apskaiciuoja visu pazymiu vidurki ir mediana bei juos isspausdina
void vidurkisMediana (std::list<Studentas> &rezultatai, int kiekStudentu, std::string sukurtiFailus, std::string vidurkisArMediana){
    double vid = 0; //vidurkis
    std::list<Studentas>::iterator it;
    std::list<int>::iterator z;
   if (sukurtiFailus== "nenoriu") {std::cout << "Norite gauti aritmetini vidurki (irasykite 'vidurki')\n ar mediana (irasykite 'mediana')?: ";
    std::cin >> vidurkisArMediana;}
    if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "mediana"){
        for (it = rezultatai.begin(); it !=rezultatai.end(); ++it)
        { double nd = 0;
           for ( z = it->namuDarbai.begin(); z!=it->namuDarbai.end(); ++z){
            nd += *z;
           }
           vid = ((nd/it->ndSkaicius * 0.4) + (it->egzaminas * 0.6));
             it->galutinisVid = vid;
            it->namuDarbai.sort();
              std::list<int>::iterator a = it->namuDarbai.begin();
            if (it->ndSkaicius%2==0)
                { int l = 0;
                  double med = 0; //mediana
                    l = (it->ndSkaicius - 2)/2; //pazymiu skaicius iki reikiamu skaitmenu
                    std::advance(a, (l-1));
                    med = std::round ((*a + ((*a+1)/2)) * 0.4 + (it->egzaminas*0.6));
                    it->galutinisMed = med;
                }
            else{
                int l = 0;
                double med = 0; //mediana
                l = it->ndSkaicius/2; //pazymiu skaicius iki reikiamu skaitmenu
                std::advance(a, (l-1));
                med = (*a * 0.4) + (it->egzaminas*0.6);
                it->galutinisMed = med;}

        }
         SkirtytiStudentus(vidurkisArMediana,rezultatai,kiekStudentu);
        rezultatai = {};
        }
    else {ifFail(); vidurkisMediana(rezultatai, kiekStudentu,sukurtiFailus,vidurkisArMediana);}

}

///I funkcija kreipiamasi jei yra nezinomas namu darbu skaicius ir ivedama, ar norima pazymius suvesti ranka, ar generuoti
void Skaitymas(std::list<Studentas> &rezultatai,int kiekStudentu,int nd, Studentas (*kazkoksIvedimas)(std::string, int,Studentas),std::string sukurtiFailus, std::string vidurkisArMediana){
   Studentas b,gal;
    std::string kaipIvestiPazymius; //ivedimo budas ranka arba generuojant
    for (int i = 0; i<kiekStudentu; i++)
    {   std::cout << "Pavarde ";
        std::cin >> b.pavarde;
        std::cout << "Vardas ";
        std::cin >> b.vardas;
        std::cout << "Ar norite pazymius irasyti ranka, ar atsitiktinai sugeneruoti?\n";
        std::cout << "Jei irasyti ranka, iveskite zodi 'ivesti'\n";
        std::cout << "Jei norite sugeneruoti atsitiktinai, iveskite zodi 'sugeneruoti': ";
        std::cin >> kaipIvestiPazymius;
        b.ndSkaicius = nd;
        gal = kazkoksIvedimas(kaipIvestiPazymius,i,b);
        rezultatai.push_back(gal);
        b = {}; gal = {};
    }
    vidurkisMediana (rezultatai,kiekStudentu,sukurtiFailus,vidurkisArMediana);
}

///Funkcijoje ivedama ar zinomas namu darbu skaicius ir tikrinama, ar ivestas atsakymas teisingas
///bei kreipiasi i kitas funkcijas ivykdzius salygas
void Ivedimas (std::string arZinoKiek,std::list<Studentas> &rezultatai, int kiekStudentu,std::string sukurtiFailus, std::string vidurkisArMediana){
     std::cin >> arZinoKiek; // ar yra zinomas namu darbu skaicius
     int nd;
    if (arZinoKiek == "Taip" || arZinoKiek == "taip")
        {   std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> nd;
            while (nd <= 0 || std::cin.fail())
            {  ifFail();
                std::cin >> nd;
                }
            if (nd >= 1){
                Skaitymas(rezultatai,kiekStudentu, nd,pazymiuIvedimas2,sukurtiFailus,vidurkisArMediana);}
        }
   else if (arZinoKiek == "Ne" || arZinoKiek == "ne" )
        {    Skaitymas(rezultatai,kiekStudentu,nd,pazymiuIvedimas,sukurtiFailus, vidurkisArMediana);}

    else {  nd = 0;
            std::cout << "Atsakymas negalimas, bandykite dar karta: ";
            Ivedimas(arZinoKiek,rezultatai,kiekStudentu,sukurtiFailus,vidurkisArMediana);}
}

void NuskaitytiIsFailo(std::list<Studentas> &rezultatai, std::string pav, std::string sukurtiFailus, int &ndsk, std::string vidurkisArMediana){
    int nd;
    Studentas a;
    int kiekStudentu = 0;
    std::string line;
    if (sukurtiFailus == "nenoriu" )
    {std::cout << "Kiek namu darbu yra faile?: ";
    std::cin>> ndsk;}
    while (ndsk <= 0 && std::cin.fail())
    {   ifFail();
        std::cin >> ndsk;}
     std::ifstream fd(pav);
           try
{
   if (!fd)
    throw std::runtime_error("Nepavyko atidaryti failo");
}
catch(std::exception& e)
{
    std::cout << e.what() << "\n";
    exit(0);
}
    auto start = std::chrono::high_resolution_clock::now();
         if (fd.is_open())
           { getline(fd, line);
               while(fd>>a.vardas){
                fd >> a.pavarde;
                 a.ndSkaicius = ndsk;
                    for (int i = 0; i< a.ndSkaicius; i++)
                    {   fd >> nd;
                        a.namuDarbai.push_back(nd);}
                fd >> a.egzaminas;
                rezultatai.push_back(a);
                a = {};
                kiekStudentu++;
                }
        }
            fd.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    if (sukurtiFailus == "nenoriu"){ std::cout <<"\n" << std::to_string(kiekStudentu) + " elementu nuskaitymas is failo uztruko: "<< diff.count() << " s\n";
        vidurkisMediana(rezultatai,kiekStudentu,sukurtiFailus, vidurkisArMediana);}
}

///Funkcija tikrina, ar studentu ivestas kiekis yra geras
void KiekyraStudentu(std::string arZinoKiek,std::list<Studentas> &rezultatai,std::string sukurtiFailus, std::string vidurkisArMediana){
    int kiekStudentu;
    std::cin >> kiekStudentu;
    if (kiekStudentu >= 1 && kiekStudentu <= 1000)
    {
        std::cout << "Ar zinote namu darbu skaiciu? Jei zinote, parasykite 'taip', kitu atveju rasykite 'ne' ";
    Ivedimas(arZinoKiek,rezultatai,kiekStudentu,sukurtiFailus,vidurkisArMediana);
    }
    else if (kiekStudentu <0 || kiekStudentu > 1000 || std::cin.fail() ) {
            ifFail();
            KiekyraStudentu(arZinoKiek,rezultatai,sukurtiFailus,vidurkisArMediana);
    }

}

void duomenys(std::string arZinoKiek,std::list<Studentas> &rezultatai,std::string sukurtiFailus){
    std::string duomenuIvedimas;
    std::cin >> duomenuIvedimas;
    std::string pav = "Studentai.txt";
    if (duomenuIvedimas == "nuskaityti"){
    std::string jo;
    std::cout << "Iveskite failo pavadinima: ";
    std::cin >> jo;
    pav = jo + ".txt";}
    std::string vidurkisArMediana;
    if (duomenuIvedimas == "ivesti" || duomenuIvedimas == "Ivesti") {
        std::cout << "Kiek yra studentu?: ";
           KiekyraStudentu(arZinoKiek,rezultatai,sukurtiFailus, vidurkisArMediana) ;}
    else if (duomenuIvedimas == "nuskaityti" || duomenuIvedimas == "Nuskaityti") {
            int ndsk; NuskaitytiIsFailo(rezultatai,pav,sukurtiFailus,ndsk, vidurkisArMediana);}
    else {  ifFail();
            duomenys (arZinoKiek,rezultatai,sukurtiFailus);}
}

void generuotiFailus (int& n, std::list<Studentas> &rezultatai, int& ndSk, std::string pav){
    Studentas a;
    int input;
     std::ofstream gen(pav);
    gen << std::left << std::setw(20) << "Vardas ";
    gen << std::left << std::setw(20) << "Pavarde ";
    for (int k = 1; k< ndSk + 1; k++){
        gen << std::left << std::setw(7)<< "ND" + std::to_string(k);
    }
    gen << std::left << std::setw(10) << "Egzaminas\n";
     using hrClock = std::chrono::high_resolution_clock;
        std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
        std::uniform_int_distribution<int> dist(1, 10);

    for (int i=1;i<n+1;i++)
        {a.ndSkaicius = ndSk;
        a.vardas = "Vardas" + std::to_string(i);
        a.pavarde = "Pavarde" + std::to_string(i);
        gen << std::left << std::setw(20) << a.vardas;
        gen <<  std::left << std::setw(21) << a.pavarde;
        for(int k=0; k<ndSk; k++){
        input = dist(mt);
        a.namuDarbai.push_back(input);
        gen <<  std::left << std::setw(7) << input;
        }
        a.egzaminas = dist(mt);
        rezultatai.push_back(a);
        gen <<  std::left << std::setw(10) << a.egzaminas << "\n";
        a = {};
        }
    gen.close();
    rezultatai = {};
}

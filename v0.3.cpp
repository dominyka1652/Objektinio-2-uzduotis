#include "v0.3.h"

void ifFail ()
{
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
std::cout << "Ivesta neteisingai, bandykite is naujo: ";
}

bool SortByPavarde(Studentas a, Studentas b) { return a.pavarde < b.pavarde; }

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

///Funkcija apskaiciuoja visu pazymiu vidurki ir mediana bei juos isspausdina
void vidurkisMediana (std::vector<Studentas> &rezultatai, int kiekStudentu){
    double vid = 0; //vidurkis
     int isviso = 0; //bendra pazymiu suma
     std:: string vidurkisArMediana;
    isviso = rezultatai[0].ndSkaicius + 1; //bendras visu pazymiu skaicius
    std::cout << "Norite gauti aritmetini vidurki (irasykite 'vidurki')\n ar mediana (irasykite 'mediana')?: ";
    std::cin >> vidurkisArMediana;
    if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "mediana"){
        for (int i = 0; i<kiekStudentu; i++)
        {  double nd = 0;
           for (int z=0; z<=rezultatai[0].ndSkaicius; z++){
            nd += rezultatai[i].namuDarbai[z];
            if (z+1==rezultatai[0].ndSkaicius){rezultatai[i].namuDarbai.push_back(rezultatai[i].egzaminas);}
           }
             vid = nd/isviso;
             rezultatai[i].galutinisVid = vid;
            std::sort(rezultatai[i].namuDarbai.begin(), rezultatai[i].namuDarbai.end());

            if (isviso%2==0)
                { int l = 0;
                  double med = 0; //mediana
                    l = (isviso - 2)/2; //pazymiu skaicius iki reikiamu skaitmenu
                    med = std::round (rezultatai[i].namuDarbai[l]+ rezultatai[i].namuDarbai[l+1])/2;
                    rezultatai[i].galutinisMed = med;
                }
            else{
                int l = 0;
                double med = 0; //mediana
                l = isviso/2; //pazymiu skaicius iki reikiamu skaitmenu
                med = rezultatai[i].namuDarbai[l];
                rezultatai[i].galutinisMed = med;}
        }
        if (kiekStudentu > 1);
        std::sort(rezultatai.begin(), rezultatai.end(), SortByPavarde);
        std::ofstream fr("Rezultatai.txt");
        fr << std::left << std::setw(20) << "Pavarde ";
        fr << std::left << std::setw(20) << "Vardas ";
        if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "Vidurki")fr << std::left << std::setw(20) << "Galutinis (Vid.)\n";
        else if (vidurkisArMediana == "Mediana" || vidurkisArMediana == "mediana")fr << std::left << std::setw(20) << "Galutinis (Med.)\n";
        fr << "-----------------------------------------------------\n";
        for (int i = 0; i<kiekStudentu; i++){
        fr << std::left << std::setw(20) << rezultatai[i].pavarde;
        fr<< std::left << std::setw(20) << rezultatai[i].vardas;
        if (vidurkisArMediana == "vidurki" || vidurkisArMediana == "Vidurki")fr<< std::left << std::setw(20) << std::setprecision(3) << rezultatai[i].galutinisVid;
        else if (vidurkisArMediana == "Mediana" || vidurkisArMediana == "mediana")fr<< std::left << std::setw(20) << std::setprecision(3) << rezultatai[i].galutinisMed;
        fr<< std::endl;}
        fr.close();
    }
    else {ifFail(); vidurkisMediana(rezultatai, kiekStudentu);}

}

///I funkcija kreipiamasi jei yra nezinomas namu darbu skaicius ir ivedama, ar norima pazymius suvesti ranka, ar generuoti
void Skaitymas(std::vector<Studentas> &rezultatai,int kiekStudentu,int nd, Studentas (*kazkoksIvedimas)(std::string, int,Studentas)){
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
    vidurkisMediana (rezultatai,kiekStudentu);
}

///Funkcijoje ivedama ar zinomas namu darbu skaicius ir tikrinama, ar ivestas atsakymas teisingas
///bei kreipiasi i kitas funkcijas ivykdzius salygas
void Ivedimas (std::string arZinoKiek,std::vector<Studentas> &rezultatai, int kiekStudentu){
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
                Skaitymas(rezultatai,kiekStudentu, nd,pazymiuIvedimas2);}
        }
   else if (arZinoKiek == "Ne" || arZinoKiek == "ne" )
        {    Skaitymas(rezultatai,kiekStudentu,nd,pazymiuIvedimas);}

    else {  nd = 0;
            std::cout << "Atsakymas negalimas, bandykite dar karta: ";
            Ivedimas(arZinoKiek,rezultatai,kiekStudentu);}
}

void NuskaitytiIsFailo(std::vector<Studentas> &rezultatai){
    int nd;
    Studentas a;
    int ndsk;
    int kiekStudentu = 0;
    std::string line;
    std::cout << "Kiek namu darbu yra faile?: ";
    std::cin>> ndsk;
    while (ndsk <= 0 && std::cin.fail())
    {   ifFail();
        std::cin >> ndsk;}
     std::ifstream fd("Studentai.txt");
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
    getline(fd, line);
        if (fd.is_open())
        {       while(! fd.eof()){
                a.ndSkaicius = ndsk;
                fd >> a.vardas >> a.pavarde;
                    for (int i = 0; i< a.ndSkaicius; i++)
                    {   fd >> nd;
                        a.namuDarbai.push_back(nd);
                        }
                fd >> a.egzaminas;

                rezultatai.push_back(a);
                a = {};
                kiekStudentu++;}
        }
            fd.close();
    vidurkisMediana (rezultatai, kiekStudentu);
}

///Funkcija tikrina, ar studentu ivestas kiekis yra geras
void KiekyraStudentu(std::string arZinoKiek, std::vector<Studentas> rezultatai){
    int kiekStudentu;
    std::cin >> kiekStudentu;
    if (kiekStudentu >= 1 && kiekStudentu <= 1000)
    {
        std:: cout << "Ar zinote namu darbu skaiciu? Jei zinote, parasykite 'taip', kitu atveju rasykite 'ne' ";
    Ivedimas(arZinoKiek,rezultatai,kiekStudentu);
    }
    else if (kiekStudentu <0 || kiekStudentu > 1000 || std::cin.fail() ) {
            ifFail();
            KiekyraStudentu(arZinoKiek,rezultatai);
    }

}

void duomenys(std::string arZinoKiek,std::vector<Studentas> rezultatai){
    std:: string duomenuIvedimas;
    std::cin >> duomenuIvedimas;
    if (duomenuIvedimas == "ivesti" || duomenuIvedimas == "Ivesti") {
        std:: cout << "Kiek yra studentu?: ";
           KiekyraStudentu(arZinoKiek,rezultatai) ;}
    else if (duomenuIvedimas == "nuskaityti" || duomenuIvedimas == "Nuskaityti") NuskaitytiIsFailo(rezultatai);
    else {  ifFail();
            duomenys (arZinoKiek,rezultatai);}
}

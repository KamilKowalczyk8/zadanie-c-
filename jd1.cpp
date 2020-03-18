#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
string napis;

class zamiana{
       ifstream plik1;
       ofstream plik2;

  public:
        zamiana();
        ~zamiana();
       
       
};

                   
bool palindrome(string s)
{
        int back = s.length()-1; //ostatnia litera s
        bool palindrome = true; //zak³adamy ¿e jest
        for (int i=0; i<s.length()/2 && palindrome; i++) //tylko do po³owy stringu
                if (s[i] != s[back--]) //back po podstawieniu zmniejszy siê o 1 z ostatniej na przedostatni¹ itd.
                        palindrome = false;
                       
        return palindrome;
}

zamiana::zamiana(){ //konstruktor otwiera pliki
    plik1.open("od.txt");
     plik2.open("do.txt");
     if(plik1.good())  //sprawdzenie czy plik istnieje
            while(!plik1.eof())  
                  {
                   getline(plik1,napis);  //pobranie linii do zmiennej napis
                   string s(napis), slowo, polacz("");
                    stringstream ss(s);
                    while(ss >> slowo) 
                    polacz += slowo;
                   if(palindrome(napis)==1)
                    { 
                    cout<<"["<<endl<<"{"<<endl<<"string"<<":"<<napis<<endl<<""<<"palindrom"<<":tak"<<endl<<"}"<<""<<endl;
                    plik2<<"["<<endl<<"{"<<endl<<"string"<<":"<<napis<<endl<<""<<"palindrom"<<":tak"<<endl<<"}"<<""<<endl;
                    }
                    else
                    {
                    cout<<"["<<endl<<"{"<<endl<<"string"<<":"<<napis<<endl<<""<<"palindrom"<<":nie"<<endl<<"}"<<""<<endl;
                    plik2<<"["<<endl<<"{"<<endl<<"string"<<":"<<napis<<endl<<""<<"palindrom"<<":nie"<<endl<<"}"<<""<<endl;
                    }
                   }
   
}

zamiana::~zamiana(){ 
    plik1.close();
    plik2.close();
}

int main() {
zamiana pali;
    return 0;
} //tu uruchamia siê niejawnie destruktor

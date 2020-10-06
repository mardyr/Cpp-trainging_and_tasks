#include "main.h"
using namespace std;

// pu³apki wskaŸników

static unsigned LIMIT = 65000;

class A {
public:
   string name = "";
   double data;
   A() {
      int rng = rand()%10+1;
      for (int i=1; i<=rng; i++)
         name += (char)(rand()%26+65);
      data = rand()%1001 / 10.0;
   }
};

void show(vector <A*> coll,unsigned ix) { // kontener wskaznikow na typ A
      cout << "Adres dla indeksu " << ix << "=" << coll[ix] << endl; // przyk³adowy adres
      if (coll[ix]==nullptr) throw string("WYJ¥TEK: wskaŸnik nie wskazuje obiektu A, nie zostanie wyœwietlony name i data\n\n");
      cout << "A->name = " << coll[ix]->name << ", A->data = " << coll[1500]->data << endl;
}

void getMyMem() {
   PROCESS_MEMORY_COUNTERS_EX pmc;
   GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));  // uwaga! + linker psapi
   cout << "PeakWorkingSetSize (kB)" << (double)(pmc.PeakWorkingSetSize)/1024 << endl;
   cout << "WorkingSetSize (kB)" << (double)(pmc.WorkingSetSize/1024) << endl;
   cout << "PrivateUsage (kB)" << (double)(pmc.PrivateUsage/1024) << endl;
}

int main()
{
   srand(time(NULL));
   setlocale(LC_ALL, "");

   getMyMem();

   cout << "\n --- tworzê " << LIMIT << " obiektów A ---\n\n";

   vector <A*> collection; // tworzymy kontener (vector) collection przechowuj¹cy wskazniki na obiekty typu A(adresy )
   for (unsigned i=1; i<=LIMIT; i++) {
      collection.push_back(new A()); // zerezwuje pamiec na obiekt typu A(wywoluje konstruktor), jakby przypisuje tym wskazujesz na to  , dodaje adres na utworzony obiekt , idzie na koniec kontenera
   }

   show(collection,1500);

   getMyMem();

   string temp;
   getline(cin,temp);

   cout << "\n *** zwalniam pamiêæ z obiektami *** \n\n";
   for (auto a=collection.begin(); a!=collection.end(); a++)
      delete *a;

   cout << "\n !!! zerujê wskaŸniki w collection !!! \n\n";
   for (auto a=collection.begin(); a!=collection.end(); a++)
      *a = nullptr;

   try {
      show(collection,1500);
      show(collection,1501); // to siê nie wykona, linia wczeœniej wyrzuci wyj¹tek
   }
   catch(string e) { // gdy blok 'try' wykryje wyj¹tek, dopasuje do jego typu i obs³u¿y kodem
      cout << e;
   }
   catch(...) {
      cout << " ";
   }

   // w tym miejscu jesteœmy pozbawieni dostêpu do obiektów A. Nie mamy wskaŸników, a obiekty wci¹¿ zajmuj¹ pamiêæ.
   getMyMem();






   getline(cin,temp);
   return 0;
}

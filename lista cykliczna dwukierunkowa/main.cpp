#include <iostream>
#include <ctime>
using namespace std;
/**
	STRUKTURY DANYCH:
		LISTA DWUKIERUNKOWA CYKLICZNA - pierwszy i ostatni element wskazuj� na siebie - w efekcie nie ma pierwszego ani ostatniego ...
		Do problemu mo�na podej�� na wiele sposob�w. W li�cie cyklicznej dalej mo�emy numerowa� elementy, jednak wtedy utworzenie cyklu
		nie ma praktycznego znaczenia, bo traktuj� j� i tak, jakby by�a zwyk�� list�.
		Mo�na do problemu podej�� inaczej i szuka� element�w przez wzgl�d na WARTO�CI przechowywane a nie na pozycj�. I taki przyk�ad podej�cia
		do listy dwukierunkowej cyklicznej zastosuj� w tej implementacji. Zmieni to zatem ca�kowicie koncepcj� obs�ugi tej struktury
		w stosunku do wcze�niejszych implementacji. I dobrze!

		Uwaga! Spr�buj zoptymalizowa� poni�szy kod, kiedy ju� w pe�ni go przeanalizujesz.

		Uwaga!!!!! Kod �r�d�owy mo�e wydawa� si� zawi�y i skomplikowany, jednak mo�na rozrysowa� sobie na kartce to, w jaki spos�b
		elementy si� dodaj�/usuwaj� - jak przesuwane sa wska�niki na left i right. To pozwoli zrozumie� kolejne metody.

		Zadanie: spr�buj przerobi� ca�y program i zamiast warto�ci int data, przechowywa� jaka� struktur� (struct) czy klas�, kt�ra zawiera kilka p�l.
		Przyk�adowo, zamiast typu int data, przekazuj i tw�rz takie warto�ci
		class Element {
			class Data;
			Element* left=NULL;
			Element* right=NULL;
		};
		gdzie klasa data mo�e np. wygl�da� nast�puj�co
		class Data {
			string name;
			int value;
			bool config;
		};
*/

class Element {
public:
	int data=0;
	Element* left=NULL; // w lewo
	Element* right=NULL; // w prawo
	Element(int d){ data = d; left=right=this; }  // ! wowow Element wskazuje sam na siebie! (uwaga! to trzeba kontrolowa� ;))
};
class ListTwoCyclic {
public:
	Element* link=NULL; // wska�nik dowolnego elementu (wystarczy �e mam jeden, dzi�ki cykliczno�ci mog� porusza� si� w dowoln� stron� listy)
	unsigned long long int size = 0;
	// przesuwa si� na element d, szuka id�c w lewo/prawo : nowy link to ten element
	bool moveTo(int d,bool left=true) {
		for (int i=1; i<=size; i++) {
			if (link->data == d) return true;
			else if (left) link=link->left;
			else link=link->right;
		}
		cout << "Brak elementu o warto�ci " << d << endl;
		return false; // Niem a takiego elementu
	}
	// DODAJ element na lewo/prawo od link
	void add(int d,bool left = true) {
		Element* n = new Element(d);
		cout << "add(" << d << ")\n";
		if (size==0) {
			link = n;
		} else {
			Element* l = link->left;
			Element* r = link->right;
			if (left) { // na lewo od link
				link->left =n;
				n->right = link;
				n->left = l;
				l->right = n;
				if (size==1) link->right = n;

			}
			else { // na prawo od link
				link->right = n;
				n->left = link;
				n->right = r;
				r->left = n;
				if (size==1) link->left = n;
			}
		}
		size++;
	}
	// remove link
	bool rmv() {
		if (size==0) return false;
		if (size==1) {
			delete link;
			link=NULL;
		} else {
			Element* temp = link;
			link = link->left; // nowy link
			link->right = temp->right;
			link->right->left = link;
			delete temp;
		}
		size--;
		return true;
	}
	// remove d (id� w lewo lub w prawo od obecnego link
	bool rmv(int d,bool left = true) {
		if (moveTo(d,left)) { // tylko o ile znajd� tak� warto��
			cout << "rmv(" << d << ")" << endl;
			rmv();
		}
	}

	void show(bool left=true) {
		 // if (link) cout <<  link->left << "<-[" << link->data <<":"<<link<< "]->" << link->right << endl; //
		if (link) cout <<  "L=" << link->data  << ":   ";
		Element* temp = link;
		if (size)
		for (unsigned long long int i=1; i<=size*2; i++) {
			if (left) {
				cout << temp->data << "<";
				temp = temp->left;
				if (i==size) cout << ":<";
			} else {
				cout << temp->data << ">";
				temp = temp->right;
				if (i==size) cout << ":>";
			}
		}
		cout << "\t[" << size << "]\n";
	}
	bool removeALL()
    {
        while(size>0)
        {
            rmv();
        }

    }

};

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));

	ListTwoCyclic* ltc = new ListTwoCyclic();
	ltc->show();

	ltc->add(10);
	ltc->show();
	ltc->show(false);

	ltc->add(20);
	ltc->show();
	ltc->show(false);

	ltc->moveTo(20);
	ltc->add(30);
	ltc->show();
	ltc->show(false);

	ltc->add(40,false);
	ltc->show(); // id� w lewo
	ltc->show(false);  // id� w prawo

	// taka sama warto�� x2, raz po lewej raz po prawej od link
	ltc->add(40,false);
	ltc->add(40,true);
	ltc->show();  // id� w prawo
	ltc->show(false);  // id� w prawo

	ltc->rmv();  // usuwam dotychczasowy link (20)
	ltc->show();  // id� w prawo
	ltc->show(false);  // id� w prawo

	ltc->rmv(40,false);  // usuwam dotychczasowy link szukam na prawo
	ltc->show();  // id� w prawo
	ltc->show(false);  // id� w prawo

	ltc->rmv(40);  // usuwam dotychczasowy link szukam na lewo
	ltc->show();  // id� w prawo
	ltc->show(false);  // id� w prawo

	ltc->rmv(10);
	ltc->show(false);


    cout<<"Usuwam wszystkie"<< endl;
     ltc->removeALL();
	//ltc->rmv(50);
	//ltc->rmv();
	//ltc->rmv();
	//ltc->rmv(); // ju� za du�o usuwam
	//ltc->show();

	/// zaprojektuj metod� czyszcz�c� WSZYSTKIE elementy listy



	return 0;
}

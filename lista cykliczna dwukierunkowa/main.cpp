#include <iostream>
#include <ctime>
using namespace std;
/**
	STRUKTURY DANYCH:
		LISTA DWUKIERUNKOWA CYKLICZNA - pierwszy i ostatni element wskazuj¹ na siebie - w efekcie nie ma pierwszego ani ostatniego ...
		Do problemu mo¿na podejœæ na wiele sposobów. W liœcie cyklicznej dalej mo¿emy numerowaæ elementy, jednak wtedy utworzenie cyklu
		nie ma praktycznego znaczenia, bo traktujê j¹ i tak, jakby by³a zwyk³¹ list¹.
		Mo¿na do problemu podejœæ inaczej i szukaæ elementów przez wzgl¹d na WARTOŒCI przechowywane a nie na pozycjê. I taki przyk³ad podejœcia
		do listy dwukierunkowej cyklicznej zastosujê w tej implementacji. Zmieni to zatem ca³kowicie koncepcjê obs³ugi tej struktury
		w stosunku do wczeœniejszych implementacji. I dobrze!

		Uwaga! Spróbuj zoptymalizowaæ poni¿szy kod, kiedy ju¿ w pe³ni go przeanalizujesz.

		Uwaga!!!!! Kod Ÿród³owy mo¿e wydawaæ siê zawi³y i skomplikowany, jednak mo¿na rozrysowaæ sobie na kartce to, w jaki sposób
		elementy siê dodaj¹/usuwaj¹ - jak przesuwane sa wskaŸniki na left i right. To pozwoli zrozumieæ kolejne metody.

		Zadanie: spróbuj przerobiæ ca³y program i zamiast wartoœci int data, przechowywaæ jakaœ strukturê (struct) czy klasê, która zawiera kilka pól.
		Przyk³adowo, zamiast typu int data, przekazuj i twórz takie wartoœci
		class Element {
			class Data;
			Element* left=NULL;
			Element* right=NULL;
		};
		gdzie klasa data mo¿e np. wygl¹daæ nastêpuj¹co
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
	Element(int d){ data = d; left=right=this; }  // ! wowow Element wskazuje sam na siebie! (uwaga! to trzeba kontrolowaæ ;))
};
class ListTwoCyclic {
public:
	Element* link=NULL; // wskaŸnik dowolnego elementu (wystarczy ¿e mam jeden, dziêki cyklicznoœci mogê poruszaæ siê w dowoln¹ stronê listy)
	unsigned long long int size = 0;
	// przesuwa siê na element d, szuka id¹c w lewo/prawo : nowy link to ten element
	bool moveTo(int d,bool left=true) {
		for (int i=1; i<=size; i++) {
			if (link->data == d) return true;
			else if (left) link=link->left;
			else link=link->right;
		}
		cout << "Brak elementu o wartoœci " << d << endl;
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
	// remove d (idŸ w lewo lub w prawo od obecnego link
	bool rmv(int d,bool left = true) {
		if (moveTo(d,left)) { // tylko o ile znajdê tak¹ wartoœæ
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
	ltc->show(); // idŸ w lewo
	ltc->show(false);  // idŸ w prawo

	// taka sama wartoœæ x2, raz po lewej raz po prawej od link
	ltc->add(40,false);
	ltc->add(40,true);
	ltc->show();  // idŸ w prawo
	ltc->show(false);  // idŸ w prawo

	ltc->rmv();  // usuwam dotychczasowy link (20)
	ltc->show();  // idŸ w prawo
	ltc->show(false);  // idŸ w prawo

	ltc->rmv(40,false);  // usuwam dotychczasowy link szukam na prawo
	ltc->show();  // idŸ w prawo
	ltc->show(false);  // idŸ w prawo

	ltc->rmv(40);  // usuwam dotychczasowy link szukam na lewo
	ltc->show();  // idŸ w prawo
	ltc->show(false);  // idŸ w prawo

	ltc->rmv(10);
	ltc->show(false);


    cout<<"Usuwam wszystkie"<< endl;
     ltc->removeALL();
	//ltc->rmv(50);
	//ltc->rmv();
	//ltc->rmv();
	//ltc->rmv(); // ju¿ za du¿o usuwam
	//ltc->show();

	/// zaprojektuj metodê czyszcz¹c¹ WSZYSTKIE elementy listy



	return 0;
}

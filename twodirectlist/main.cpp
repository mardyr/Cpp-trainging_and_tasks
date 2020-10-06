#include "main.hpp"

/**
	STRUKTURY DANYCH:
		LISTA DWUKIERUNKOWA - od jednokierunkowej ta implementacja ró¿ni siê dodatkowym polem powi¹zañ elementów.
		Nie tylko wskazuje nastêpnego na liœcie, ale te¿ wczeœniejszego.
		Uwaga! Spróbuj zoptymalizowaæ poni¿szy kod, kiedy ju¿ w pe³ni go przeanalizujesz.
*/

class Element {
public:
	int data=0;
	Element* next=NULL; // nastêpny
	Element* prev=NULL; // poprzedni
	Element(int d){ this->data = d; this->next = this->prev = NULL; } // konstruktor
};
class ListTwo {
public:
	Element* first=NULL; // wskaŸnik pierwszego elementu listy
	Element* last=NULL;	// i ostatniego elentu na liœcie
	unsigned long long int size = 0; // tym razem bêdê pamiêta³ iloœæ elementów na liœcie

	Element* getPosition(unsigned long long int pos) {
		if (pos < 1 || pos > size ) return NULL; // size === this->size :)
		if (pos > size - pos) { // od ty³u
			Element* temp = this->last;
			unsigned long long int i = size;
			while (i-- > pos) {
				temp = temp->prev;
			}
			return temp;
		} else { // od przodu
			Element* temp = first;
			unsigned long long int i = 1;
			while (i++ < pos) {
				temp = temp->next;
			}
			return temp;
		}
	}

	void add(int d, unsigned long long int pos) {
		Element* n = new Element(d);
		if (size==0) { first = last = n; } // nie ma ani jednego dodajê bez wzglêdu na pos
		else if (pos <= 1) {  // na pocz¹tek
			first->prev = n;
			n->next = first;
			first=n;
		}
		else if (pos>size) { // na koniec
			last->next = n;
			n->prev = last;
			last = n;
		}
		else { // w œrodek
			Element* temp = getPosition(pos);
			Element* before = temp->prev;
			before->next = n;
			n->prev = before;
			temp->prev = n;
			n->next = temp;
		}
		size++;
		cout << "Dodajê element " << d << " na pozycjê " << pos << endl;
	}

	void show() {
		Element* temp = first;
		unsigned long long int i=0;
		while (temp!=NULL) {
				i++;
			cout << "<->"<<i<< "." << temp->data << ",\n" ;
			temp = temp->next;
		}
		cout << "NULL " << "[" << size << "] ";
		if (first!=NULL) cout << "P=" << first->data << " O=" << last->data << "\n\n";
		else cout << "P=NULL O=NULL\n\n";
	}
	// teraz je¿eli pos < size lub > size usuwam pierwszy lub ostatni
	bool rmv(unsigned long long int pos) {
		if (size==0) return true; // nie ma co usuwaæ
		else if (size==1) { // usuwam jeden, pos nie ma znaczenia
			delete first;
			first = last = NULL;
		}
		else if (pos <=1 ) { // usuwam pierwszy
			Element* temp = first;
			first = first->next;
			first->prev = NULL;
			delete temp;
		} else if (pos >= size) { // ostatni
			Element* temp = last;
			last->prev->next = NULL;
			last = last->prev;
			delete temp;
		} else { // w œrodku
			Element* temp = getPosition(pos);
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		size--;
		cout << "Usuwam element z pozycji " << pos << endl;
		return true;
	}
	// :)
	void rmvAll() {
		while (size>0) rmv(size);
	}
};


int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));


	ListTwo* myList = new ListTwo();
	myList->show(); // NULL

	myList->add(10,10); // pierwszy element, pozycja nie ma znaczenia, doda siê
	myList->show();

	myList->add(20,0);  // ok na pocz¹tek
	myList->add(30,1);  // ok na pocz¹tek
	myList->add(40,1);  // ok na pocz¹tek
	myList->show();

	myList->add(50,4);  // ok w miejsce ostatniego
	myList->add(60,myList->size+1);  // ok i tak na koniec
	myList->show();

	myList->rmv(2); // ze œrodka
	myList->show();
	myList->rmv(1); // pierwszy
	myList->show();
	myList->rmv(myList->size); // ostatni
	myList->show();

	// usuwam resztê
	myList->rmvAll();
	myList->show();

	/*  // sprawdŸ sobie czy dobrze zwalnia pamiêæ - tylko usuñ polecenie COUT z metody add i rmv :-D
	char z;
	for (unsigned long long int i = 1; i<=5000000; i++) myList->add(i,1); // ~120mb
	cin >> z;
	for (unsigned long long int i = 1; i<=2000000; i++) myList->rmv(1); // ~80mb
	cin >> z;
	*/

	return 0;
}

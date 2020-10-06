#include "main.hpp"

/**
	STRUKTURY DANYCH:
		DRZEWO BINARNE: to specjalna konstrukcja, w której ka¿dy ELEMENT struktury danych mo¿e mieæ 2 potomków. Istnieje zatem
		tylko jeden element najstarszy w hierarchii.
		Przyjmiemy, ¿e element mo¿na dodawaæ tylko na "nieobsadzonych" potomkach drzewa (wartoœæ zero|one to NULL).
		Usuniêcie jakiegoœ elementu usuwa wszystkich jego potomków (i ich potomków).

*/
stringstream view[6]; // 5 poziomów wyœwietlania (+1 na zapas do wyœwietlania NULLów dla 6 poziomu)
	// Binary Tree Element
class BTElement {
public:
	int data=0;
	BTElement* parent=NULL; // rodzic - element niekonieczny, ale u³atwia obs³ugê
	BTElement* zero=NULL; // lewy (0)
	BTElement* one=NULL; // prawy (1)

	BTElement(int d){ data = d; }

	// dodawanie za pomoc¹ œcie¿ki gdzie kolejna liczba binarna oznacza "zejœcie" do przodka, przy czym 0-lewo, 1-prawo
	// pozwalam obsadziæ tylko do 4 poziomu
    bool add(int d,string path,unsigned index=0) {
    	if (path.size() > 4 || path.size() == 0 || index >= path.size() ) { return true; }
		char znak = path[index]; // sterowanie dodawaniem "010" -> napierw indeks 0 , pozniej 1 i 2
		if (znak=='0') { // idê w lewo
			if (zero!=NULL && index == path.size()-1) return false; // ju¿ nie da siê dodaæ (5 poziom zatkany)
			if (zero==NULL) {
				BTElement* n = new BTElement(d);
				n->parent = this; // ten ktory wywolalem wczesniej rekurencyjnie jest rodzicem
				zero = n;
				return true;
			} else {
				return zero->add(d,path,index+1);
			}
		} else { // idê w prawo
			if (one!=NULL && index == path.size()-1) return false; // ju¿ nie da siê dodaæ (5 poziom zatkany)
			if (one==NULL) {
				BTElement* n = new BTElement(d);
				n->parent = this;
				one = n;
				return true;
			} else {
				return one->add(d,path,index+1);
			}
		}
    }
    // pokazywanie (rysowanie) umowne [nie graficzne przecie¿]
    void show(unsigned level=0) {
    	int sw = 3;
    	if (level==0) for (unsigned int ix=0; ix<5; ix++) { view[ix].str(""); }
    	view[level] << setw(sw) << right << data;
    	if (zero==NULL) { view[level+1] << setw(sw) << right << "-"; }
    	else zero->show(level+1);
    	if (one==NULL) { view[level+1] << setw(sw) << right << "-"; }
    	else one->show(level+1);
    	view[level] << setw(70/((level+1)*4)) << "";
    	if (level==0) {
			for (unsigned i=0;i<6;i++) {
				cout << view[i].str() << endl;
			}
			cout << "==================================\n\n";
    	}
    }
    // Przesuwam siê na element podany œcie¿k¹ binarn¹
    BTElement* moveTo(string path) {
    	BTElement* temp = this;
    	for (int i=0; i < path.size() ; i++) {
    		if (temp==NULL) break; // bo nie moge sie przemieszczac obiektem bo jest pusty
			if (path[i]=='0') {
				temp=temp->zero;
			} else {
				temp=temp->one;
			}
    	}
    	return temp;
    }
    // kasuje element potomny
    bool del() {
    	BTElement* temp = this;
    	if (!temp) return false;
    	if (temp->parent->zero == temp) temp->parent->zero = NULL; // rodzicowi wstawiam NULL
    	else temp->parent->one = NULL; // rodzicowi wstawiam NULL

		if (temp->zero) temp->zero->del();
		if (temp->one) temp->one->del();
		delete temp;
    }
    void showRelatives(string path)
    {

        int level = path.size +1 ;
        for(int=path.size()-1;i=0;i--)
        {
            if(path>4 || path==0 ) break;
            char znak = path[i];
            if(znak=='0')
            {
                BTElement*temp = parent ; // mam pozycje teraz tego elementu
                temp->zero = this;
                this = temp;
                cout<<data<<endl;
                delete temp;
            }
            else
            {
                BTElement*temp = parent;
                temp->one = this;
                this = temp;
                cout << data<<endl;
                delete temp;

            }
        }


    }
};

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));

	BTElement* ROOT = new BTElement(1);
	// LEVEL 1
	ROOT->add(20,"0");
	ROOT->add(21,"1");
	// LEVEL 2
	ROOT->add(31,"00");
	ROOT->add(32,"01");
	ROOT->add(33,"10");
	ROOT->add(34,"11");
	// LEVEL 3
	ROOT->add(41,"001");
	ROOT->add(42,"101");
	ROOT->add(43,"110");
	// LEVEL 4
	ROOT->add(51,"0010");
	ROOT->add(52,"0011");
	ROOT->add(53,"1100");
	ROOT->add(54,"1101");

	ROOT->show();

	ROOT->moveTo("110")->del();

	ROOT->show();

	delete ROOT;

	/// ZADANIE !
	// Dla elementu pobranego metoda moveTo stwórz metodê wyœwietlaj¹c¹ wszystkich jego przodków (a¿ do ROOT'a)


	return 0;
}

using namespace std;
Human::Human() {}
Human::Human(string n, string l, unsigned y) {
   name  = n; lastname = l; year = y; // this->  jest domy�lne, gdy mam doczynienia ze zmienn� kt�rej nigdzie nie deklarowa�em
}
void Human::show() {
   cout << name << " " << lastname << " born in " << year << "\n";
   cout << "*===========================*\n";

}

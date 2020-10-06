using namespace std;
Human::Human() {}
Human::Human(string n, string l, unsigned y) {
   name  = n; lastname = l; year = y; // this->  jest domyœlne, gdy mam doczynienia ze zmienn¹ której nigdzie nie deklarowa³em
}
void Human::show() {
   cout << name << " " << lastname << " born in " << year << "\n";
   cout << "*===========================*\n";

}

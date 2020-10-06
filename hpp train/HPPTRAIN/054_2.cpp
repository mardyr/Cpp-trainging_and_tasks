#include "main.h"
unsigned int r() {
	cout << "Wylosowano = ";
	return (unsigned int) (rand()%25000)%(rand()%99 + 2);
}

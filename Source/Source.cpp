#include <iostream>
#include "Game.h"

using namespace std;

int main() {
	Game g = Game();
	cout << g.retrieve() << endl;
	g.increment();
	cout << g.retrieve() << endl;
}
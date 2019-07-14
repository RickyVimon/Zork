// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Universal.h"

using namespace std;

int main()
{
	try {

		bool game_completed = 0;
		bool char_created = 0;

		World my_world;

		while (!game_completed)
		{
			my_world.UserInput();
			break;
		}
		return 0;
	}
	catch (exception const & e) {
		cout << "error exception";
		main();
		return 0;
	}
	
}
void CharacterCreation() {
	
}

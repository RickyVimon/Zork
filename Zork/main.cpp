// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "World.h"
#include <iostream>
#include <string>
#include <vector>
<<<<<<< Updated upstream
=======
#include <conio.h>
#include "Universal.h"
>>>>>>> Stashed changes

using namespace std;

int main()
{
	try {

		bool game_completed = 0;

		World my_world;
		
		cout << "Welcome to this version of Zork! \n";
		throw exception("error");

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

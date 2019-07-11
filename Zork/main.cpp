// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include"World.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	try {
		char key;
		string input_text;
		vector<string> command;
		bool game_completed = 0;

		World my_world;
		
		cout << "Welcome to this version of Zork! \n";
		throw exception("error");

		while (!game_completed) {
			cout << "a currar";
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

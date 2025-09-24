#include <iostream>
#include <random>
#include <ctime>
#include <string>

//Header files
#include "Encrypter.hpp"

int main() {
	//Seed random
	srand(time(0));

	//Variables
	std::string input;
	Encrypter encrypt;

	//Generate Key
	encrypt.keygen();

	return 0;
}

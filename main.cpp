#include <iostream>
#include <string>

//Header files
#include "Encrypter.hpp"

int main() {
	//Variables
	std::string input;
	Encrypter encrypt;

	//Generate Key
	encrypt.keygen();

	return 0;
}

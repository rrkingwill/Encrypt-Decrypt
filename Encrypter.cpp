#include "Encrypter.hpp"

//Default Constructor
Encrypter::Encrypter() 
: keySize(128), key("") 
{

}

//Conversion Constructor
Encrypter::Encrypter(std::string k) 
: keySize(128), key(std::move(k)) 
{

}

//Destructor
Encrypter::~Encrypter() {

}

//Random key generator
std::string Encrypter::keygen() {
    for(auto i = 0; i < keySize; i++) {
        key += rand() % 95 + 32;
    }

    std::cout << key << std::endl;
    return key;
}

//Encrypts message using key
std::string Encrypter::encrypt(std::string k, std::string m) {

}
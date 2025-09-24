#ifndef ENCRYPTER_HPP
#define ENCRYPTER_HPP

#include <iostream>
#include <string>

class Encrypter {
public:
    //Constructors
    Encrypter();
    Encrypter(std::string key);
    virtual ~Encrypter();


    //----------Members----------//
    //Generates random key
    std::string keygen();
    std::string encrypt(std::string, std::string);

    
private:
    short keySize;
    std::string key;

};

#endif

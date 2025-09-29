#ifndef ENCRYPTER_HPP
#define ENCRYPTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <ctime>
#include <algorithm>


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
    std::string decrypt(std::string, std::string);
    unsigned long sMod(std::string, unsigned long);
    std::string toNumStr(std::string);
    
private:
    int keySize;
    std::string key;

};

#endif

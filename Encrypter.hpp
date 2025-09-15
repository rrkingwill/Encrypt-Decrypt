#ifndef ENCRYPTER_HPP
#define ENCRYPTER_HPP

#include <string>

class Encrypter {
public:
    //Constructors
    Encrypter();
    Encrypter(std::string key);
    virtual Encrypter~();
    Encrypter(const Encrypter &other);

    //Members
    std::string keyGen();
    
private:
    std::string key;

};

#endif

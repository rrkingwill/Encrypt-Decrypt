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
        key += rand() % 256;
    }

    // std::cout << key << std::endl;
    // std::cout << std::endl << std::endl;
    //  for(auto i = 0; i < keySize; i++) {
    //      std::cout << static_cast<int>(key[i]) << " ";
    //  }
    // std::cout << std::endl << std::endl;

    // std::cout <<  << std::endl;
    
    //Print hex representation of string
    for(auto i = 0; i < keySize; i++) {
        printf("%d ", static_cast<unsigned char>(key[i]));
    }
    std::cout << std::endl << std::endl;

    encrypt(key, "");

    return key;
}

//Encrypts message using key
std::string Encrypter::encrypt(std::string k, std::string m) {
    //Ouput Message (testing)
    //std::cout << "Message: " << m << std::endl;


    //Convert key to string of base10 numbers so it is easier to work with
    k = toNumStr(k);
    //Split the key into 2 keys
    std::string k1 = k.substr(0, keySize/2);
    std::string k2 = k.substr(keySize/2, keySize);

    //Mod k1 with large prime number to get seed for Fisher-Yates
    int seed = sMod(k1, 120715241);

    std::cout << std::endl << std::endl << seed << std::endl;

    // //Fisher-Yates seeded shuffle
    // for(auto i = keySize-1; i > 0; i--) {


    // }
    
    return m;
}

unsigned long Encrypter::sMod(std::string slhs, unsigned long rhs) {
    std::string sub = "";
    unsigned long res = 0;

    //Convert key to string of base10 numbers so it is easier to work with
    for(auto i = 0; i < sub.length(); i+=sub.length()) {
        sub += slhs.substr(i, i + (9 - sub.length()));
        res = std::stoul(sub) % rhs;
        
    }

    rhs = rhs;

    return res;
}

std::string Encrypter::toNumStr(std::string s) {
    std::string temp;
    for(auto i = 0; i < s.length(); i++) {
        std::stringstream ss;
        ss << static_cast<int>((unsigned char)s[i]);
        temp += ss.str();
    }
    return temp;
}

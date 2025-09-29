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
    //Seed random
    srand(time(0));

    for(auto i = 0; i < keySize; i++) {
        key += rand() % 93 + 33;
    }
    
    //Print hex representation of string
    for(auto i = 0; i < keySize; i++) {
        printf("%c", static_cast<unsigned char>(key[i]));
    }
    std::cout << std::endl << std::endl;

    std::string cipher;
    cipher = encrypt(key, "This is a test to see if the shuffle works.");
    
    decrypt(key, cipher);

    return key;
}

//Encrypts message using key
std::string Encrypter::encrypt(std::string k, std::string m) {
    //Cipher initialized as the message
    std::string c = m;
    //Split the key into 2 keys
    std::string k1 = k.substr(0, keySize/2);
    std::string k2 = k.substr(keySize/2, keySize);

    //Ouput Message (testing)
    std::cout << "Message: " << m << std::endl;

    //Convert k1 to a string of base10 numbers to make it easier to work with
    k1 = toNumStr(k1);

    //------Shuffle message-----//
    //Seed random with k1 % prime number for the shuffle
    srand(sMod(k1, 120715241));

    //Fisher-Yates seeded shuffle based on k1 % prime number
    for(auto i = m.length()-1; i > 0; i--) {
        //Random index to swap with
        int i2 = rand() % (m.length()+1);

        //Swap i and i2
        std::swap(c[i], c[i2]);
    }
    
    

    
    std::cout << std::endl << c << std::endl;
    return c;
}

std::string Encrypter::decrypt(std::string k, std::string c) {
    std::vector<int> iVec(c.length()-1);
    //Split the key into 2 keys
    std::string k1 = k.substr(0, keySize/2);
    std::string k2 = k.substr(keySize/2, keySize);
    //Convert k1 to strings of base10 numbers to make it easier to work with
    k1 = toNumStr(k1);

    //Seed random to unshuffle based on same seed from encryption shuffle
    srand(sMod(k1, 120715241));

    //Fill iVec with indexes to swap in reverse order
    for(auto i = c.length()-2; i+1 > 0; i--) {
        iVec[i] = rand() % (c.length()+1);
    }

    //Undo the shuffle
    for(auto i = 0; i < iVec.size(); i++) {
        //Do the swap reverse order the encryption did
        std::swap(c[i+1], c[iVec[i]]);
    }

    


    std::cout << c << std:: endl;
    

    return c;
}

unsigned long Encrypter::sMod(std::string lhs, unsigned long rhs) {
    unsigned long res = 0;

    //Mod each character
    for(auto i = 0; i < lhs.length(); i++) {

        //Multiply res by 10 and add character, then mod (appends lhs[i] to result, then mods)
        res = ((res * 10) + lhs[i] - '0') % rhs;

    }

    return res;
}

std::string Encrypter::toNumStr(std::string s) {
    std::string temp;
    for(auto i = 0; i < s.length(); i++) {

        std::stringstream ss;
        ss << static_cast<int>(s[i]);
        temp += ss.str();


    }
    return temp;
}

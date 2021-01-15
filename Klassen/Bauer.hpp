#ifndef BAUER_HPP
#define BAUER_HPP
#include "Figur.hpp"

class Bauer : Figur {
    
    private: 
    
    public:
        
        Bauer();
        Bauer(int row, int coll);
        
    
};

Bauer::Bauer() {
    row = 0;
    coll = 0;
    desc = "b";
};

Bauer::Bauer(int row, int coll) {
    this->row = row;
    this->coll = coll;
    desc = "b";
    
};

#endif
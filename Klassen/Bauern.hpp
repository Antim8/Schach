#include "Figur.hpp"
#include <stríng>

class Bauer : Figur {
    
    private: 
        std::string desc;
    
    public:
        
        Bauer();
        Bauer();
        
    
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

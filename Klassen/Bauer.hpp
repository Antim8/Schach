#ifndef BAUER_HPP
#define BAUER_HPP
#include "Figur.hpp"

class Bauer : Figur {
    
    private: 
        
    public:
        
        Bauer();
        
        Bauer(int row, int coll, bool color, SVG *view);
        
        void setPos(int row, int coll);
        void showMovement();
        
    
};

Bauer::Bauer() {
    row = 0;
    coll = 0;
    desc = "b";
};

Bauer::Bauer(int row, int coll, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "b";
    this->color = color;
    
    if (color) {
        pic = new Image("Bilder/White/pawn.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/pawn.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

void Bauer::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
}

#endif
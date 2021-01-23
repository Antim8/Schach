#ifndef BAUER_HPP
#define BAUER_HPP
#include "Figur.hpp"

class Bauer : Figur {
    
    private: 
        
    public:
        
        Bauer();
        
        Bauer(int coll, int row, bool color, SVG *view);
        
        void setPos(int coll, int row);
        void showMovement(Schachbrett *brett);
        
    
};

Bauer::Bauer() {
    row = 0;
    coll = 0;
    desc = "b";
};

Bauer::Bauer(int coll, int row, bool color, SVG *view) {
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

void Bauer::showMovement(Schachbrett *brett) {
    
     if (color) {
        
        if (row == 2) {
            
            colorIfAvailable(coll, row + 1, 0, 1, 2, brett, color);
              
        } else {
         
            colorIfAvailable(coll, row + 1, 0, 1, 1, brett, color);
            
        }
         
        if (brett->getTileFig(coll + 1, row + 1)[2] == 'b')
            colorIfAvailable(coll + 1, row + 1, 0, 0, 1, brett, color);
        if (coll > 1) { 
            if (brett->getTileFig(coll - 1, row + 1)[2] == 'b')
                colorIfAvailable(coll - 1, row + 1, 0, 0, 1, brett, color);
        }
            
         
    } else {
         
        if (row == 7) {
            
            colorIfAvailable(coll, row - 1, 0, -1, 2, brett, color);
              
        } else {
         
            colorIfAvailable(coll, row - 1, 0, 0, 1, brett, color);
            
        }
        if (coll > 1) {
            if (brett->getTileFig(coll - 1, row - 1)[2] == 'w')
                colorIfAvailable(coll - 1, row - 1, 0, 0, 1, brett, color);
        }
         
        if (brett->getTileFig(coll + 1, row - 1)[2] == 'w')
            colorIfAvailable(coll + 1, row - 1, 0, 0, 1, brett, color);
         
         
    }
    
}
    

#endif
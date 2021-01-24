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
};

void Bauer::showMovement(Schachbrett *brett) {
    
    if (color) {
        if (brett->getTileFig(coll, row + 1) == "" && (row + 1) <= 8) {
            
            brett->setPM(coll, row + 1);
            brett->colorTile(coll, row + 1, "green");
            
            if (row == 2 && brett->getTileFig(coll, row + 2) == "") {
                
                brett->setPM(coll, row + 2);
                brett->colorTile(coll, row + 2, "green");
                
            }
        }
        
        if (brett->getTileFig(coll + 1, row + 1)[2] == 'b' && (row + 1) <= 8 && (coll + 1) <= 8) {
            brett->setPM(coll + 1, row + 1);
            brett->colorTile(coll + 1, row + 1, "green");
        }
        if (brett->getTileFig(coll - 1, row + 1)[2] == 'b' && (row + 1) <= 8 && (coll - 1) >= 1) {
            brett->setPM(coll - 1, row + 1);
            brett->colorTile(coll - 1, row + 1, "green");
        }
        
    } else {
        
        if (brett->getTileFig(coll, row - 1) == "" && (row - 1) >= 1) {
            
            brett->setPM(coll, row - 1);
            brett->colorTile(coll, row - 1, "green");
            
            if (row == 7 && brett->getTileFig(coll, row - 2) == "") {
                
                brett->setPM(coll, row - 2);
                brett->colorTile(coll, row - 2, "green");
                
            }
        }
        
        if (brett->getTileFig(coll + 1, row - 1)[2] == 'w' && (row - 1) >= 1 && (coll + 1) <= 8) {
            brett->setPM(coll + 1, row - 1);
            brett->colorTile(coll + 1, row - 1, "green");
        }
        if (brett->getTileFig(coll - 1, row - 1)[2] == 'w' && (row - 1) >= 1 && (coll - 1) >= 1) {
            brett->setPM(coll - 1, row - 1);
            brett->colorTile(coll - 1, row - 1, "green");
        }
        
        
    }
    
}

#endif
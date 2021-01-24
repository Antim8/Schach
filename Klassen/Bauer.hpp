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
    
};



Bauer::Bauer(int coll, int row, bool color, SVG *view) {
    
    this->row = row;
    this->coll = coll;
    this->color = color;
    
    // Platzieren des Bildes relativ zu den Kästchen/Tiles
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

// Anzeigen der möglichen Züge 
void Bauer::showMovement(Schachbrett *brett) {
    
    // Für weiß
    if (color) {
        if (brett->getTileFig(coll, row + 1) == "" && (row + 1) <= 8) {
            
            // Speichern der möglichen Bewegungen in Array im Schachbrett
            brett->setPM(coll, row + 1);
            // Einfärben der möglichen Felder
            brett->colorTile(coll, row + 1, "green");
            
            if (row == 2 && brett->getTileFig(coll, row + 2) == "") {
                
                brett->setPM(coll, row + 2);
                brett->colorTile(coll, row + 2, "green");
                
            }
        }
        
        // Diagonales Schlagen falls eine gegnerische Figur bereit steht
        if (brett->getTileFig(coll + 1, row + 1)[2] == 'b' && (row + 1) <= 8 && (coll + 1) <= 8) {
            
            brett->setPM(coll + 1, row + 1);
            brett->colorTile(coll + 1, row + 1, "green");
            
        }
        if (brett->getTileFig(coll - 1, row + 1)[2] == 'b' && (row + 1) <= 8 && (coll - 1) >= 1) {
            
            brett->setPM(coll - 1, row + 1);
            brett->colorTile(coll - 1, row + 1, "green");
            
        }
        
    // Für Schwarz
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
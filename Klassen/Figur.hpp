#ifndef FIGUR_HPP
#define FIGUR_HPP

#include <algoviz/SVG.hpp> 
#include <string>
#include <iostream>
#include "Schachbrett.hpp"

class Figur {
    
  
    protected: 
    
        int row;
        int coll;
        // true = white false = black
        bool color;
        Image *pic;
    
    public:
        
        Figur();
        ~Figur();
        Figur(int coll, int row, bool color);
    
        int getRow();
        int getColl();
    
        bool getColor();
        void setPos(int coll, int row);
        
               
};

Figur::Figur() {
    
    row = 0;
    coll = 0;
    color = true;
    
};
// Beim Schlagen/Löschen der Figur wird das Bild explizit entfernt
Figur::~Figur() {
 
    delete pic;
    
};

Figur::Figur(int coll, int row, bool color) {
    
    this->row = row;
    this->coll = coll;
    this->color = color;
    
};

int Figur::getRow() {
    return row;
};

int Figur::getColl() {
    return coll;
};

bool Figur::getColor() {
    return color;
};

// Verschiebung einer Figur inklusive des zugehörigen Bildes
void Figur::setPos(int coll, int row) {
    
    this->row = row;
    this->coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
    
};
    
#endif
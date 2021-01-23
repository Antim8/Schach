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
        std::string desc;
        // true = white false = black
        bool color;
        Image *pic;
    
    public:
        
        Figur();
        ~Figur();
        Figur(int coll, int row, bool color);
    
        int getRow();
        int getColl();
    
        string getDesc();
        bool getColor();
    
        void setPos(int coll, int row);
        
               
};

Figur::Figur() {
    row = 0;
    coll = 0;
    desc = "";
    color = true;
};

Figur::~Figur() {
 
    delete pic;
    std::cout << "destr" << endl;
};

Figur::Figur(int coll, int row, bool color) {
    this->row = row;
    this->coll = coll;
    desc = "f";
    this->color = color;
};

int Figur::getRow() {
    return row;
};

int Figur::getColl() {
    return coll;
};

string Figur::getDesc() {
    return desc;
};

bool Figur::getColor() {
    return color;
};

void Figur::setPos(int coll, int row) {
    this->row = row;
    this->coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};
    
#endif
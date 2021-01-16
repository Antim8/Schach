#ifndef FIGUR_HPP
#define FIGUR_HPP

#include <string>
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
        Figur(int row, int coll, bool color);
    
        int getRow();
        int getColl();
    
        string getDesc();
        bool getColor();
    
        void setPos(int row, int coll);
               
};

Figur::Figur() {
    row = 0;
    coll = 0;
    desc = "";
    color = true;
};

Figur::Figur(int row, int coll, bool color) {
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

void Figur::setPos(int row, int coll) {
    this->row = row;
    this->coll = coll;
};
    
#endif
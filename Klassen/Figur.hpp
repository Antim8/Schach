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
        Figur(int row, int coll, bool color);
    
        int getRow();
        int getColl();
    
        string getDesc();
        bool getColor();
    
        void setPos(int row, int coll);
        void showMovement();
        void colorIfAvailable(int row, int coll, int drow, int dcoll, Schachbrett *brett);
               
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
}

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
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};

/*vector<int> Figur::colorIfAvailable(int row, int coll, int drow, int dcoll, Schachbrett *brett){
     vector<int> tile;
    if(row > 8 || row < 1 || coll > 8 || coll < 1 || (brett->getTileFig(row,coll)[2] == 'w' && color) || (brett->getTileFig(row,coll)[2] == 'b' && !color)) {
        tile.push_back(row - (drow + 2 * !color) * abs(drow));
        tile.push_back(coll - dcoll);
        return tile;
    }else if((brett->getTileFig(row, coll)[2] == 'w' && !color) || (brett->getTileFig(row, coll)[2] == 'b' && color)){
        tile.push_back(row);
        tile.push_back(coll);
        brett->colorTile(row, coll, "green");
        return tile;
    }else 
        brett->colorTile(row, coll, "green");
        return colorIfAvailable(row + (drow - 2 * !color) * abs(drow), coll + dcoll, drow, dcoll, brett);
}*/

void Figur::colorIfAvailable(int row, int coll, int drow, int dcoll, Schachbrett *brett){
    if(row > 8 || row < 1 || coll > 8 || coll < 1 || (brett->getTileFig(row,coll)[2] == 'w' && color) ||
       (brett->getTileFig(row,coll)[2] == 'b' && !color)) {
        return;
    }else if((brett->getTileFig(row, coll)[2] == 'w' && !color) || (brett->getTileFig(row, coll)[2] == 'b' && color)){
        brett->setPossibleMovement(row, coll);
        brett->colorTile(row, coll, "green");
        return;
    } else {
        brett->setPossibleMovement(row, coll);
        brett->colorTile(row, coll, "green");
        return colorIfAvailable(row + (drow - 2 * !color) * abs(drow), coll + dcoll, drow, dcoll, brett);
    }
}

#endif
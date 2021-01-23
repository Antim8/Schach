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
        void showMovement();
        void colorIfAvailable(int coll, int row, int dcoll, int drow, int steps, Schachbrett *brett);
               
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
    pic->moveTo(row * 60 + 40, 610 - coll * 60 - 30);
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

void Figur::colorIfAvailable(int coll, int row, int dcoll, int drow, int steps, Schachbrett *brett){
    if(row > 8 || row < 1 || coll > 8 || coll < 1 || steps <= 0 || (brett->getTileFig(coll, row)[2] == 'w' && color) ||
       (brett->getTileFig(coll, row)[2] == 'b' && !color)) {
        cout << 1 << endl;
        return;
    }else if((brett->getTileFig(coll, row)[2] == 'w' && !color) || (brett->getTileFig(coll, row)[2] == 'b' && color)){
        brett->setPossibleMovement(coll, row);
        brett->colorTile(coll, row, "green");
        return;
    } else {
        brett->setPossibleMovement(coll, row);
        brett->colorTile(coll, row, "green");
        return colorIfAvailable(coll + dcoll, row + drow, dcoll, drow, steps - 1, brett);
    }
}

#endif
#ifndef SPRINGER_HPP
#define SPRINGER_HPP

class Springer : Figur {
    
    private:
    
    public:
    
        Springer();
        Springer(int coll, int row, bool color, SVG *view);
        void setPos(int coll, int row);
        void showMovement(Schachbrett *brett);
};

Springer::Springer() {
    this->row = 0;
    this->coll = 0;
    this->desc = "s";
};

Springer::Springer(int coll, int row, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "s";
    this->color = color;
    
    if (color) {
        pic = new Image("Bilder/White/knight.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/knight.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

void Springer::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};

void Springer::showMovement(Schachbrett *brett) {
    // obenrechts
    if ((brett->getTileFig(coll + 1, row + 2) == "" || (brett->getTileFig(coll + 1, row + 2)[2] == 'b' && color) ||
       (brett->getTileFig(coll + 1, row + 2)[2] == 'w' && !color)) && (row + 2) <= 8 && (coll + 1) <= 8) {
         
        brett->setPM(coll + 1, row + 2);
        brett->colorTile(coll + 1, row + 2, "green");
    }
    
    if ((brett->getTileFig(coll + 2, row + 1) == "" || (brett->getTileFig(coll + 2, row + 1)[2] == 'b' && color) ||
       (brett->getTileFig(coll + 2, row + 1)[2] == 'w' && !color)) && (row + 1) <= 8 && (coll + 2) <= 8) {
         
        brett->setPM(coll + 2, row + 1);
        brett->colorTile(coll + 2, row + 1, "green");
    }
    
    //untenrechts
    if ((brett->getTileFig(coll + 1, row - 2) == "" || (brett->getTileFig(coll + 1, row - 2)[2] == 'b' && color) ||
       (brett->getTileFig(coll + 1, row - 2)[2] == 'w' && !color)) && (row - 2) >= 1 && (coll + 1) <= 8) {
         
        brett->setPM(coll + 1, row - 2);
        brett->colorTile(coll + 1, row - 2, "green");
    }
    
    if ((brett->getTileFig(coll + 2, row - 1) == "" || (brett->getTileFig(coll + 2, row - 1)[2] == 'b' && color) ||
       (brett->getTileFig(coll + 2, row - 1)[2] == 'w' && !color)) && (row - 1) >= 1 && (coll + 2) <= 8) {
         
        brett->setPM(coll + 2, row - 1);
        brett->colorTile(coll + 2, row - 1, "green");
    }
    
    //untenlinks
    if ((brett->getTileFig(coll - 1, row - 2) == "" || (brett->getTileFig(coll - 1, row - 2)[2] == 'b' && color) ||
       (brett->getTileFig(coll - 1, row - 2)[2] == 'w' && !color)) && (row - 2) >= 1 && (coll - 1) >= 1) {
         
        brett->setPM(coll - 1, row - 2);
        brett->colorTile(coll - 1, row - 2, "green");
    }
    
    if ((brett->getTileFig(coll - 2, row - 1) == "" || (brett->getTileFig(coll - 2, row - 1)[2] == 'b' && color) ||
       (brett->getTileFig(coll - 2, row - 1)[2] == 'w' && !color)) && (row - 1) >= 1 && (coll - 2) >= 1) {
         
        brett->setPM(coll - 2, row - 1);
        brett->colorTile(coll - 2, row - 1, "green");
    }
    
    //obenlinks
    if ((brett->getTileFig(coll - 1, row + 2) == "" || (brett->getTileFig(coll - 1, row + 2)[2] == 'b' && color) ||
       (brett->getTileFig(coll - 1, row + 2)[2] == 'w' && !color)) && (row + 2) <= 8 && (coll - 1) >= 1) {
         
        brett->setPM(coll - 1, row + 2);
        brett->colorTile(coll - 1, row + 2, "green");
    }
    
    if ((brett->getTileFig(coll - 2, row + 1) == "" || (brett->getTileFig(coll - 2, row + 1)[2] == 'b' && color) ||
       (brett->getTileFig(coll - 2, row + 1)[2] == 'w' && !color)) && (row + 1) <= 8 && (coll - 2) >= 1) {
         
        brett->setPM(coll - 2, row + 1);
        brett->colorTile(coll - 2, row + 1, "green");
    }
             

}


#endif
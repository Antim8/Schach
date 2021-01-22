#ifndef SPRINGER_HPP
#define SPRINGER_HPP

class Springer : Figur {
    
    private:
    
    public:
    
        Springer();
        Springer(int row, int coll, bool color, SVG *view);
        void setPos(int row, int coll);
        void showMovement(Schachbrett *brett);
};

Springer::Springer() {
    this->row = 0;
    this->coll = 0;
    this->desc = "s";
};

Springer::Springer(int row, int coll, bool color, SVG *view) {
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

void Laeufer::showMovement(Schachbrett *brett) {
    //nach oben rechts
    colorIfAvailable(row + 2, coll + 1, 0, 0, 1, brett);
    //nach oben links
    colorIfAvailable(row + 2, coll - 1, 0, 0, 1, brett);
    //nach unten links
    colorIfAvailable(row - 2, coll - 1, 0, 0, 1, brett);
    //nach unten rechts
    colorIfAvailable(row - 2, coll + 1, 0, 0, 1, brett);
};
#endif
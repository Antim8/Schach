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
    //nach oben rechts
    colorIfAvailable(coll + 1, row + 2, 0, 0, 1, brett);
    colorIfAvailable(coll + 2, row + 1, 0, 0, 1, brett);
    //nach oben links
    colorIfAvailable(coll - 1, row + 2, 0, 0, 1, brett);
    colorIfAvailable(coll - 2, row + 1, 0, 0, 1, brett);
    //nach unten links
    colorIfAvailable(coll - 1, row - 2, 0, 0, 1, brett);
    colorIfAvailable(coll - 2, row - 1, 0, 0, 1, brett);
    //nach unten rechts
    colorIfAvailable(coll + 1, row - 2, 0, 0, 1, brett);
    colorIfAvailable(coll + 2, row - 1, 0, 0, 1, brett);
};
#endif
#ifndef TURM_HPP
#define TURM_HPP

class Turm : Figur {
    
    private:
    
    public:
    
        Turm();
        Turm(int coll, int row, bool color, SVG *view);
        void showMovement(Schachbrett *brett);
        void setPos(int coll, int row);
    
};

Turm::Turm() {
    this->row = 0;
    this->coll = 0;
    this->desc = "t";
};

Turm::Turm(int coll, int row, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "t";
    this->color = color;
    
    if (color) {
        pic = new Image("Bilder/White/tower.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/tower.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

void Turm::showMovement(Schachbrett *brett) {
    //nach oben
    colorIfAvailable(coll, row + 1, 0, 1, 7, brett, color);
    //nach unten
    colorIfAvailable(coll, row - 1, 0, -1, 7, brett, color);
    //nach links
    colorIfAvailable(coll + 1, row, 1, 0, 7, brett, color);
    //nach rechts
    colorIfAvailable(coll - 1, row, -1, 0, 7, brett, color);
};

void Turm::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};

#endif
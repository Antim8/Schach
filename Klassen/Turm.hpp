#ifndef TURM_HPP
#define TURM_HPP

class Turm : Figur {
    
    private:
    
    public:
    
        Turm();
        Turm(int row, int coll, bool color, SVG *view);
        void showMovement(Schachbrett *brett);
        void setPos(int row, int coll);
    
};

Turm::Turm() {
    this->row = 0;
    this->coll = 0;
    this->desc = "t";
};

Turm::Turm(int row, int coll, bool color, SVG *view) {
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
    colorIfAvailable(row + 1, coll, 1, 0, 7, brett);
    //nach unten
    colorIfAvailable(row - 1, coll, -1, 0, 7, brett);
    //nach links
    colorIfAvailable(row, coll + 1, 0, 1, 7, brett);
    //nach rechts
    colorIfAvailable(row, coll - 1, 0, -1, 7, brett);
};

void Turm::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};

#endif
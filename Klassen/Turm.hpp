#ifndef TURM_HPP
#define TURM_HPP

class Turm : Figur {
    
    private:
    
    public:
    
        Turm();
        Turm(int row, int coll, bool color, SVG *view);
    
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
        pic = new Image("../Bilder/White/tower.png", coll * 60 + 40, 550 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("../Bilder/Black/tower.png", coll * 60 + 40, 550 - row * 60 - 30, 60, 60, view);
    }
    
};
#endif
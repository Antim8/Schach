#ifndef KOENIG_HPP
#define KOENIG_HPP

class Koenig : Figur {
    
    private:
        
    public:
    
        Koenig();
        Koenig(int row, int coll, bool color, SVG *view);
        void setPos(int row, int coll);
};

Koenig::Koenig() {
    this->row = 0;
    this->coll = 0;
    this->desc = "k";
};

Koenig::Koenig(int row, int coll, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "k";
    this->color = color;
    
    if (color) {
        pic = new Image("Bilder/White/king.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/king.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

void Koenig::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};
#endif
#ifndef LAEUFER_HPP
#define LAEUFER_HPP

class Laeufer : Figur {
    
    private:
    
    public:
    
        Laeufer();
        Laeufer(int row, int coll, bool color, SVG *view);
    
};

Laeufer::Laeufer() {
    this->row = 0;
    this->coll = 0;
    this->desc = "l";
};

Laeufer::Laeufer(int row, int coll, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "l";
    this->color = color;
    
    if (color) {
        pic = new Image("../Bilder/White/bishop.png", coll * 60 + 40, 550 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("../Bilder/Black/bishop.png", coll * 60 + 40, 550 - row * 60 - 30, 60, 60, view);
    }
    
};
#endif
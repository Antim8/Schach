#ifndef DAME_HPP
#define DAME_HPP

class Dame : Figur {
    
    private:
    
    public:
    
        Dame();
        Dame(int row, int coll, bool color, SVG *view);
    
};

Dame::Dame() {
    this->row = 0;
    this->coll = 0;
    this->desc = "d";
};

Dame::Dame(int row, int coll, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "d";
    this->color = color;
    
    if (color) {
        pic = new Image("../Bilder/White/queen.png", coll * 60 + 40, 550 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("../Bilder/Black/queen.png", coll * 60 + 40, 550 - row * 60 - 30, 60, 60, view);
    }
    
};
#endif
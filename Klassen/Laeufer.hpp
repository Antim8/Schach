#ifndef LAEUFER_HPP
#define LAEUFER_HPP

class Laeufer : Figur {
    
    private:
    
    public:
    
        Laeufer();
        Laeufer(int coll, int row, bool color, SVG *view);
        void setPos(int coll, int row);
        void showMovement(Schachbrett *brett);
};

Laeufer::Laeufer() {
    this->row = 0;
    this->coll = 0;
    this->desc = "l";
};

Laeufer::Laeufer(int coll, int row, bool color, SVG *view) {
    this->row = row;
    this->coll = coll;
    desc = "l";
    this->color = color;
    
    if (color) {
        pic = new Image("Bilder/White/bishop.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/bishop.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

void Laeufer::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};

void Laeufer::showMovement(Schachbrett *brett) {
    //nach oben rechts
    colorIfAvailable(coll + 1, row + 1, 1, 1, 7, brett);
    //nach oben links
    colorIfAvailable(coll - 1, row + 1, -1, 1, 7, brett);
    //nach unten links
    colorIfAvailable(coll - 1, row - 1, -1, -1, 7, brett);
    //nach unten rechts
    colorIfAvailable(coll + 1, row - 1, 1, -1, 7, brett);
};
#endif
#ifndef KOENIG_HPP
#define KOENIG_HPP

class Koenig : Figur {
    
    private:
        
    public:
    
        Koenig();
        Koenig(int row, int coll, bool color, SVG *view);
        void setPos(int row, int coll);
        void showMovement(Schachbrett *brett);
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

void Koenig::showMovement(Schachbrett *brett) {
        
    // nach oben
    colorIfAvailable(row + 1, coll, 1, 0, 1, brett);
    // nach unten
    colorIfAvailable(row - 1, coll, -1, 0, 1, brett);
    // nach rechts
    colorIfAvailable(row, coll + 1, 0, 1, 1, brett);
    // nach links
    colorIfAvailable(row, coll - 1, 0, -1, 1, brett);
    // nach oben rechts
    colorIfAvailable(row + 1, coll + 1, 1, 1, 1, brett); 
    // nach unten rechts
    colorIfAvailable(row - 1, coll + 1, -1, 1, 1, brett); 
    // nach unten links
    colorIfAvailable(row - 1, coll - 1, -1, -1, 1, brett); 
    // nach oben links
    colorIfAvailable(row + 1, coll - 1, 1, -1, 1, brett); 
    
}

#endif
#ifndef DAME_HPP
#define DAME_HPP

class Dame : Figur {
    
    private:
    
    public:
    
        Dame();
        Dame(int row, int coll, bool color, SVG *view);
        void setPos(int row, int coll);
        void showMovement(Schachbrett *brett);
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
        pic = new Image("Bilder/White/queen.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/queen.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

void Dame::setPos(int coll, int row) {
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
};

void Dame::showMovement(Schachbrett *brett) {
    // nach oben
    colorIfAvailable(row + 1, coll, 1, 0, 7, brett);
    // nach unten
    colorIfAvailable(row - 1, coll, -1, 0, 7, brett);
    // nach rechts
    colorIfAvailable(row, coll + 1, 0, 1, 7, brett);
    // nach links
    colorIfAvailable(row, coll - 1, 0, -1, 7, brett);
    // nach oben rechts
    colorIfAvailable(row + 1, coll + 1, 1, 1, 7, brett); 
    // nach unten rechts
    colorIfAvailable(row - 1, coll + 1, -1, 1, 7, brett); 
    // nach unten links
    colorIfAvailable(row - 1, coll - 1, -1, -1, 7, brett); 
    // nach oben links
    colorIfAvailable(row + 1, coll - 1, 1, -1, 7, brett); 
}
#endif
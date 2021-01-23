#ifndef DAME_HPP
#define DAME_HPP

class Dame : Figur {
    
    private:
    
    public:
    
        Dame();
        Dame(int coll, int row, bool color, SVG *view);
        void setPos(int coll, int row);
        void showMovement(Schachbrett *brett);
};

Dame::Dame() {
    this->row = 0;
    this->coll = 0;
    this->desc = "d";
};

Dame::Dame(int coll, int row, bool color, SVG *view) {
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
    colorIfAvailable(coll, row + 1, 0, 1, 7, brett, color);
    // nach unten
    colorIfAvailable(coll, row - 1, 0, -1, 7, brett, color);
    // nach rechts
    colorIfAvailable(coll + 1, row, 1, 0, 7, brett, color);
    // nach links
    colorIfAvailable(coll - 1, row, -1, 0, 7, brett, color);
    // nach oben rechts
    cout << "Dame Daten " << coll << " " << row << " " << color << endl; 
    colorIfAvailable(coll + 1, row + 1, 1, 1, 7, brett, color); 
    // nach unten rechts
    colorIfAvailable(coll + 1, row - 1, 1, -1, 7, brett, color); 
    // nach unten links
    colorIfAvailable(coll - 1, row - 1, -1, -1, 7, brett, color); 
    // nach oben links
    colorIfAvailable(coll - 1, row + 1, -1, 1, 7, brett, color); 
    return;
}
#endif
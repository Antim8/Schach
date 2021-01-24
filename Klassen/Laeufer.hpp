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
    
};

Laeufer::Laeufer(int coll, int row, bool color, SVG *view) {
    
    this->row = row;
    this->coll = coll;
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

// siehe Dame
void Laeufer::showMovement(Schachbrett *brett) {
    
    bool endOR = false;
    bool endUR = false;
    bool endUL = false;
    bool endOL = false;
    
    for(int i = 1; i < 8; i++) {

        if ((brett->getTileFig(coll + i - 1, row + i - 1)[2] == 'b' && color) ||
            (brett->getTileFig(coll + i - 1, row + i - 1)[2] == 'w' && !color) ||
            (brett->getTileFig(coll + i, row + i)[2] == 'b' && !color) ||
            (brett->getTileFig(coll + i, row + i)[2] == 'w' && color) || (row + i) > 8 || (coll + i) > 8)
                endOR = true;
        
        if ((brett->getTileFig(coll + i - 1, row - i + 1)[2] == 'b' && color) ||
            (brett->getTileFig(coll + i - 1, row - i + 1)[2] == 'w' && !color) ||
            (brett->getTileFig(coll + i, row - i)[2] == 'b' && !color) ||
            (brett->getTileFig(coll + i, row - i)[2] == 'w' && color) || (row - i) < 1 || (coll + i) > 8)
                endUR = true;
        
        if ((brett->getTileFig(coll - i + 1, row - i + 1)[2] == 'b' && color) ||
            (brett->getTileFig(coll - i + 1, row - i + 1)[2] == 'w' && !color) ||
            (brett->getTileFig(coll - i, row - i)[2] == 'b' && !color) ||
            (brett->getTileFig(coll - i, row - i)[2] == 'w' && color) || (row - i) < 1 || (coll - i) < 1)
                endUL = true;
        
        if ((brett->getTileFig(coll - i + 1, row + i - 1)[2] == 'b' && color) ||
            (brett->getTileFig(coll - i + 1, row + i - 1)[2] == 'w' && !color) ||
            (brett->getTileFig(coll - i, row + i)[2] == 'b' && !color) ||
            (brett->getTileFig(coll - i, row + i)[2] == 'w' && color) || (row + i) > 8 || (coll - i) < 1)
                endOL = true;
       

            // obenrechts

            if (!endOR) { 
                
                brett->setPM(coll + i, row + i);
                brett->colorTile(coll + i, row + i, "green");

            }
            // untenrechts

            if(!endUR) {  
                
                brett->setPM(coll + i, row - i);
                brett->colorTile(coll + i, row - i, "green");

            }
            // untenlinks

            if(!endUL) { 
                
                brett->setPM(coll - i, row - i);
                brett->colorTile(coll - i, row - i, "green");

            }
            // obenlinks

            if(!endOL) { 
                
                brett->setPM(coll - i, row + i);
                brett->colorTile(coll - i, row + i, "green");

            }
    }
    
}
#endif
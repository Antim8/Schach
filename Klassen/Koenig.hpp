#ifndef KOENIG_HPP
#define KOENIG_HPP

class Koenig : Figur {
    
    private:
        
    public:
    
        Koenig();
        Koenig(int coll, int row, bool color, SVG *view);
    
        void setPos(int coll, int row);
        void showMovement(Schachbrett *brett);
};

Koenig::Koenig() {
    
    this->row = 0;
    this->coll = 0;
  
};

Koenig::Koenig(int coll, int row, bool color, SVG *view) {
    
    this->row = row;
    this->coll = coll;
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

// siehe Dame
void Koenig::showMovement(Schachbrett *brett) {
    
    bool endO = false;
    bool endU = false;
    bool endR = false;
    bool endL = false; 
    bool endOR = false;
    bool endUR = false;
    bool endUL = false;
    bool endOL = false;
    
    for (int i = 1; i < 2; i++) {
        
        if ((brett->getTileFig(coll, row + i - 1)[2] == 'b' && color) || (brett->getTileFig(coll, row + i - 1)[2] == 'w' && !color) ||
           (brett->getTileFig(coll, row + i)[2] == 'b' && !color) || (brett->getTileFig(coll, row + i)[2] == 'w' && color) || (row + i) > 8)
            endO = true;
        
        if ((brett->getTileFig(coll, row - i + 1)[2] == 'b' && color) || (brett->getTileFig(coll, row - i + 1)[2] == 'w' && !color) ||
           (brett->getTileFig(coll, row - i)[2] == 'b' && !color) || (brett->getTileFig(coll, row - i)[2] == 'w' && color) || (row - i) < 1)
            endU = true;
        
        if ((brett->getTileFig(coll + i - 1, row)[2] == 'b' && color) || (brett->getTileFig(coll + i - 1, row)[2] == 'w' && !color) ||
           (brett->getTileFig(coll + i,row)[2] == 'b' && !color) || (brett->getTileFig(coll + i, row)[2] == 'w' && color) || (coll + i) > 8)
            endR = true;
        
        if ((brett->getTileFig(coll - i + 1, row)[2] == 'b' && color) || (brett->getTileFig(coll - i + 1, row)[2] == 'w' && !color) ||
           (brett->getTileFig(coll - i,row)[2] == 'b' && !color) || (brett->getTileFig(coll - i, row)[2] == 'w' && color) || (coll - i) < 1)
            endL = true;        
        
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
        
        // oben
        if (!endO) {  
            
            brett->setPM(coll, row + i);
            brett->colorTile(coll, row + i, "green");
            
        }
        // unten
       
        if(!endU) { 
            
            brett->setPM(coll, row - i);
            brett->colorTile(coll, row - i, "green");
            
        }
        // rechts
        
        if(!endR) {  
            
            brett->setPM(coll + i, row);
            brett->colorTile(coll + i, row, "green");
            
        }
        // links
       
        if(!endL) {  
            
            brett->setPM(coll - i, row);
            brett->colorTile(coll - i, row, "green");
            
        }

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
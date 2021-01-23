#ifndef SCHACHBRETT_HPP
#define SCHACHBRETT_HPP

#include <algoviz/SVG.hpp>


class Schachbrett {
    
    private:
    
        SVG *feld;
        Rect* tiles[13][10];
        string order[8][8] = {""};
        string pM[8][8] = {""};
    
    public: 
        
        Schachbrett();
        void startingOrder();
        SVG *getFeld();
        void colorTile(int coll, int row, string color);
        void resetColor();
        string getTileFig( int coll, int row);
        string setTileFig(int coll, int row, string tileFig);
        string getPM(int coll, int row);
        void setPM(int coll, int row);
        void resetPM();
};
            
        
Schachbrett::Schachbrett() {
        
    feld = new SVG(800, 610, "Schachbrett");
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 10; j++) {
            
            tiles[i][j] = new Rect(10 + i * 60, 550 - j * 60, 60, 60, feld);
            
            tiles[i][j]->setFill("lightgrey");
            tiles[i][j]->setColor("transparent");
            
            if( i > 0 && i < 9 && j > 0 && j < 9) {
            
                if( (i % 2 == 0 &&  j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
                
                    tiles[i][j]->setFill(139, 69, 19, 0.7);
                } else {
                    
                    tiles[i][j]->setFill(255, 211, 155, 0.7);
                }
            }
        }
    }
    
    for(int i = 8; i > 0; i--) {
        
        Text *tmptext;
        tmptext = new Text(to_string(i), 37, (9 - i) * 60 + 40, feld);
        
    }
    
    for(int i = 8; i > 0; i--) {
        
        Text *tmptext;
        string letters[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
        tmptext = new Text(letters[8-i], 37 + 60 * (9 - i), 580, feld);  
        
    }
    
    Text *tmpText = new Text("weiß", 620, 40, feld);
    tmpText = new Text("schwarz", 740, 40, feld);
    
    
    
};

/*void Schachbrett::startingOrder() {
    
    string storder[] = {"t0", "s0", "l0", "d ", "k ", "l1", "s1", "t1"}; 
    
    for ( int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            
            order[7 * i][j][0] = storder[j];
            
            if (i) {
                order[7 * i][j][1] = "b";
            } else {
                order[7 * i][j][1] = "w";
            }
            
            //TODO: Bauern hinzu
            order[6][j][0] = "b" + to_string(j);
            order[6][j][1] = "b";
            order[1][j][0] = "b" + to_string(j);
            order[1][j][1] = "w";
        }
    }
    
};*/

void Schachbrett::startingOrder() {
    
    string storder[] = {"t0", "s0", "l0", "d ", "k ", "l1", "s1", "t1"}; 
    
    for ( int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            
            //order[j][7* i] = storder[j];
            
            if (i) {
                order[j][7 * i] = storder[j] + "b";
            } else {
                order[j][7 * i] = storder[j] + "w";
            }
            
            //TODO: Bauern hinzu
            order[j][6] = "b" + to_string(j) + "b";
            order[j][1] = "b" + to_string(j) + "w";
        }
    }
    
};


SVG *Schachbrett::getFeld() {
    return feld;
};

void Schachbrett::colorTile(int coll, int row, string color) {
    if(row > 0 && coll > 0)
        tiles[coll][row]->setColor(color);
        
};

void Schachbrett::resetColor() {
    for(int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            tiles[i][j]->setColor("transparent");
        }
    }
        
};


string Schachbrett::getTileFig(int coll, int row) {
    if (row > 0 && coll > 0)
        return order[coll - 1][row - 1];//(order[row - 1][coll - 1][0] + order[row - 1][coll - 1][1]); 
    else 
        return "";
    
};

string Schachbrett::setTileFig(int coll, int row, string tileFig) {
 //TODO
    string figOnTile = getTileFig(coll, row);
    order[coll - 1][row - 1] = tileFig;
    if (figOnTile[0] != 'k') 
        return figOnTile;
    else
        return "gameOver";
    
};

string Schachbrett::getPM(int coll, int row) {
    
    return pM[coll - 1][row - 1];
    
}

void Schachbrett::setPM(int coll, int row) {
    
    pM[coll - 1][row - 1] = "p";

}

void Schachbrett::resetPM(){
    
    for(int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            pM[i][j] = "";
        }
    }

}
    
#endif
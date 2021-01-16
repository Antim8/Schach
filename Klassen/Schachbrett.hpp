#ifndef SCHACHBRETT_HPP
#define SCHACHBRETT_HPP

#include <algoviz/SVG.hpp>



class Schachbrett {
    
    private:
    
        SVG *feld;
        Rect* tiles[13][10];
        string order[8][8][2];
    
    public: 
        
        Schachbrett();
        void startingOrder();
    
};
            
        
Schachbrett::Schachbrett() {
        
    feld = new SVG(800, 800, "Schachbrett");
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

void Schachbrett::startingOrder() {
    
    string storder[] = {"t", "s", "l", "d", "k", "l", "s", "t"}; 
    
    for ( int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            
            order[7 * i][j][0] = storder[j];
            
            if (i) {
                order[7 * i][j][1] = "b";
            } else {
                order[7 * i][j][1] = "w";
            }
            
            //TODO: Bauern hinzu
            order[6][j][0] = "b";
            order[6][j][1] = "b";
            order[1][j][0] = "b";
            order[1][j][1] = "w";
        }
    }
    
}
      
#endif
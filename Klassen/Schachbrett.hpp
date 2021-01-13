#ifndef SCHACHBRETT_HPP
#define SCHACHBRETT_HPP

#include <algoviz/SVG.hpp>

class Schachbrett {
    
    private:
    
        SVG *feld;
        Rect* tiles[13][10];
    
    public: 
        
        Schachbrett();
    
};
            
        
Schachbrett::Schachbrett() {
        
    feld = new SVG(800, 800, "Schachbrett");
    for (int i = 0; i < 13; i++) {
   
        for (int j = 0; j < 10; j++) {
            tiles[i][j] = new Rect(10 + i * 60, 10 + j * 60, 60, 60, feld);
            
            tiles[i][j]->setFill("lightgrey");
            tiles[i][j]->setColor("transparent");
        
            if( i > 0 && i < 9 && j > 0 && j < 9) {
            
                if( (i % 2 != 0 &&  j % 2 != 0) || (i % 2 == 0 && j % 2 == 0)) {
                
                    tiles[i][j]->setFill(255, 211, 155, 0.7);
                } else {
                    
                    tiles[i][j]->setFill(139, 69, 19, 0.7);
                }
            }
        }
    }
    
    for(int i = 8; i > 0; i--) {
        
        Text *tmptext;
        tmptext = new Text(to_string(i), 37, (9 - i) * 60 + 40, feld);
        
    }
    
    /*for(int i = 8; i > 0; i--) {
        
        Text *tmptext;
        string letters = "ABCDEFGH";
        string letter = letters[8-i] + "";
        tmptext = new Text(letter, 37 + 60 * (9 - i), 580, feld); 
        //tmptext = new Text(char(("" + 'A' + (8 - i))), 37 + 60 * (9 - i), 580, feld); 
        
    }*/
    
    Text *tmpText = new Text("weiß", 620, 40, feld);
    tmpText = new Text("schwarz", 740, 40, feld);
    
}
      
#endif
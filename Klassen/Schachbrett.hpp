#include <algoviz/SVG.hpp>

class Schachbrett {
    
    private:
    
        SVG *feld;
        Rect* tiles[12][10];
    
    public: 
        
        Schachbrett(){
        
            feld = new SVG(800, 800, "Schachbrett");
    
            for (int i = 0; i < 12; i++) {
        
                for (int j = 0; j < 10; j++) {
         
                    tiles[i][j] = new Rect(10 + i * 60, 10 + j * 60, 60, 60, feld);
                
                    if( i > 0 && i < 9 && j > 0 && j < 9) {
                    
                        if( (i % 2 != 0 &&  j % 2 != 0) || (i % 2 == 0 && j % 2 == 0)) {
                        
                            tiles[i][j]->setFill(255, 211, 155, 0.7);
                        } else {
                            
                            tiles[i][j]->setFill(139, 69, 19, 0.7);
                        }
                    }
                }
            }
        }
    
};
            
        

 
/*Schachbrett::Schachbrett() {
  
    feld = new SVG(600, 600, "Schachbrett");
    
    for (int i = 0; i < 12; i++) {
        
        for (int j = 0; j < 12; j++) {
         
            tiles[i][j] = new Rect(10 + i * 40, 10 + j * 40, 40, 40, feld);
            
            if( i > 0 && i < 9 && j > 0 && j < 9) {
                
                if( (i % 2 != 0 &&  j % i != 0) || (i % 2 == 0 && j % 2 == 0)) {
                    
                    tiles[i][j]->setFill(139, 69, 19, 0.7);
                } else {
                    tiles[i][j]->setFill(255, 211, 155, 0.7);
                }
            }
            
        }
    }
    
};*/

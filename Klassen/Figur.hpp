

class Figur {
    
  
    protected: 
        int row;
        int coll;
        
    public:
        
        Figur();
        Figur(int row, int coll);
    
        int getRow();
        int getColl();
               
};

Figur::Figur() {
    row = 0;
    coll = 0;
};

Figur::Figur(int row, int coll) {
    this->row = row;
    this->coll = coll;
};

int Figur::getRow() {
    return row;
};

int Figur::getColl() {
    return coll;
};
#ifndef SPRINGER_HPP
#define SPRINGER_HPP

class Springer : Figur {
    
    private:
    
    public:
    
        Springer();
        Springer(int row, int coll);
    
};

Springer::Springer() {
    this->row = 0;
    this->coll = 0;
    this->desc = "s";
};

Springer::Springer(int row, int coll) {
    this->row = row;
    this->coll = coll;
    desc = "s";
    
};
#endif
#ifndef KOENIG_HPP
#define KOENIG_HPP

class Koenig : Figur {
    
    private:
    
    public:
    
        Koenig();
        Koenig(int row, int coll);
    
};

Koenig::Koenig() {
    this->row = 0;
    this->coll = 0;
    this->desc = "k";
};

Koenig::Koenig(int row, int coll) {
    this->row = row;
    this->coll = coll;
    desc = "k";
    
};
#endif
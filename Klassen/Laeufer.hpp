#ifndef LAEUFER_HPP
#define LAEUFER_HPP

class Laeufer : Figur {
    
    private:
    
    public:
    
        Laeufer();
        Laeufer(int row, int coll);
    
};

Laeufer::Laeufer() {
    this->row = 0;
    this->coll = 0;
    this->desc = "l";
};

Laeufer::Laeufer(int row, int coll) {
    this->row = row;
    this->coll = coll;
    desc = "l";
    
};
#endif
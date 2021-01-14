#ifndef DAME_HPP
#define DAME_HPP

class Dame : Figur {
    
    private:
    
    public:
    
        Dame();
        Dame(int row, int coll);
    
};

Dame::Dame() {
    this->row = 0;
    this->coll = 0;
    this->desc = "d";
};

Dame::Dame(int row, int coll) {
    this->row = row;
    this->coll = coll;
    desc = "d";
    
};
#endif
#include <iostream>
#include "stampbuf.h"

class row{
    private:
        int actual_row;
    public:
        row(): actual_row(0){}
        row(int r) : actual_row(r){}
        int getrow()const { return actual_row; }
};

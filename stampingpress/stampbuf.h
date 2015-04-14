#ifndef STAMPBUF_H
#define STAMPBUF_H

#include <streambuf>

using namespace std;

class stampbuf : public std::streambuf
{
    private:
        char * buffer;
        int cur_col;
        int cur_row;
        int buffer_size;
        int stamping(int i);
    public:
        stampbuf(int col, int row);
        ~stampbuf();
        void add_row();
        void set_row(int row);
        void set_col(int col);
        virtual int sync();
        virtual int overflow(int ch);
};

#endif

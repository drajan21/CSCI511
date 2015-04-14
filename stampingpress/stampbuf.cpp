#include <iostream>
#include "stampbuf.h"
#include "stamp.h"
#include <string>

using namespace std;
using namespace stamping_press;

stampbuf::stampbuf(int col, int row): cur_col(0), cur_row(0), buffer_size(col/2), buffer(new char[col/2])
{
    insert_plate(col, row);
    setp(buffer, buffer + buffer_size);
}

//stampbuf dtor
stampbuf::~stampbuf()
{
    sync();
    delete [] buffer;
    eject_plate();
}

     

int stampbuf::sync()
{
    for(char *i = pbase(); i!= pptr(); ++i)
    {
        try{
            set_die(*i);
        }
        catch(...)
        {
            //to handle repeated letters
            if(*i == get_die())
            {
            }
            //if no die present just  increment column
            else
            {
                cur_col++;
                continue;
            }
        }
        try{
            stamp(cur_col, cur_row);
        }
        catch(...)
        {
            cur_col++;
            continue;
        }
        cur_col++;
    }
    setp(buffer, buffer + buffer_size);

    return 0;
}

int stampbuf::overflow(int ch)
{
    for(int i = 0; i < buffer_size; ++i)
    {
    
        try{
            set_die(buffer[i]);
        }
        catch(...)
        {
            if(buffer[i] == get_die())
            {
            }
            else
            {
                cur_col++;
                continue;
            }
        }
        try{
            stamp(cur_col, cur_row);
        }
        catch(...)
        {
            cur_col++;
            continue;
        }
        cur_col++;
    }
    setp(buffer, buffer + buffer_size);
    //if the last character is not end of buffer array
    if(ch != traits_type::eof())
    {
        //write character to the pptr
        *pptr() = ch;
        //increment pointer
        pbump(1);
    }
    return ch;
}

//Function moves to the next row
void stampbuf::add_row()
{
    cur_row++;
}
//Function sets value of the current row
void stampbuf::set_row(int row)
{
    cur_row = row;
}
//Function sets the value of current column
void stampbuf::set_col(int col)
{
    cur_col = col;
}

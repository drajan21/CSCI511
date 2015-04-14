#include <iostream>
#include "stampbuf.h"
#include "row.h"

using namespace std;

class stampstream: public ostream
{
    public:
        stampstream(int col, int row);
        ~stampstream();
};

stampstream::stampstream(int col, int row): ostream(new stampbuf(col, row))
{
}

//stampstream's dtor
stampstream::~stampstream()
{
    delete rdbuf();
}

ostream& operator<<(ostream &os, const row& r)
{
    stampbuf *sb = dynamic_cast<stampbuf*>(os.rdbuf());
    os.flush();
    //get the new row to be set
    int newRow = r.getrow();
    sb->set_row(newRow);
    sb->set_col(0);
    return os;
}

ostream& endrow(ostream &os)
{
    stampbuf *sb = dynamic_cast<stampbuf*>(os.rdbuf());
    os.flush();
    //add a new row
    sb->add_row();
    sb->set_col(0);
    return os;
}

int main()
{
    stampstream s(30,10);

    s << "hi th#re planetoid humans" <<endrow
     << " how's all the fish" << row(5) << "one more";
    s << row(4) << " two more" << 3.1415;
    s << row(8) << "The quick brown fox jumped over the lazy dog's back.";
    s << row(3) << "the end";
    return 0;
}

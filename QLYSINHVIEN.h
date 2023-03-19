#ifndef QLYSINHVIEN_H
#define QLYSINHVIEN_H

#include<fstream>
#include "SINHVIEN.h"
#include<vector>
#include<sstream>
#include <time.h>

using namespace std;
class Qly_Sinhvien
{
    private:
    Sinhvien* danhsach;
    int size=0;

    public:
    Qly_Sinhvien();
    ~Qly_Sinhvien();
    void XuatFile();
    void DocFile();
    void ThemSV();
    void XuatDTB();
    void Date();
    void Ranking();
        
};
struct SortedMark{

    inline bool operator() (const Sinhvien& sv1,const  Sinhvien& sv2)
{
    return (sv1.dtb() > sv2.dtb());
}
};
#endif

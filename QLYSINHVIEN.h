#ifndef QLYSINHVIEN_H
#define QLYSINHVIEN_H
#include<fstream>
#include "SINHVIEN.h"
#include<vector>
#include<sstream>
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
    void Print();
        
};
#endif

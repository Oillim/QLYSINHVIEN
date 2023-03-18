#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<cstring>
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>

const int STR_SIZE = 40;
const int MARK_SIZE = 3;
class Sinhvien
{
    private:
        char* hoten;
        char*  maso;
        char* ngaysinh;
        float* marks;

    public:
        Sinhvien();
        ~Sinhvien();
        
        Sinhvien(const Sinhvien& sv);
        Sinhvien& operator=(Sinhvien sv);
        void XuatSV();
        void NhapSV(const std::string& val,int index);
};

#endif
#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<cstring>
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>
#include<algorithm>
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
        float dtb() const;
        Sinhvien(const Sinhvien& sv);
        Sinhvien& operator=(Sinhvien sv);
        std::string GetDate();
        void NhapSV(const std::string& val,int index);
    friend void swap(Sinhvien& sv1, Sinhvien& sv2);
    friend std::ostream& operator<<(std::ostream& os, const Sinhvien& sv);
};

#endif
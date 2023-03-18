#include "SINHVIEN.h"

Sinhvien::Sinhvien()
:hoten(new char[STR_SIZE]())
,maso(new char[STR_SIZE]())
, ngaysinh(new char[STR_SIZE]())
, marks(new float[MARK_SIZE]())
{
}
Sinhvien::~Sinhvien(){
    delete[] hoten;
    delete[] maso;
    delete[] ngaysinh;
    delete[] marks;
    
}
void Sinhvien::NhapSV(const std::string& val,int index){
    
     switch(index)
     {
        case 0:
            
            strcpy(hoten,val.c_str());
            break;
        case 1:
            //maso = (char*)val.c_str();break;
        case 2:
            //ngaysinh = (char*)val.c_str();break;
        default:
            //marks[index-3] = std::atof(val.c_str());
            break;
     }
}

Sinhvien::Sinhvien(const Sinhvien& sv)
{
    hoten = sv.hoten;
    maso = sv.maso;
    ngaysinh = sv.ngaysinh;
    for (int i=0;i<3;i++)
    marks[i] = sv.marks[i];
}


Sinhvien& Sinhvien::operator=(Sinhvien sv)
{
    hoten = sv.hoten;
    maso = sv.maso;
    ngaysinh = sv.ngaysinh;
    for(int i=0;i<3;i++)
    marks[i] = sv.marks[i];
}

void Sinhvien::XuatSV()
{
    std::cout << "Ten cua sinh vien: "  << hoten << "\n";
    std::cout << "Ma so sinh vien: " << maso << "\n";
    std::cout << "Ngay sinh cua sinh vien: " << ngaysinh << "\n";
    std::cout << "Diem bai tap cua sinh vien: " << marks[0] << "\n";
    std::cout << "Diem giua ky cua sinh vien: " << marks[1] << "\n";
    std::cout << "Diem cuoi ky cua sinh vien: " << marks[2] << "\n";
}


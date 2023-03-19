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
    
     switch(index%6)
     {
        case 0: 
            strcpy(hoten,val.c_str());
            break;
        case 1:
            strcpy(maso,val.c_str());break;
        case 2:
            strcpy(ngaysinh,val.c_str());break;
        default:
            marks[index-3] = std::atof(val.c_str());
            break;
     }
}

Sinhvien::Sinhvien(const Sinhvien& sv)
: hoten(new char[STR_SIZE]())
, maso(new char[STR_SIZE]())
, ngaysinh(new char[STR_SIZE]())
, marks(new float[MARK_SIZE]())
{ 
    strcpy(hoten,sv.hoten);
    strcpy(maso,sv.maso);
    strcpy(ngaysinh,sv.ngaysinh);

    std::copy(sv.marks, sv.marks + MARK_SIZE, marks);
}


Sinhvien& Sinhvien::operator=(Sinhvien sv)
{   
    swap(*this,sv);
    return *this;
    
}

void swap(Sinhvien& sv1, Sinhvien&sv2)
{
    using std::swap;
    swap(sv1.hoten,sv2.hoten);
    swap(sv1.maso,sv2.maso);
    swap(sv1.ngaysinh,sv2.ngaysinh);
    swap(sv1.marks,sv2.marks);
}
std::ostream& operator<<(std::ostream& os, const Sinhvien& sv)
{
    os << sv.hoten << " | "
       << sv.maso << " | " 
       << sv.ngaysinh << " | " 
       << sv.marks[0] << " | " 
       << sv.marks[1] << " | " 
       << sv.marks[2];
    return os;
}
float Sinhvien::dtb() const
{
    float stdAvg = marks[0]*0.25+marks[1]*0.25+marks[2]*0.5;
    return stdAvg;
}
std::string Sinhvien::GetDate()
{
    std::string s(ngaysinh);
    return s.substr(0,s.length()-1);

}



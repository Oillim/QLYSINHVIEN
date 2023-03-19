#include "SINHVIEN.h"
#include "QLYSINHVIEN.h"
#include<iostream>
using namespace std;

int main()
{
    Qly_Sinhvien qlysinhvien;
    int choice;
    qlysinhvien.DocFile();
    while(true)
    {
        
        cout<<"Menu quan ly sinh vien\n";
        cout<<"1. Ghi danh sach sinh vien len tap tin.\n";
        cout<<"2. Tim cac sinh vien co diem trung binh nho hon diem trung binh cua lop va ghi vao tap tin.\n";
        cout<<"3. Them 1 sinh vien moi vao danh sach va cap nhat lai vao tap tin.\n";
        cout<<"4. In ra man hinh danh sach xep loai sinh vien (theo diem trung binh).\n";
        cout<<"5. In ra man hinh cac sinh vien co cung ngay sinh nhat trong ngay hien tai.\n";
        cout<<"6. Thoat chuong trinh.\n";
        cout<<"Vui long chon 1 option: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            
            qlysinhvien.XuatFile();
            break;
            case 2:
            qlysinhvien.XuatDTB();
            break;
            case 3:
            qlysinhvien.ThemSV();
            qlysinhvien.XuatFile();
            break;
            case 4:
            qlysinhvien.Ranking();
            break;
            case 5:
            qlysinhvien.Date();
            break;
            case 6:
            exit(1);
            break;
        }
    }
    return 0;
}

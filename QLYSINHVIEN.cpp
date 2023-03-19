#include "QLYSINHVIEN.h"

Qly_Sinhvien::Qly_Sinhvien()
: size(0)
, danhsach(nullptr)
{
}

Qly_Sinhvien::~Qly_Sinhvien(){
    delete[] danhsach;
}

void Qly_Sinhvien::DocFile(){

    std::ifstream myFile("input.txt");
    std::vector<std::string> lines; 
    std::string line;
    while(getline(myFile,line))
    {
        std::stringstream line_str(line);
        std::string val;
        while(getline(line_str,val,','))
            lines.push_back(val);
        size++;
    }
    delete[] danhsach;
    danhsach = new Sinhvien[size]();
    int k=-1;
    for (int i=0;i<lines.size();i++)
    {     
        if(i%6==0) k++;
        danhsach[k].NhapSV(lines[i],i%6);
    }
}

void Qly_Sinhvien::XuatFile()
{
    std::ofstream myFile;
    myFile.open("output.txt",std::ofstream::out | std::ofstream::trunc);
    myFile<<"-----------------------------------\n";
    myFile<<"Danh sach sinh vien nhap tu tap tin\n";
    myFile<<"-----------------------------------\n";
    myFile << "Ho ten | Ma so | Ngay sinh | Diem bai tap | Diem giua ky | Diem cuoi ky | Diem trung binh\n";
    for(int i=0;i<size;i++)
    {
        myFile << danhsach[i] <<" | "<<danhsach[i].dtb()<<endl;
    }
    myFile.close();
}

void Qly_Sinhvien::XuatDTB()
{   std::ofstream myFile;
    float dtb_lop=0;
    
    for(int i=0;i<size;i++)
        dtb_lop+=danhsach[i].dtb();

    dtb_lop/=size;
    myFile.open("output.txt",std::ofstream::out | std::ofstream::trunc);
    myFile<<"----------------------------------------------------------------------------\n";
    myFile<<"Danh sach cac sinh vien co diem trung binh thap hon diem trung binh cua lop:\n";
    myFile<<"----------------------------------------------------------------------------\n";
    for(int i=0;i<size;i++)
    {
        if(danhsach[i].dtb()<dtb_lop) myFile << danhsach[i]<<" | "<<danhsach[i].dtb()<<endl;
    }
    
}
void Qly_Sinhvien::ThemSV()
{
    Sinhvien sv_moi;
    string val;
    cout<<"Nhap ho ten cua sinh vien moi: ";
    getline(cin.ignore(),val);
    sv_moi.NhapSV(val,0);
    cout<<"Nhap ma so cua sinh vien moi: ";
    getline(cin,val);
    sv_moi.NhapSV(val,1);
    cout<<"Nhap ngay sinh cua sinh vien moi: ";
    getline(cin,val);
    sv_moi.NhapSV(val,2);
    cout<<"Nhap diem bai tap cua sinh vien moi: ";
    getline(cin,val);
    sv_moi.NhapSV(val,3);
    cout<<"Nhap diem giua ky cua sinh vien moi: ";
    getline(cin,val);
    sv_moi.NhapSV(val,4);
    cout<<"Nhap diem cuoi ky cua sinh vien moi: ";
    getline(cin,val);
    sv_moi.NhapSV(val,5);

    Sinhvien* tmp = new Sinhvien[size+1]();
    
    std::copy(danhsach, danhsach + size, tmp);
 
    delete[] danhsach;
    ++size;
    danhsach = tmp;
    danhsach[size-1] = sv_moi; 
    

}
void Qly_Sinhvien::Ranking()
{
    std::vector<Sinhvien> tmp;
    tmp.reserve(tmp.size()+size);
    std::copy(&danhsach[0],&danhsach[size],std::back_inserter(tmp));
    std::sort(tmp.begin(), tmp.end(), SortedMark());
    
    std::ofstream myFile;
    myFile.open("output.txt");
    myFile<<"----------------------------------\n";
    myFile << "Xep loai sinh vien: \n";
    myFile<<"----------------------------------\n";
    myFile << "Thu hang | Ten | Ma so | Ngay sinh | Diem bai tap | Diem giua ky | Diem cuoi ky | Diem trung binh\n"; 
    
    for (int i=0;i<tmp.size();i++)
    {
        myFile<< i+1 <<" | "<< tmp[i]<<" | "<<tmp[i].dtb()<<endl;
    }   
}

void Qly_Sinhvien::Date()
{
    time_t now = time(0);
    char* s = ctime(&now);
    string s1(s);
    std::ofstream myFile;
    myFile.open("output.txt");
    myFile << "------------------------------------------------------\n";
    myFile << "Sinh vien co cung ngay sinh nhat trong ngay hien tai: \n";
    myFile << "------------------------------------------------------\n";
    myFile << "Thu hang | Ten | Ma so | Ngay sinh | Diem bai tap | Diem giua ky | Diem cuoi ky | Diem trung binh\n";
    for (int i=0;i<size;i++)
    {
        if(atoi(danhsach[i].GetDate().c_str()) == atoi(s1.substr(8,s1.length()-1).c_str()))
            myFile<< danhsach[i]<<endl;
    }

}
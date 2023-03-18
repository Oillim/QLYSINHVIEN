#include "QLYSINHVIEN.h"

Qly_Sinhvien::Qly_Sinhvien(){
}

Qly_Sinhvien::~Qly_Sinhvien(){
}

void Qly_Sinhvien::DocFile(){

    std::ifstream myFile("input.txt");
    std::vector<std::vector<std::string>> lines; 
    std::string line;

    while(getline(myFile,line))
    {
        std::stringstream line_str(line);
        std::string value;
        std::vector<std::string> line_val;

        while(getline(line_str,value,','))
            line_val.push_back(value);
        lines.push_back(line_val);
    }
    for (int i=0;i<lines.size();i++)
    {
        for (int j=0;j<lines[i].size();j++)
        {
            
            danhsach[i].NhapSV(lines[i][j],j);
            cout<<lines[i][j]<<endl;
        }
    }
}
void Qly_Sinhvien::Print()
{
    for (int i=0;i<size;i++)
    danhsach[i].XuatSV();
}
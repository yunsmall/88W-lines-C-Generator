#include <iostream>
#include <fstream>
//#include "NumInfo.h"
#include "CodeGenerator.h"

using namespace std;

const string file_path="./hhh.cpp";



int main(){
    ofstream out_file{file_path};

    CodeGenerator generator{100000};
    cout<<"准备生成hhh.cpp文件"<<endl;
    generator.writeToStream(out_file);
    out_file.flush();

    return 0;    
}
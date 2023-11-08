//
// Created by yunsmall on 23-11-3.
//

#include "CodeGenerator.h"
#include "NumInfo.h"
#include <sstream>
#include <fmt/format.h>

using namespace std;

const std::string CodeGenerator::beginWord=R"(
#include <iostream>

using namespace std;

int main(){
    int i;
    cout<<"你想查哪个数？"<<endl;
    cin>>i;
    switch(i){
)";

const std::string CodeGenerator::endWord=R"(
    default:
        cout<<"超出可找范围"<<endl;
    }
    return 0;
}
)";

constexpr string_view CodeGenerator::caseString=R"(
    case {0}:
        cout<<"{0}{1}偶数"<<endl;
        cout<<"{0}有{2}位数字"<<endl;
        cout<<"{0}{3}3的倍数"<<endl;
        cout<<"{0}{4}5的倍数"<<endl;
        break;)";

//const auto CodeGenerator::fmtStr=FMT_CO

CodeGenerator::CodeGenerator(uint32_t max_gen_num):m_max_num(max_gen_num){};

CodeGenerator::~CodeGenerator(){};

void CodeGenerator::writeToStream(std::ostream& out){
    out<<getBeginWord();

//    string casestr_copy=caseString;

    for(uint32_t i=0;i<this->m_max_num;i++) {
        out << genSwitchCase(i);
    }
    out<<getEndWord();
}

std::string CodeGenerator::genSwitchCase(uint32_t current_num){
//    string casestr_copy{caseString.c_str()};
    return fmt::format(caseString,
                       current_num,
                       getYesNo(NumInfo::isEven(current_num)),
                       NumInfo::getLen(current_num),
                       getYesNo(NumInfo::isTimedBy3(current_num)),
                       getYesNo(NumInfo::isTimedBy5(current_num))
    );

}


const std::string& CodeGenerator::getBeginWord(){
    return beginWord;
}

const std::string& CodeGenerator::getEndWord(){
    return endWord;
}

std::string CodeGenerator::getYesNo(bool yesno) {
    return yesno?"是":"不是";
}

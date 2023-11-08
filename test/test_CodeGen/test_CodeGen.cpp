#include <gtest/gtest.h>
#include <iostream>
#include <string>
//#define private public
//#define protected public
#include "CodeGenerator.h"
//#undef private
//#undef protected

class CodeGenTest: public testing::Test{
protected:
    std::string genSwitchCase(uint32_t current_num){
       return codeGenerator.genSwitchCase(current_num);
    }

    std::string getYesNo(bool yesno){
        return codeGenerator.getYesNo(yesno);
    }
    CodeGenerator codeGenerator{10000};
};

TEST_F(CodeGenTest,SwitchCase){
    EXPECT_EQ(R"(
    case 2000:
        cout<<"2000是偶数"<<endl;
        cout<<"2000有4位数字"<<endl;
        cout<<"2000不是3的倍数"<<endl;
        cout<<"2000是5的倍数"<<endl;
        break;)",genSwitchCase(2000));
    EXPECT_EQ(R"(
    case 1524:
        cout<<"1524是偶数"<<endl;
        cout<<"1524有4位数字"<<endl;
        cout<<"1524是3的倍数"<<endl;
        cout<<"1524不是5的倍数"<<endl;
        break;)",genSwitchCase(1524));

    EXPECT_EQ(R"(
    case 16589:
        cout<<"16589不是偶数"<<endl;
        cout<<"16589有5位数字"<<endl;
        cout<<"16589不是3的倍数"<<endl;
        cout<<"16589不是5的倍数"<<endl;
        break;)",genSwitchCase(16589));
}

TEST_F(CodeGenTest,YesNo){
    using namespace std;
    string yes="是";
    string no="不是";


    EXPECT_EQ(yes, getYesNo(true));
    EXPECT_EQ(no, getYesNo(false));

}

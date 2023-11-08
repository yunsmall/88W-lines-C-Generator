//
// Created by yunsmall on 23-11-3.
//

#ifndef TEST_CODEGENERATOR_H
#define TEST_CODEGENERATOR_H


#include <string>
#include <ostream>
#include <fmt/core.h>


class CodeGenerator {
    friend class CodeGenTest;
public:
    explicit CodeGenerator(uint32_t max_gen_num);
    virtual ~CodeGenerator();

    void writeToStream(std::ostream& out);

private:
    uint32_t m_max_num;
    const std::string& getBeginWord();
    const std::string& getEndWord();
    static const std::string beginWord;
    static const std::string endWord;

    static const std::string_view caseString;
    std::string genSwitchCase(uint32_t current_num);
    std::string getYesNo(bool yesno);
};


#endif //TEST_CODEGENERATOR_H

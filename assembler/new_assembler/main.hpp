#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#define OFFSET 0x4000

struct Instruction {
    std::string name;
    uint8_t opcode;
    std::string addr_mode;
};

enum TokenType {
    // Whitespace
    WHITESPACE, NEWLINE,

    // Preproccess
    PREPROCESS, INCLUDE, ARGUEMENT,

    // Single-Character Tokens
    PAREN, COMMA,

    // Literals
    IDENTIFIER_DECLARE, IDENTIFIER, LABEL_DECLARE, LABEL_USED, STRING, CHAR, NUMBER, REG, IMMEDIATE, BINARY, HEX, EQUAL, NEGATIVE,

    // Keywords
    INSTRUCTION,
};    

struct Token {
    TokenType        type;
    std::string      substring;
};

struct ParsedInstruction {
    Instruction instr;
    int argumentValue;
    std::string label_val = "";
    int address = 0;
};

struct Labels {
    std::string name;
    int address;
};

struct Vars {
    std::string name;
    int val;
};

std::string toLowerCase(const std::string& input);
std::string toUpperCase(const std::string& input);

class Lexer {
private:
    const std::vector<Instruction> m_instructionSet;
    std::string m_sourceFilePath;
    Token m_currToken;

    std::string m_get_contents();
    std::string m_removeComments();
    bool m_isLabel();
    std::string m_getInstr_String();

public:
    Lexer(const std::string& sourcePath, const std::vector<Instruction>& instructionSet);

    std::vector<Token> tokenList;    

    void tokenize();
    void print();
};

class Parse {
private:
    std::vector<ParsedInstruction>& m_parsedList;
    Lexer m_lexer;

public:
    Parse(Lexer lexer);

};

class Assembler {
private:
    static const std::vector<Instruction> m_instructionSet;

    const std::string m_sourceFilePath;
    const std::string m_outputFilePath;

public:
    Assembler(const std::string& sourcePath, const std::string& outputPath);

    void assemble();

};

inline std::vector<Instruction> createInstructionSet() {
    std::vector<Instruction> instructionSet;
    instructionSet.push_back({"NOP", 0, "implied"});
    instructionSet.push_back({"ADC", 1, "immediate"});
    instructionSet.push_back({"ADC", 2, "zeropage"});
    instructionSet.push_back({"ADC", 3, "zeropage,X"});
    instructionSet.push_back({"ADC", 4, "zeropage,Y"});
    instructionSet.push_back({"ADC", 5, "absolute"});
    instructionSet.push_back({"ADC", 6, "absolute,X"});
    instructionSet.push_back({"ADC", 7, "absolute,Y"});
    instructionSet.push_back({"ADC", 8, "(indirect,X)"});
    instructionSet.push_back({"ADC", 9, "(indirect,Y)"});
    instructionSet.push_back({"ADC", 10, "(indirect),X"});
    instructionSet.push_back({"ADC", 11, "(indirect),Y"});
    instructionSet.push_back({"AND", 12, "immediate"});
    instructionSet.push_back({"AND", 13, "zeropage"});
    instructionSet.push_back({"AND", 14, "zeropage,X"});
    instructionSet.push_back({"AND", 15, "zeropage,Y"});
    instructionSet.push_back({"AND", 16, "absolute"});
    instructionSet.push_back({"AND", 17, "absolute,X"});
    instructionSet.push_back({"AND", 18, "absolute,Y"});
    instructionSet.push_back({"AND", 19, "(indirect,X)"});
    instructionSet.push_back({"AND", 20, "(indirect,Y)"});
    instructionSet.push_back({"AND", 21, "(indirect),X"});
    instructionSet.push_back({"AND", 22, "(indirect),Y"});
    instructionSet.push_back({"ASL", 23, "implied"});
    instructionSet.push_back({"ASL", 24, "zeropage"});
    instructionSet.push_back({"ASL", 25, "zeropage,X"});
    instructionSet.push_back({"ASL", 26, "zeropage,Y"});
    instructionSet.push_back({"ASL", 27, "absolute"});
    instructionSet.push_back({"ASL", 28, "absolute,X"});
    instructionSet.push_back({"ASL", 29, "absolute,Y"});
    instructionSet.push_back({"BCC", 30, "absolute"});
    instructionSet.push_back({"BCS", 31, "absolute"});
    instructionSet.push_back({"BEQ", 32, "absolute"});
    instructionSet.push_back({"BIT", 33, "zeropage"});
    instructionSet.push_back({"BIT", 34, "absolute"});
    instructionSet.push_back({"BMI", 35, "absolute"});
    instructionSet.push_back({"BNE", 36, "absolute"});
    instructionSet.push_back({"BPL", 37, "absolute"});
    instructionSet.push_back({"BRK", 38, "implied"});
    instructionSet.push_back({"BVC", 39, "absolute"});
    instructionSet.push_back({"BVS", 40, "absolute"});
    instructionSet.push_back({"CLC", 41, "implied"});
    instructionSet.push_back({"CLI", 42, "implied"});
    instructionSet.push_back({"CLV", 43, "implied"});
    instructionSet.push_back({"CMP", 44, "immediate"});
    instructionSet.push_back({"CMP", 45, "zeropage"});
    instructionSet.push_back({"CMP", 46, "zeropage,X"});
    instructionSet.push_back({"CMP", 47, "zeropage,Y"});
    instructionSet.push_back({"CMP", 48, "absolute"});
    instructionSet.push_back({"CMP", 49, "absolute,X"});
    instructionSet.push_back({"CMP", 50, "absolute,Y"});
    instructionSet.push_back({"CMP", 51, "(indirect,X)"});
    instructionSet.push_back({"CMP", 52, "(indirect,Y)"});
    instructionSet.push_back({"CMP", 53, "(indirect),X"});
    instructionSet.push_back({"CMP", 54, "(indirect),Y"});
    instructionSet.push_back({"CPX", 55, "immediate"});
    instructionSet.push_back({"CPX", 56, "zeropage"});
    instructionSet.push_back({"CPX", 57, "absolute"});
    instructionSet.push_back({"CPY", 58, "immediate"});
    instructionSet.push_back({"CPY", 59, "zeropage"});
    instructionSet.push_back({"CPY", 60, "absolute"});
    instructionSet.push_back({"DEC", 61, "zeropage"});
    instructionSet.push_back({"DEC", 62, "zeropage,X"});
    instructionSet.push_back({"DEC", 63, "zeropage,Y"});
    instructionSet.push_back({"DEC", 64, "absolute"});
    instructionSet.push_back({"DEC", 65, "absolute,X"});
    instructionSet.push_back({"DEC", 66, "absolute,Y"});
    instructionSet.push_back({"DEX", 67, "implied"});
    instructionSet.push_back({"DEY", 68, "implied"});
    instructionSet.push_back({"EOR", 69, "immediate"});
    instructionSet.push_back({"EOR", 70, "zeropage"});
    instructionSet.push_back({"EOR", 71, "zeropage,X"});
    instructionSet.push_back({"EOR", 72, "zeropage,Y"});
    instructionSet.push_back({"EOR", 73, "absolute"});
    instructionSet.push_back({"EOR", 74, "absolute,X"});
    instructionSet.push_back({"EOR", 75, "absolute,Y"});
    instructionSet.push_back({"EOR", 76, "(indirect,X)"});
    instructionSet.push_back({"EOR", 77, "(indirect,Y)"});
    instructionSet.push_back({"EOR", 78, "(indirect),X"});
    instructionSet.push_back({"EOR", 79, "(indirect),Y"});
    instructionSet.push_back({"INC", 80, "zeropage"});
    instructionSet.push_back({"INC", 81, "zeropage,X"});
    instructionSet.push_back({"INC", 82, "zeropage,Y"});
    instructionSet.push_back({"INC", 83, "absolute"});
    instructionSet.push_back({"INC", 84, "absolute,X"});
    instructionSet.push_back({"INC", 85, "absolute,Y"});
    instructionSet.push_back({"INX", 86, "implied"});
    instructionSet.push_back({"INY", 87, "implied"});
    instructionSet.push_back({"JMP", 88, "absolute"});
    instructionSet.push_back({"JMP", 89, "(indirect)"});
    instructionSet.push_back({"JSR", 90, "absolute"});
    instructionSet.push_back({"LDA", 91, "immediate"});
    instructionSet.push_back({"LDA", 92, "zeropage"});
    instructionSet.push_back({"LDA", 93, "zeropage,X"});
    instructionSet.push_back({"LDA", 94, "zeropage,Y"});
    instructionSet.push_back({"LDA", 95, "absolute"});
    instructionSet.push_back({"LDA", 96, "absolute,X"});
    instructionSet.push_back({"LDA", 97, "absolute,Y"});
    instructionSet.push_back({"LDA", 98, "(indirect,X)"});
    instructionSet.push_back({"LDA", 99, "(indirect,Y)"});
    instructionSet.push_back({"LDA", 100, "(indirect),X"});
    instructionSet.push_back({"LDA", 101, "(indirect),Y"});
    instructionSet.push_back({"LDX", 102, "immediate"});
    instructionSet.push_back({"LDX", 103, "zeropage"});
    instructionSet.push_back({"LDX", 104, "zeropage,Y"});
    instructionSet.push_back({"LDX", 105, "absolute"});
    instructionSet.push_back({"LDX", 106, "absolute,Y"});
    instructionSet.push_back({"LDY", 107, "immediate"});
    instructionSet.push_back({"LDY", 108, "zeropage"});
    instructionSet.push_back({"LDY", 109, "zeropage,X"});
    instructionSet.push_back({"LDY", 110, "absolute"});
    instructionSet.push_back({"LDY", 111, "absolute,X"});
    instructionSet.push_back({"LSR", 112, "implied"});
    instructionSet.push_back({"LSR", 113, "zeropage"});
    instructionSet.push_back({"LSR", 114, "zeropage,X"});
    instructionSet.push_back({"LSR", 115, "zeropage,Y"});
    instructionSet.push_back({"LSR", 116, "absolute"});
    instructionSet.push_back({"LSR", 117, "absolute,X"});
    instructionSet.push_back({"LSR", 118, "absolute,Y"});
    instructionSet.push_back({"ORA", 119, "immediate"});
    instructionSet.push_back({"ORA", 120, "zeropage"});
    instructionSet.push_back({"ORA", 121, "zeropage,X"});
    instructionSet.push_back({"ORA", 122, "zeropage,Y"});
    instructionSet.push_back({"ORA", 123, "absolute"});
    instructionSet.push_back({"ORA", 124, "absolute,X"});
    instructionSet.push_back({"ORA", 125, "absolute,Y"});
    instructionSet.push_back({"ORA", 126, "(indirect,X)"});
    instructionSet.push_back({"ORA", 127, "(indirect,Y)"});
    instructionSet.push_back({"ORA", 128, "(indirect),X"});
    instructionSet.push_back({"ORA", 129, "(indirect),Y"});
    instructionSet.push_back({"PHA", 130, "implied"});
    instructionSet.push_back({"PHP", 131, "implied"});
    instructionSet.push_back({"PLA", 132, "implied"});
    instructionSet.push_back({"PLP", 133, "implied"});
    instructionSet.push_back({"ROL", 134, "implied"});
    instructionSet.push_back({"ROL", 135, "zeropage"});
    instructionSet.push_back({"ROL", 136, "zeropage,X"});
    instructionSet.push_back({"ROL", 137, "zeropage,Y"});
    instructionSet.push_back({"ROL", 138, "absolute"});
    instructionSet.push_back({"ROL", 139, "absolute,X"});
    instructionSet.push_back({"ROL", 140, "zeropage,Y"});
    instructionSet.push_back({"ROR", 141, "implied"});
    instructionSet.push_back({"ROR", 142, "zeropage"});
    instructionSet.push_back({"ROR", 143, "zeropage,X"});
    instructionSet.push_back({"ROR", 144, "zeropage,Y"});
    instructionSet.push_back({"ROR", 145, "absolute"});
    instructionSet.push_back({"ROR", 146, "absolute,X"});
    instructionSet.push_back({"ROR", 147, "zeropage,Y"});
    instructionSet.push_back({"RTI", 148, "implied"});
    instructionSet.push_back({"RTS", 149, "implied"});
    instructionSet.push_back({"SUB", 150, "immediate"});
    instructionSet.push_back({"SUB", 151, "zeropage"});
    instructionSet.push_back({"SUB", 152, "zeropage,X"});
    instructionSet.push_back({"SUB", 153, "zeropage,Y"});
    instructionSet.push_back({"SUB", 154, "absolute"});
    instructionSet.push_back({"SUB", 155, "absolute,X"});
    instructionSet.push_back({"SUB", 156, "absolute,Y"});
    instructionSet.push_back({"SUB", 157, "(indirect,X)"});
    instructionSet.push_back({"SUB", 158, "(indirect,Y)"});
    instructionSet.push_back({"SUB", 159, "(indirect),X"});
    instructionSet.push_back({"SUB", 160, "(indirect),Y"});
    instructionSet.push_back({"SEC", 161, "implied"});
    instructionSet.push_back({"SEI", 162, "implied"});
    instructionSet.push_back({"STA", 163, "zeropage"});
    instructionSet.push_back({"STA", 164, "zeropage,X"});
    instructionSet.push_back({"STA", 165, "zeropage,Y"});
    instructionSet.push_back({"STA", 166, "absolute"});
    instructionSet.push_back({"STA", 167, "absolute,X"});
    instructionSet.push_back({"STA", 168, "absolute,Y"});
    instructionSet.push_back({"STA", 169, "(indirect,X)"});
    instructionSet.push_back({"STA", 170, "(indirect,Y)"});
    instructionSet.push_back({"STA", 171, "(indirect),X"});
    instructionSet.push_back({"STA", 172, "(indirect),Y"});
    instructionSet.push_back({"STX", 173, "zeropage"});
    instructionSet.push_back({"STX", 174, "zeropage,Y"});
    instructionSet.push_back({"STX", 175, "absolute"});
    instructionSet.push_back({"STX", 176, "absolute,Y"});
    instructionSet.push_back({"STY", 177, "zeropage"});
    instructionSet.push_back({"STY", 178, "zeropage,X"});
    instructionSet.push_back({"STY", 179, "absolute"});
    instructionSet.push_back({"STY", 180, "absolute,X"});
    instructionSet.push_back({"TAX", 181, "implied"});
    instructionSet.push_back({"TAY", 182, "implied"});
    instructionSet.push_back({"TSX", 183, "implied"});
    instructionSet.push_back({"TSA", 184, "implied"});
    instructionSet.push_back({"TXS", 185, "implied"});
    instructionSet.push_back({"TYA", 186, "implied"});
    instructionSet.push_back({"HLT", 187, "implied"});
    instructionSet.push_back({"OUT", 188, "implied"});
    return instructionSet;
}

#endif
#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include "main.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "preprocessor.hpp"

class Assembler {
public:
    Assembler(const std::string& sourcePath, const std::string& outputPath);

    void assemble();

private:
    static const std::vector<Instruction> _instructionSet;

    const std::string _sourceFilePath;
    const std::string _outputFilePath;
};

inline std::vector<Instruction> createInstructionSet() {
    std::vector<Instruction> instructionSet;
    instructionSet.push_back({"nop", 0, "implied"});
    instructionSet.push_back({"adc", 1, "immediate"});
    instructionSet.push_back({"adc", 2, "zeropage"});
    instructionSet.push_back({"adc", 3, "zeropage,X"});
    instructionSet.push_back({"adc", 4, "zeropage,Y"});
    instructionSet.push_back({"adc", 5, "absolute"});
    instructionSet.push_back({"adc", 6, "absolute,X"});
    instructionSet.push_back({"adc", 7, "absolute,Y"});
    instructionSet.push_back({"adc", 8, "(indirect,X)"});
    instructionSet.push_back({"adc", 9, "(indirect,Y)"});
    instructionSet.push_back({"adc", 10, "(indirect),X"});
    instructionSet.push_back({"adc", 11, "(indirect),Y"});
    instructionSet.push_back({"and", 12, "immediate"});
    instructionSet.push_back({"and", 13, "zeropage"});
    instructionSet.push_back({"and", 14, "zeropage,X"});
    instructionSet.push_back({"and", 15, "zeropage,Y"});
    instructionSet.push_back({"and", 16, "absolute"});
    instructionSet.push_back({"and", 17, "absolute,X "});
    instructionSet.push_back({"and", 18, "absolute,Y"});
    instructionSet.push_back({"and", 19, "(indirect,X)"});
    instructionSet.push_back({"and", 20, "(indirect,Y)"});
    instructionSet.push_back({"and", 21, "(indirect),X"});
    instructionSet.push_back({"and", 22, "(indirect),Y"});
    instructionSet.push_back({"asl", 23, "implied"});
    instructionSet.push_back({"asl", 24, "zeropage"});
    instructionSet.push_back({"asl", 25, "zeropage,X"});
    instructionSet.push_back({"asl", 26, "zeropage,Y"});
    instructionSet.push_back({"asl", 27, "absolute"});
    instructionSet.push_back({"asl", 28, "absolute,X"});
    instructionSet.push_back({"asl", 29, "absolute,Y"});
    instructionSet.push_back({"bcc", 30, "absolute"});
    instructionSet.push_back({"bcs", 31, "absolute"});
    instructionSet.push_back({"beq", 32, "absolute"});
    instructionSet.push_back({"bit", 33, "zeropage"});
    instructionSet.push_back({"bit", 34, "absolute"});
    instructionSet.push_back({"bmi", 35, "absolute"});
    instructionSet.push_back({"bne", 36, "absolute"});
    instructionSet.push_back({"bpl", 37, "absolute"});
    instructionSet.push_back({"brk", 38, "implied"});
    instructionSet.push_back({"bvc", 39, "absolute"});
    instructionSet.push_back({"bvs", 40, "absolute"});
    instructionSet.push_back({"clc", 41, "implied"});
    instructionSet.push_back({"cli", 42, "implied"});
    instructionSet.push_back({"clv", 43, "implied"});
    instructionSet.push_back({"cmp", 44, "immediate"});
    instructionSet.push_back({"cmp", 45, "zeropage"});
    instructionSet.push_back({"cmp", 46, "zeropage,X"});
    instructionSet.push_back({"cmp", 47, "zeropage,Y"});
    instructionSet.push_back({"cmp", 48, "absolute"});
    instructionSet.push_back({"cmp", 49, "absolute,X"});
    instructionSet.push_back({"cmp", 50, "absolute,Y"});
    instructionSet.push_back({"cmp", 51, "(indirect,X)"});
    instructionSet.push_back({"cmp", 52, "(indirect,Y)"});
    instructionSet.push_back({"cmp", 53, "(indirect),X"});
    instructionSet.push_back({"cmp", 54, "(indirect),Y"});
    instructionSet.push_back({"cpx", 55, "immediate"});
    instructionSet.push_back({"cpx", 56, "zeropage"});
    instructionSet.push_back({"cpx", 57, "absolute"});
    instructionSet.push_back({"cpy", 58, "immediate"});
    instructionSet.push_back({"cpy", 59, "zeropage"});
    instructionSet.push_back({"cpy", 60, "absolute"});
    instructionSet.push_back({"dec", 61, "zeropage"});
    instructionSet.push_back({"dec", 62, "zeropage,X"});
    instructionSet.push_back({"dec", 63, "zeropage,Y"});
    instructionSet.push_back({"dec", 64, "absolute"});
    instructionSet.push_back({"dec", 65, "absolute,X"});
    instructionSet.push_back({"dec", 66, "absolute,Y"});
    instructionSet.push_back({"dex", 67, "implied"});
    instructionSet.push_back({"dey", 68, "implied"});
    instructionSet.push_back({"eor", 69, "immediate"});
    instructionSet.push_back({"eor", 70, "zeropage"});
    instructionSet.push_back({"eor", 71, "zeropage,X"});
    instructionSet.push_back({"eor", 72, "zeropage,Y"});
    instructionSet.push_back({"eor", 73, "absolute"});
    instructionSet.push_back({"eor", 74, "absolute,X"});
    instructionSet.push_back({"eor", 75, "absolute,Y"});
    instructionSet.push_back({"eor", 76, "(indirect,X)"});
    instructionSet.push_back({"eor", 77, "(indirect,Y)"});
    instructionSet.push_back({"eor", 78, "(indirect),X"});
    instructionSet.push_back({"eor", 79, "(indirect),Y"});
    instructionSet.push_back({"inc", 80, "zeropage"});
    instructionSet.push_back({"inc", 81, "zeropage,X"});
    instructionSet.push_back({"inc", 82, "zeropage,Y"});
    instructionSet.push_back({"inc", 83, "absolute"});
    instructionSet.push_back({"inc", 84, "absolute,X"});
    instructionSet.push_back({"inc", 85, "absolute,Y"});
    instructionSet.push_back({"inx", 86, "implied"});
    instructionSet.push_back({"iny", 87, "implied"});
    instructionSet.push_back({"jmp", 88, "absolute"});
    instructionSet.push_back({"jmp", 89, "(indirect)"});
    instructionSet.push_back({"jsr", 90, "absolute"});
    instructionSet.push_back({"lda", 91, "immediate"});
    instructionSet.push_back({"lda", 92, "zeropage"});
    instructionSet.push_back({"lda", 93, "zeropage,X"});
    instructionSet.push_back({"lda", 94, "zeropage,Y"});
    instructionSet.push_back({"lda", 95, "absolute"});
    instructionSet.push_back({"lda", 96, "absolute,X"});
    instructionSet.push_back({"lda", 97, "absolute,Y"});
    instructionSet.push_back({"lda", 98, "(indirect,X)"});
    instructionSet.push_back({"lda", 99, "(indirect,Y)"});
    instructionSet.push_back({"lda", 100, "(indirect),X"});
    instructionSet.push_back({"lda", 101, "(indirect),Y"});
    instructionSet.push_back({"ldx", 102, "immediate"});
    instructionSet.push_back({"ldx", 103, "zeropage"});
    instructionSet.push_back({"ldx", 104, "zeropage,Y"});
    instructionSet.push_back({"ldx", 105, "absolute"});
    instructionSet.push_back({"ldx", 106, "absolute,Y"});
    instructionSet.push_back({"ldy", 107, "immediate"});
    instructionSet.push_back({"ldy", 108, "zeropage"});
    instructionSet.push_back({"ldy", 109, "zeropage,X"});
    instructionSet.push_back({"ldy", 110, "absolute"});
    instructionSet.push_back({"ldy", 111, "absolute,X"});
    instructionSet.push_back({"lsr", 112, "implied"});
    instructionSet.push_back({"lsr", 113, "zeropage"});
    instructionSet.push_back({"lsr", 114, "zeropage,X"});
    instructionSet.push_back({"lsr", 115, "zeropage,Y"});
    instructionSet.push_back({"lsr", 116, "absolute"});
    instructionSet.push_back({"lsr", 117, "absolute,X"});
    instructionSet.push_back({"lsr", 118, "absolute,Y"});
    instructionSet.push_back({"ora", 119, "immediate"});
    instructionSet.push_back({"ora", 120, "zeropage"});
    instructionSet.push_back({"ora", 121, "zeropage,X"});
    instructionSet.push_back({"ora", 122, "zeropage,Y"});
    instructionSet.push_back({"ora", 123, "absolute"});
    instructionSet.push_back({"ora", 124, "absolute,X"});
    instructionSet.push_back({"ora", 125, "absolute,Y"});
    instructionSet.push_back({"ora", 126, "(indirect,X)"});
    instructionSet.push_back({"ora", 127, "(indirect,Y)"});
    instructionSet.push_back({"ora", 128, "(indirect),X"});
    instructionSet.push_back({"ora", 129, "(indirect),Y"});
    instructionSet.push_back({"pha", 130, "implied"});
    instructionSet.push_back({"php", 131, "implied"});
    instructionSet.push_back({"pla", 132, "implied"});
    instructionSet.push_back({"plp", 133, "implied"});
    instructionSet.push_back({"rol", 134, "implied"});
    instructionSet.push_back({"rol", 135, "zeropage"});
    instructionSet.push_back({"rol", 136, "zeropage,X"});
    instructionSet.push_back({"rol", 137, "zeropage,Y"});
    instructionSet.push_back({"rol", 138, "absolute"});
    instructionSet.push_back({"rol", 139, "absolute,X"});
    instructionSet.push_back({"rol", 140, "zeropage,Y"});
    instructionSet.push_back({"ror", 141, "implied"});
    instructionSet.push_back({"ror", 142, "zeropage"});
    instructionSet.push_back({"ror", 143, "zeropage,X"});
    instructionSet.push_back({"ror", 144, "zeropage,Y"});
    instructionSet.push_back({"ror", 145, "absolute"});
    instructionSet.push_back({"ror", 146, "absolute,X"});
    instructionSet.push_back({"ror", 147, "zeropage,Y"});
    instructionSet.push_back({"rti", 148, "implied"});
    instructionSet.push_back({"rts", 149, "implied"});
    instructionSet.push_back({"sub", 150, "immediate"});
    instructionSet.push_back({"sub", 151, "zeropage"});
    instructionSet.push_back({"sub", 152, "zeropage,X"});
    instructionSet.push_back({"sub", 153, "zeropage,Y"});
    instructionSet.push_back({"sub", 154, "absolute"});
    instructionSet.push_back({"sub", 155, "absolute,X"});
    instructionSet.push_back({"sub", 156, "absolute,Y"});
    instructionSet.push_back({"sub", 157, "(indirect,X)"});
    instructionSet.push_back({"sub", 158, "(indirect,Y)"});
    instructionSet.push_back({"sub", 159, "(indirect),X"});
    instructionSet.push_back({"sub", 160, "(indirect),Y"});
    instructionSet.push_back({"sec", 161, "implied"});
    instructionSet.push_back({"sei", 162, "implied"});
    instructionSet.push_back({"sta", 163, "zeropage"});
    instructionSet.push_back({"sta", 164, "zeropage,X"});
    instructionSet.push_back({"sta", 165, "zeropage,Y"});
    instructionSet.push_back({"sta", 166, "absolute"});
    instructionSet.push_back({"sta", 167, "absolute,X"});
    instructionSet.push_back({"sta", 168, "absolute,Y"});
    instructionSet.push_back({"sta", 169, "(indirect,X)"});
    instructionSet.push_back({"sta", 170, "(indirect,Y)"});
    instructionSet.push_back({"sta", 171, "(indirect),X"});
    instructionSet.push_back({"sta", 172, "(indirect),Y"});
    instructionSet.push_back({"stx", 173, "zeropage"});
    instructionSet.push_back({"stx", 174, "zeropage,Y"});
    instructionSet.push_back({"stx", 175, "absolute"});
    instructionSet.push_back({"stx", 176, "absolute,Y"});
    instructionSet.push_back({"sty", 177, "zeropage"});
    instructionSet.push_back({"sty", 178, "zeropage,X"});
    instructionSet.push_back({"sty", 179, "absolute"});
    instructionSet.push_back({"sty", 180, "absolute,X"});
    instructionSet.push_back({"tax", 181, "implied"});
    instructionSet.push_back({"tay", 182, "implied"});
    instructionSet.push_back({"tsx", 183, "implied"});
    instructionSet.push_back({"tsa", 184, "implied"});
    instructionSet.push_back({"txs", 185, "implied"});
    instructionSet.push_back({"tya", 186, "implied"});
    instructionSet.push_back({"hlt", 187, "implied"});
    instructionSet.push_back({"out", 188, "implied"});
    return instructionSet;
}

#endif
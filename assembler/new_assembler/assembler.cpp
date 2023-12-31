#include "assembler.hpp"

const std::vector<Instruction> Assembler::_instructionSet = createInstructionSet();

Assembler::Assembler(const std::string &sourcePath, const std::string &outputPath)
    : _sourceFilePath(sourcePath), _outputFilePath(outputPath) {
}

void Assembler::assemble() {

    Preprocessor preprocessor;
    std::string sourceCode;

    preprocessor.processFile(_sourceFilePath, sourceCode);

    Lexer lexer(sourceCode, _instructionSet);

    lexer.tokenize();
    lexer.print();

    Parser parser(lexer, _instructionSet);
    parser.parseProgram();
    parser.printAST();

}

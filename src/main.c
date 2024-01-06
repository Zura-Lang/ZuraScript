#include "include/visitor.h"
#include "include/parser.h"
#include "include/lexer.h"
#include "include/AST.h"
#include "include/io.h"

#include <stdio.h>

void print_help() {

    printf("\nUsage: program.out <filename>\n");
    exit(1);

}

int main(int argc, char* argv[]) {

    if (argc < 2) {

        print_help();

    }

    lexer_T* lexer = init_lexer (
        get_file_conetents(argv[1])
    );

    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser, parser->scope);
    printf("Parsed successfully\n");

    // print out the AST
    printf("AST:\n");
    printAST(root, 0);

    printf("Running visitor\n");
    visitor_T* visitor = init_visitor();
    visitor_visit(visitor, root);

    return 0;
}


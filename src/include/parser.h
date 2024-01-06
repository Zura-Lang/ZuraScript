#ifndef PARSER_H
#define PARSER_H

#include "AST.h"
#include "lexer.h"
#include "scope.h"

typedef struct PARSER_STRUCT {
    lexer_T* lexer;
    token_T* current_token;
    token_T* prev_token;
    scope_T* scope;
} parser_T;

void parser_eat(parser_T* parser, int token_type);

parser_T* init_parser(lexer_T* lexer);

AST_T* parser_parse_function_definition(parser_T* parser, scope_T* scope);
AST_T* parser_parse_variable_definition(parser_T* parser, scope_T* scope);
AST_T* parser_parse_function_call(parser_T* parser, scope_T* scope);
AST_T* parser_parse_statements(parser_T* parser, scope_T* scope);
AST_T* parser_parse_statement(parser_T* parser, scope_T* scope);
AST_T* parser_parse_variable(parser_T* parser, scope_T* scope);
AST_T* parser_parse_string(parser_T* parser, scope_T* scope);
AST_T* parser_parse_factor(parser_T* paser, scope_T* scope);
AST_T* parser_parse_expr(parser_T* parser, scope_T* scope);
AST_T* parser_parse_term(parser_T* parser, scope_T* scope);
AST_T* parser_parse_id(parser_T* parser, scope_T* scope);
AST_T* parser_parse(parser_T* parser, scope_T* scope);

struct keywordMap {
    char* keyword;
    AST_T* (*func)(parser_T*, scope_T*);
};

struct keywordMap keywordMapLookUp[] = {
    {"var", parser_parse_variable_definition},
    {"function", parser_parse_function_definition},
};

#endif
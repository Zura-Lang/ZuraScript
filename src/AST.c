#include "include/AST.h"

#include <stdio.h>

AST_T* init_ast(int type) {

    AST_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;

    ast->scope = (void*)0;

    ast->variable_definition_variable_name = (void*)0;

    ast->variable_definition_value = (void*)0;

    // AST_FUNCTION_DEFINITION
    ast->function_definition_body = (void*)0;
    ast->function_definition_name = (void*)0;

    // AST_VARIABLE
    ast->variable_name = (void*)0;
    
    // AST_FUNCTION_CALL
    ast->function_call_name = (void*)0;
    ast->function_call_arguments = (void*)0;
    ast->function_call_arguments_size = 0;

    // AST STRING
    ast->string_value = (void*)0;

    // AST_COMPOUND
    ast->compound_value = (void*)0;
    ast->compound_size = 0;

    return ast;
}

AST_T *printAST(AST_T *node, int depth) {
    if (node == NULL) {
        return NULL;
    }
    switch (node->type) {
        case AST_VARIABLE_DEFINITION:
            printf("%*sVariable definition: %s\n", depth * 4, "", node->variable_definition_variable_name);
            printAST(node->variable_definition_value, depth + 1);
            break;
        case AST_FUNCTION_DEFINITION:
            printf("%*sFunction definition: %s\n", depth * 4, "", node->function_definition_name);
            printAST(node->function_definition_body, depth + 1);
            break;
        case AST_VARIABLE:
            printf("%*sVariable: %s\n", depth * 4, "", node->variable_name);
            break;
        case AST_FUNCTION_CALL:
            printf("%*sFunction call: %s\n", depth * 4, "", node->function_call_name);
            for (int i = 0; i < node->function_call_arguments_size; i++) {
                printAST(node->function_call_arguments[i], depth + 1);
            }
            break;
        case AST_STRING:
            printf("%*sString: %s\n", depth * 4, "", node->string_value);
            break;
        case AST_COMPOUND:
            printf("%*sCompound statement:\n", depth * 4, "");
            for (int i = 0; i < node->compound_size; i++) {
                printAST(node->compound_value[i], depth + 1);
            }
            break;
        case AST_NOOP:
            printf("%*sNo operation\n", depth * 4, "");
            break;
    }
    return node;
}


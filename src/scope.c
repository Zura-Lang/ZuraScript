#include "include/scope.h"
#include <stdio.h>

scope_T* init_scope() {

    scope_T* scope = calloc(1, sizeof(struct SCOPE_STRUCT));
    scope->function_definitions = (void*)0;
    scope->function_definitions_size = 0;

    return scope;

}

AST_T* scope_add_function_definition(scope_T* scope, AST_T* fdef) {
    printf("Adding function definition `%s` to scope\n", fdef->function_definition_name);
    scope->function_definitions_size += 1;

    if(scope->function_definitions == (void*)0) {

        scope->function_definitions = calloc(1, sizeof(struct AST_STRUCT*));

    }
    else {

        scope->function_definitions = realloc(scope->function_definitions, 
                                              scope->function_definitions_size * sizeof(struct AST_STRUCT**)
                                             );

    }

    scope->function_definitions[scope->function_definitions_size-1] = fdef;

    return fdef;
}

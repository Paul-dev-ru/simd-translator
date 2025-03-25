grammar Assembly;

program: statement* NEWLINE* EOF;

statement
    : labelDeclaration
    | addStatement 
    | subStatement 
    | cmpStatement 
    | jzStatement
    | jmpStatement
    ;

labelDeclaration
    : label ':' NEWLINE
    ;

addStatement
    : 'add' register ',' operand NEWLINE
    ;

subStatement
    : 'sub' register ',' operand NEWLINE
    ;

cmpStatement
    : 'cmp' register ',' operand NEWLINE
    ;

jzStatement
    : 'jz' label NEWLINE
    ;

jmpStatement
    : 'jmp' label NEWLINE
    ;

register
    : VALID_NAME
    ;

operand
    : (register | INT)
    ;

label
    : VALID_NAME
    ;

VALID_NAME : [a-zA-Z_] [a-zA-Z_0-9]*;
INT : '-'? [0-9]+;

NEWLINE : '\r'? '\n';
WS: [ \t]+ -> skip;
grammar SpecialAsm;

program: command* NEWLINE* EOF;

command
    : serviceCommand
    | aluCommand
    | procCommand
    ;

serviceCommand
    : initCommand
    | decCommand
    | incr0Command
    | setCommand
    | jumpCommand
    | waitCommand
    | genCommand
    | eopCommand 
    ;

// init(rn,d) – запись числа d в регистр rn n=0..3
initCommand
    : 'init' '(' REGISTER ',' INT ')'
    ;

// dec(rn) – декремент регистра rn n=0..3
decCommand
    : 'dec' '(' REGISTER ')'
    ;

// incr0 – инкремент регистра r0
incr0Command
    : 'incr0'
    ;

// set(rn,q) – присвоение регистру rn n=0..3 значения параметра номер q=0..3
setCommand
    : 'set' '(' REGISTER ',' PARAM ')'
    ;

// jump(rn,L) – переход на строку с меткой L, если содержимое регистра rn не равно 0
jumpCommand
    : 'jump' '(' REGISTER ',' LABEL ')'
    ;

// wait(t) – пауза t тактов
waitCommand
    : 'wait' '(' UNSIGNED ')' 
    ;

// gen – запуск генератора
genCommand
    : 'gen'
    ;

// eop – конец программы 
eopCommand
    : 'eop'
    ;

aluCommand
    : idCommand
    | andCommand
    | orCommand
    | xorCommand
    | invCommand
    | revCommand
    ;

// id(…) – тождественная операция (результат A)
idCommand
    : 'id' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// and(…) – поразрядная конъюнкция (результат A and B)
andCommand
    : 'and' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// or(…) – поразрядная дизъюнкция (результат A or B)
orCommand
    : 'or' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// xor(…) – поразрядная сумма по модулю 2 (результат A xor B)
xorCommand
    : 'xor' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// inv(…) – поразрядная инверсия (результат not A)
invCommand
    : 'inv' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// rev(…) – перестановка битов A в обратном порядке
revCommand
    : 'rev' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

procCommand
    : a1Command
    | a4Command
    | a5Command
    | a128dCommand
    | dCommand
    | dinvCommand
    | d64Command
    | d64invCommand
    ;

// a1(…) – преобразование A1
a1Command
    : 'a1' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// a4(…) – преобразование А4
a4Command
    : 'a4' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// a5(…) – преобразование А5
a5Command
    : 'a5' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// a128d(…) – преобразование A128d
a128dCommand
    : 'a128d' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// d(…) – преобразование D
dCommand
    : 'd' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// dinv(…) – преобразование обратный D
dinvCommand
    : 'dinv' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// d64(…) – преобразование D-K64
d64Command
    : 'd64' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

// d64inv(…) – преобразование обратный D-K64
d64invCommand
    : 'd64inv' '(' (namedArgument (',' namedArgument)*)? ')'
    ;

argument
    : 'in'
    | 'out'
    | 'ac'
    | 'sr'
    | 'sc'
    | 'tr'
    | 'eop'
    | 'wrout'
    | 'cmp'
    | 'acc'
    | 'rr'
    | 'rt'
    | 'd4m'
    | 'rd'
    | 'gen'
    ;

argumentValue
    : VALID_NAME
    | twoArray
    | fourArray
    ;

twoArray
    : '[' VALID_NAME ',' VALID_NAME ']'
    ;

fourArray
    : '[' VALID_NAME ',' VALID_NAME ',' VALID_NAME ',' VALID_NAME ']'
    ;

namedArgument
    : argument '=' argumentValue
    ;

UNSIGNED: [0-9]+;
INT: '-'? [0-9]+;

VALID_NAME: [a-zA-Z_] [a-zA-Z_0-9]*;
LABEL: VALID_NAME;
REGISTER: 'r' [0-9]+;
PARAM: VALID_NAME;

NEWLINE: '\r'? '\n';
WS: [ \t]+ -> skip;
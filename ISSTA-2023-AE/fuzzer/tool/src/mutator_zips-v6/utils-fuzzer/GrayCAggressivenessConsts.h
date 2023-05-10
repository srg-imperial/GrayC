/* ******************************************************************
File: GrayCAggressivenessConsts

Contain all the constants to control the fuzzer aggressiveness

TODO: add the terminology from the paper here.

TODO: move constants from expression-mutator/ExpressionMutator.h to here

Mutators:
- AppendExpression + ExtractExpression = inner random machanism 
      from original fuzzer (e.g. Csmith)

- Control with constants in this header:
  - AssignmentMutator
  - ConstantMutator
  - DuplicateMutator
  - ExpressionMutator
  - TODO: add the rest of the mutators, finish dup and expr mutator
******************************************************************/
#ifndef GRAYC_AGGRESSIVENESS_CONSTS_H
#define GRAYC_AGGRESSIVENESS_CONSTS_H

// TODO: Reduce/increase the probability to get more aggressive fuzzing
#define __AssignmentMutator_VisitUnaryOperator_CONST 0.1    

// TODO: Reduce/increase the probability to get more aggressive fuzzing
#define __AssignmentMutator_VisitDeclStmtr_CONST 0.5

// Increase the probability to get more aggressive fuzzing
#define __CONSTANT_MUTATOR_ALLOW_NEG_NUM_MEMORY_ACCESS_CONST 0.2

// Increase the probablity to get more aggressive fuzzing
#define __CONSTANT_MUTATOR_ALLOW_BIG_NUM_MEMORY_CONST 0.02

// Increase the probability to get more aggressive fuzzing
#define __CONSTANT_MUTATOR_INTEGER_EDITS_CONST 0.5

// Increase the probability to get more aggressive fuzzing
#define __CONSTANT_MUTATOR_FLIP_CHARS_CONST 0.1

// Decrease the probability to get more aggressive fuzzing
#define __DUPLICATE_MUTATOR_REMOVE_RHS_OR_LHS 0.9

// Increase the probability to get more aggressive fuzzing 
#define __DUPLICATE_MUTATOR_DUP_OR_DEL 0.5

// Increase the probability to get more aggressive fuzzing
#define __EXPRESSION_MUTATOR_REPLACE_BIN_OP_SUB_EXPR 0.6

// Increase the probability to get more aggressive fuzzing
#define __EXPRESSION_MUTATOR_EXPR_MAX_LEN 20000

#endif

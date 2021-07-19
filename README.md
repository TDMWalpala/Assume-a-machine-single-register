# Assume-a-machine-single-register
Assume a machine that has a single register and six instructions.

LD A which places the operand A into the register.
ST A which places the contents of the register into the variable A.
AD A which adds the contents of variable A to the register.
SB A which subtracts the contents of the variable A from the register.
ML A which multiplies the contents of the register by the variable A.
DV A which divides the contents of the register by the variable A.

Write C a program that accepts a postfix expression containing single-letter operands and
the operators +,-,*, and / and which prints a sequence of instructions to evaluate the
expression and leave the result in the register.
Use variables of the form TEMPn as temporary variables.
For example, the postfix expression ABC*+DE-/ should yield the printout.

LD B

ML C

ST TEMP1

LD A

AD TEMP1

ST TEMP2

LD D

SB E

ST TEMP3

LD TEMP2

DV TEMP3

ST TEMP4

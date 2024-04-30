## Rumman Shahzad
## CS 385-01, Assignment 1
## February 13, 2024

        .text
        .globl main
main:
        # Obtain the 1st integer
        ori $v0,$zero,4             # I-type, I-format (ori rd,rs,imm), load system code for printing a string
        lui $a0,0x1001              # I-type, I-format (lui rd,imm), load upper 16 bits of prompt address in $a0 to be printed
        ori $a0,$a0,0x0010          # I-type, I-format (ori rd,rs,imm), load lower 16 bits of prompt address in $a0 to be printed
        syscall                     # System call, transfer control to operating system

        ori $v0,$zero,5             # I-type, I-format (ori rd,rs,imm), load system code for reading an integer
        syscall                     # System call, transfer control to operating system
        addu $s0,$zero,$v0          # R-type, R-format (addu rd,rs,rt), keep first integer in saved register $s0

        # Obtain the 2nd integer
        ori $v0,$zero,4             # I-type, I-format (ori rd,rs,imm), load system code for printing a string
        lui $a0,0x1001              # I-type, I-format (lui rd,imm), load upper 16 bits of prompt2 address in $a0 to be printed
        ori $a0,$a0,0x002a          # I-type, I-format (ori rd,rs,imm), load lower 16 bits of prompt2 address in $a0 to be printed
        syscall                     # System call, transfer control to operating system

        ori $v0,$zero,5             # I-type, I-format (ori rd,rs,imm), load system code for reading an integer
        syscall                     # System call, transfer control to operating system
        addu $s1,$zero,$v0          # R-type, R-format (addu rd,rs,rt), keep second integer in saved register $s1

        # Determine which integer is larger
        lui $t0,0x1001              # I-type, I-format (lui rd,imm), setup base register for offsetting
        slt $t1,$s1,$s0             # R-type, R-format (slt rd,rs,rt), if second integer is less than first, rd = 1; else 0
        beq $t1,$zero,secondLarger  # Branch type, I-format (beq rs,rt,label), if $t1 != 0, jump to secondLarger, else do nothing

        # First integer is larger (skip over secondLarger block)
        sw $s0,0($t0)               # Memory transfer type, I-format (sw rs,imm(rt)), save first integer in memory
        sw $s1,4($t0)               # Memory transfer type, I-format (sw rs,imm(rt)), save second integer in memory
        addu $t2,$zero,$s1          # R-type, R-format (addu rd,rs,rt), move smaller integer to $t2
        addu $t3,$zero,$s0          # R-type, R-format (addu rd,rs,rt), move larger integer to $t3
        j continue                  # J-type, J-format (j target), skip over secondLarger
        
        # Second integer is larger
secondLarger:
        sw $s1,0($t0)               # Memory transfer type, I-format (sw rs,imm(rt)), save second integer in memory
        sw $s0,4($t0)               # Memory transfer type, I-format (sw rs,imm(rt)), save first integer in memory
        addu $t2,$zero,$s0          # R-type, R-format (addu rd,rs,rt), move smaller integer to $t2
        addu $t3,$zero,$s1          # R-type, R-format (addu rd,rs,rt), move larger integer to $t3

        # Divide the integers and store the quotient and remainder in memory
continue:
        div $t3,$t2                 # R-type, R-format (div rs,rt), divide the larger integer by the smaller integer
        mflo $t4                    # R-type, R-format (mflo rd), move quotient to $t4
        mfhi $t5                    # R-type, R-format (mfhi rd), move remainder to $t5
        sw $t4,8($t0)               # Memory transfer type, I-format (sw rs,imm(rt)), save quotient in memory
        sw $t5,12($t0)              # Memory transfer type, I-format (sw rs,imm(rt)), save remainder in memory

        # Print the larger integer first
        ori $v0,$zero,4             # I-type, I-format (ori rd,rs,imm), load system code for printing a string
        lui $a0,0x1001              # I-type, I-format (lui rd,imm), load upper 16 bits of address of larger in $a0 to be printed
        ori $a0,$a0,0x0045          # I-type, I-format (ori rd,rs,imm), load lower 16 bits of address of larger in $a0 to be printed
        syscall                     # System call, transfer control to operating system

        addu $a0,$zero,$t3          # R-type, R-format (addu rd,rs,rt), move larger integer to $a0 for printing
        ori $v0,$zero,1             # I-type, I-format (ori rd,rs,imm), load system code for printing an integer
        syscall                     # System call, transfer control to operating system

        # Then print the smaller integer
        ori $v0,$zero,4             # I-type, I-format (ori rd,rs,imm), load system code for printing a string
        lui $a0,0x1001              # I-type, I-format (lui rd,imm), load upper 16 bits of address of smaller in $a0 to be printed
        ori $a0,$a0,0x0057          # I-type, I-format (ori rd,rs,imm), load lower 16 bits of address of smaller in $a0 to be printed
        syscall                     # System call, transfer control to operating system

        addu $a0,$zero,$t2          # R-type, R-format (addu rd,rs,rt), move smaller integer to $a0 for printing
        ori $v0,$zero,1             # I-type, I-format (ori rd,rs,imm), load system code for printing an integer
        syscall                     # System call, transfer control to operating system

        # Print the quotient
        ori $v0,$zero,4             # I-type, I-format (ori rd,rs,imm), load system code for printing a string
        lui $a0,0x1001              # I-type, I-format (lui rd,imm), load upper 16 bits of address of quotient in $a0 to be printed
        ori $a0,$a0,0x006a          # I-type, I-format (ori rd,rs,imm), load lower 16 bits of address of quotient in $a0 to be printed
        syscall                     # System call, transfer control to operating system

        addu $a0,$zero,$t4          # R-type, R-format (addu rd,rs,rt), move quotient to $a0 for printing
        ori $v0,$zero,1             # I-type, I-format (ori rd,rs,imm), load system code for printing an integer
        syscall                     # System call, transfer control to operating system

        # Print the remainder
        ori $v0,$zero,4             # I-type, I-format (ori rd,rs,imm), load system code for printing a string
        lui $a0,0x1001              # I-type, I-format (lui rd,imm), load upper 16 bits of address of remainder in $a0 to be printed
        ori $a0,$a0,0x0076          # I-type, I-format (ori rd,rs,imm), load lower 16 bits of address of remainder in $a0 to be printed
        syscall                     # System call, transfer control to operating system

        addu $a0,$zero,$t5          # R-type, R-format (addu rd,rs,rt), move remainder to $a0 for printing
        ori $v0,$zero,1             # I-type, I-format (ori rd,rs,imm), load system code for printing an integer
        syscall                     # System call, transfer control to operating system

        # Exit the program
        ori $v0,$zero,10            # I-type, I-format (ori rd,rs,imm), load system code for exit
        syscall                     # System call, transfer control to operating system

        .data
integers:   .word   0 0 0 0
prompt:     .asciiz "Enter the first integer: "
prompt2:    .asciiz "Enter the second integer: "
larger:     .asciiz "\nLarger integer: "
smaller:    .asciiz "\nSmaller integer: "
quotient:   .asciiz "\nQuotient: "
remainder:  .asciiz "\nRemainder: "
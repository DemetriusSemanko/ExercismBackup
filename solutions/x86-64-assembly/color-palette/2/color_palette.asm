default rel

section .rodata
    global RED, GREEN, BLUE
    RED: dd 0xFF000000
    GREEN: dd 0x00FF0000
    BLUE: dd 0x0000FF00

; Define the variable 'base_color' with the default value of 0xFFFFFF00
; It must be accessible from other source files
section .data
    global base_color
    base_color: dd 0xFFFFFF00

section .text
extern combining_function

; the global directive makes a function visible to the test files
global get_color_value
get_color_value:
    ; This function takes the address for a color as parameter
    ; It must return the 32-bit value associated with the color
    mov eax, dword [rdi]
    
    ret

global add_base_color
add_base_color:
    ; (rdi: color_addr)
    ; This function takes the address for a color as parameter
    ; It saves the 32-bit value associated with this color in the variable 'base_color'
    ; This variable must be accessible from other source files
    ; This function has no return value
    mov esi, dword [rdi]
    mov [base_color], esi

    ret

global make_color_combination
make_color_combination:
    ; (rdi: combined_color_dest_addr, rsi: seconday_color_addr)
    ; This function takes the following parameters:
    ; - Combined color (32-bit) dest addr
    ; - Secondary color addr
    
    
    ; Call 'combining_function' with base and secondary color values (32-bit) and store the result in combined color dest addr
    
    ; This function has no return value
    
    mov r11, rdi
    movzx rdi, dword [base_color]
    
    mov rsi, [rsi]

    call combining_function
    mov dword [r11], eax
    
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

section .text

COOK_TIME equ 40

global expected_minutes_in_oven
expected_minutes_in_oven:
    mov rax, COOK_TIME
    ret

global remaining_minutes_in_oven
remaining_minutes_in_oven: ; (time_in_oven)
    mov rax, COOK_TIME
    sub rax, rdi
    ret

LAYER_TIME equ 2

global preparation_time_in_minutes
preparation_time_in_minutes: ; (layers)
    mov rax, rdi
    imul rax, LAYER_TIME
    ret

global elapsed_time_in_minutes
elapsed_time_in_minutes: ; (num_layers, time_in_oven)
    mov rax, rdi
    imul rax, LAYER_TIME
    add rax, rsi
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

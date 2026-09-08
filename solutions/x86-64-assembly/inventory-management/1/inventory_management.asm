%include "debug.mac"

WEIGHT_OF_EMPTY_BOX equ 500
TRUCK_HEIGHT equ 300
PAY_PER_BOX equ 5
PAY_PER_TRUCK_TRIP equ 220

section .text

global get_box_weight
get_box_weight: ; (rdi: num_first_prod, rsi: weight_first_prod, rdx: num_sec_prod, rcx: weight_sec_prod)
    mov r8, rdx ; rdx is parameter register, used in imul, so mov value to safety
    imul rdi, rsi ; first product total weight
    imul rcx, r8 ; second product total weight
    mov rax, 0 ; flush register since it's used in imul
    add rax, rdi
    add rax, rcx
    add rax, WEIGHT_OF_EMPTY_BOX 
    ret

global max_number_of_boxes
max_number_of_boxes: ; (rdi: box_height_cm)
    mov ax, TRUCK_HEIGHT ; move 8 bits to 16 bit register
    mov bl, dil ; mov lower 8 bits to 8 bit register
    div bl ; divide ax by bl
    ; since ax is lower 16 of rax, answer is returned
    ret

global items_to_be_moved
items_to_be_moved: ; (rdi: num_prod_unaccounted, rsi: num_prod_boxed)
    mov eax, edi
    sub eax, esi
    ret

global calculate_payment
calculate_payment: ; (rdi: payment, esi: boxes_moved, edx: truck_trips, ecx: lost_items_num, 
                   ; r8: lost_item_val, r9b: num_other_workers)

    mov rax, PAY_PER_TRUCK_TRIP
    mul rdx
    mov r10, rax
    ; r10: truck_trip_total

    mov rax, PAY_PER_BOX
    mul rsi
    mov rsi, rax
    ; rsi: box_pay_total

    mov rax, rcx
    mul r8
    mov rcx, rax
    ; rcx: lost_items_value

    add r10, rsi
    sub r10, rdi
    sub r10, rcx
    ; acc our gains/losses

    inc r9
    mov rax, r10
    cqo ; I had to just RTFM
    idiv r9

    add rax, rdx
    
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

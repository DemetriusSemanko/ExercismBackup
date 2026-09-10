C2 equ 2
C3 equ 3
C4 equ 4
C5 equ 5
C6 equ 6
C7 equ 7
C8 equ 8
C9 equ 9
C10 equ 10
CJ equ 11
CQ equ 12
CK equ 13
CA equ 14

TRUE equ 1
FALSE equ 0

section .text

global value_of_card
value_of_card:
    ; (dil: card_num)
    ; This function takes as parameter a number representing a card
    ; The function should return the numerical value of the passed-in card
    
    cmp dil, 11
    jl .less_than_face
    jge .face_or_ace
    
    .less_than_face:
        movzx rax, dil
        ret
        
    .face_or_ace:
        cmp dil, 14
        je .ace
        mov rax, 10 ; assume face card value
        ret
    
    .ace:
        mov rax, 1
        ret
    
    ret

global higher_card
higher_card:
    ; (rdi: card_one, rsi: card_two)
    ; This function takes as parameters two numbers each representing a card
    ; The function should return which card has the higher value
    ; If both have the same value, both should be returned
    ; If one is higher, the second one should be 0
    
    ; save original card_one code
    mov r11, rdi

    call value_of_card
    mov r9, rax ; r9 keeps card_one's value

    ; put card_two in rdi
    mov rdi, rsi
    call value_of_card
    mov r10, rax ; r10 keeps card_two's value
    
    cmp r9, r10
    
    jg .a_greater_than_b
    jl .a_less_than_b
    je .a_equals_b
    
    .a_greater_than_b:
        mov rax, r11
        mov rdx, 0
        ret
    
    .a_less_than_b:
        mov rax, rsi
        mov rdx, 0
        ret
        
    .a_equals_b:
        mov rax, r11
        mov rdx, rsi
        ret

global value_of_ace
value_of_ace:
    ; (rdi: card_one, rsi: card_two)
    call value_of_card
    mov r9, rax
    cmp r9, 1
    je .ace_is_1
    
    mov rdi, rsi
    call value_of_card
    mov r10, rax
    cmp r10, 1
    je .ace_is_1
    
    add r9, r10
    mov rax, 11
    
    cmp r9, 10
    ja .ace_is_1
        
    ret
    
.ace_is_1:
    mov rax, 1
    ret

global is_blackjack
is_blackjack:
    ; (rdi: card_one, rsi: card_two)
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards form a blackjack, and FALSE otherwise
    call value_of_card
    
    cmp rax, 10
    je .card_one_is_10

    cmp rax, 1
    je .card_one_is_ace

    mov rax, 0
    
    ret

.card_one_is_ace:
    mov rdi, rsi
    call value_of_card
    cmp rax, 10
    jne .not_blackjack

    mov rax, TRUE
    ret

.card_one_is_10:
    cmp rsi, CA
    jne .not_blackjack

    mov rax, TRUE
    ret

.not_blackjack:
    mov rax, FALSE
    ret

global can_split_pairs
can_split_pairs:
    ; (rdi: card_one, rsi: card_two)
    call value_of_card
    mov r9, rax
    
    mov rdi, rsi
    call value_of_card
    mov r10, rax

    cmp r9, r10
    je .splittable
    
    mov rax, FALSE
    ret
    
.splittable:
    mov rax, TRUE
    ret

global can_double_down
can_double_down:
    ; This function takes as parameters two numbers each representing a card
    ; The function should return TRUE if the two cards form a hand that can be doubled down, and FALSE otherwise
    call value_of_card
    mov r9, rax

    mov rdi, rsi
    call value_of_card
    add r9, rax

    cmp r9, 9
    jb .cannot_double_down

    cmp r9, 11
    ja .cannot_double_down

    mov rax, TRUE
    
    ret

.cannot_double_down:
    mov rax, FALSE
    ret

%ifidn __OUTPUT_FORMAT__,elf64
section .note.GNU-stack noalloc noexec nowrite progbits
%endif

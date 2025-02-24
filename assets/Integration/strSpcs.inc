;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Written by : - Abdelrahman Hamza  12-12-2021                                        ;;
; parameters : - string you want to remove all spaces from it                         ;;
; return     : - Removes all spaces from this string                                  ;;
;A macro that takes a string with spaces and remove all spaces from it                ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
removeSpaces MACRO string                                                             ;;
    LOCAL loopOverAllString                                                           ;;
    LOCAL stringEnd                                                                   ;;
    LOCAL notSpace                                                                    ;;
    LOCAL innerLoopString                                                             ;;
    LOCAL DontIncBX                                                                   ;;
    mov bx, string                                                                    ;;
                                                                                      ;;
    ;mov bx,offset string                                                             ;;
    ;iterate over all string                                                          ;;
    loopOverAllString:                                                                ;;
        ;check end of string                                                          ;;
        mov ah,'$'                                                                    ;;
        cmp [bx],ah                                                                   ;;
        jz stringEnd                                                                  ;;
        ;check if space                                                               ;;
        mov ah,' '                                                                    ;;
        cmp [bx],ah                                                                   ;;
        jnz notSpace                                                                  ;;
            ; if space what to do?                                                    ;;
            mov si,bx                                                                 ;;
            innerLoopString:                                                          ;;
                mov ah,'$'                                                            ;;
                cmp [si],ah                                                           ;;
                jz DontIncBX   ;not increament bx if space                            ;;
                mov ax,[si+1]                                                         ;;
                mov [si],ax                                                           ;;
                inc si                                                                ;;
            jmp innerLoopString                                                       ;;
                                                                                      ;;
        notSpace:                                                                     ;;
        inc bx                                                                        ;;
        DontIncBX:                                                                    ;;
    jmp loopOverAllString                                                             ;;
                                                                                      ;;
    stringEnd:                                                                        ;;
ENDM                                                                                  ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
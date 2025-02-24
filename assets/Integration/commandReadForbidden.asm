                            
getChar MACRO   
  mov ah, 07h   
  int 21h        
ENDM

.model small
.stack 64
.data
;MyCommand LABEL BYTE
CommandSize db 20
ActualSize db ?
newStr db 20 dup('$')





.code
main proc far

    mov ax,@data
    mov ds,ax

    call getCommandLVL1
    
    hlt
main endp


getCommandLVL1 proc
  lea di,newStr  ;change this to new name
  lea si,newStr
  Com1mainLoop:
  mov ah, 07h
  int 21h
  mov dl,al
  mov bh,0Dh
  cmp dl,bh
  jz Com1exit
  mov bh,08h
  cmp dl,bh
  jz Com1Backspace

  mov bl,'F' ;;forbidden Character 
  cmp al,bl
  jz Com1found   
  
  mov ah,0eh  ;Display a character in AL
  int 10h    
  mov [di],al
  inc di 
  
  Com1found:
  jmp Com1mainLoop
  
  Com1Backspace: ;if user enter backspace
  cmp di,si
  jz NoDEC1
  dec di
  NoDEC1:
  mov bl,'$'
  mov [di],bl
  mov ah,3h
  mov bh,0h  ;get cursor
  int 10h
  ;check if the cursor(x) = 0
  mov al,0
  cmp al,dl
  jz NoDEC2
  dec dl
  NoDEC2:
  mov ah,2
  int 10h
  mov ah,2
  mov dl,' '
  int 21h
  mov ah,3h
  mov bh,0h 
  int 10h
  dec dl
  mov ah,2
  int 10h              
  jmp Com1mainLoop
  
  Com1exit:
  ret
getCommandLVL1 endp
end main
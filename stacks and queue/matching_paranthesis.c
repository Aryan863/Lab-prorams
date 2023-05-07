#include<stdio.h>

#define sz 50

struct Stack{
    char st[sz];
    int top;
}S;

int stackEmpty(){
    if(S.top==-1)
        return 1;
    else
        return 0;
}

int stackFull(){
    if(S.top==sz-1)
        return 1;
    else
        return 0;
}

void push(char elem){
    if(stackFull()==1)
        printf("Stack is Full\n");
    else{
        S.top++;
        S.st[S.top] = elem;
    }
}

void pop(){
    if(stackEmpty()==1)
        printf("Stack is Empty\n");
    else{
        S.top--;
    }
}

int main(){

    
    S.top = -1;

    char str[sz];
    printf("Enter the expression for parenthesis validation:\n");
    gets(str);

    int flag = 0;

    for(int i=0; str[i]!='\0'; i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            push(str[i]);
        }
        
        else if(str[i]==')' || str[i]==']' || str[i]=='}'){
            if(stackEmpty()==1){
                flag = 1;
                break;
            }
            if(str[i]==')' && S.st[S.top]=='('){
                pop();
            }
            else if(str[i]=='}' && S.st[S.top]=='{'){
                pop();
            }
            else if(str[i]==']' && S.st[S.top]=='['){
                pop();
            }
            else{
                flag = 1;
                break;
            }
        }
    }
    if(S.top!=-1)
        flag = 1;

    if(flag==0)
        printf("Valid Expression.\n");
    else
        printf("Invalid Expression.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float num1;
    float num2;
    char op;
    float result;
} calc;

calc* add_history(calc*, int* , int* , float, float, char, float);

int main()
{
    calc* history=NULL;
    int count=0, capacity=0;
    float num1,num2,result=0;
    char op;
    while(1)
    {
        printf("Enter an operator:'+' for addition, '-' for subtraction, '*' for multiplication, '/' for division, 'q' to quit");
        scanf(" %c",&op);
        printf("Enter 2 numbers: ");
        scanf("%f%f",&num1,&num2);
        int valid=0;
        switch(op)
        {
            case '+': result= num1+num2;
            break;
            case '-': result= num1-num2;
            break;
            case '*': result= num1*num2;
            break;
            case '/': 
            if(num2==0){
                printf("ERROR: Divison by 0 is undefined.\n");
                valid=1;
                break;
            }
            else{
                result=(float) (num1/num2);
            }
            break;
            case 'q': exit(0);
            default:
            printf("Invalid operator\n");
            valid=1;
        }
        if (valid==0) 
        {
            printf("Result: %.2f\n", result);
            history = add_history(history, &count, &capacity, num1, num2, op, result);
            printf("[System: History size is now %d]\n", count);
        }
    }
    free(history);
    return 0;
}

calc* add_history(calc* history, int* count, int* capacity, float num1, float num2, char op, float result)
{
    if (*count == *capacity)
    {
        if (*capacity == 0)
        {
            *capacity = 1;
        }
        else
        {
            *capacity = *capacity * 2;
        } 
        history = (calc*) realloc(history, (*capacity) * sizeof(calc));
    }
    history[*count].num1=num1;
    history[*count].num2=num2;
    history[*count].op=op;
    history[*count].result=result;
    *count+=1;
    return history;
}
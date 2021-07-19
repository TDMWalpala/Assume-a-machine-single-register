//Include the standard library
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//Define a item array maximum size
#define size 100
//A structure to represent a stack.
struct stack{
    int top; //declare stack top
    char item[size];//character array
}st;
//Function to add an item to stack. It increases top by 1
void push(char ele[])
{
    st.top = st.top + 1;
    st.item[st.top] = ele ;//store "ele" value into the stack

}

int empty() //check Stack is empty.
{
    if(st.top == -1) //Stack is empty when top is equal to -1.
    {
        return 1; //If stack is empty then return integer 1.

    }else
    {
        return 0;//If stack is not empty then return integer 0.
    }
}



char pop() //Removing elements in the stack
{
    char out;
    if(empty()) //calling empty function and check return value.
    {
        printf("\nInvelid Expression"); /*if return value equal to 1 then
                                        print "Invelid Expression and exti programm */
        getch();
        exit(0);
    }
     out = st.item[st.top]; //if retun value equal 0 then pop the element and decreases top by 1.
     st.top--;
     return out; //return the pop element value.

    }

    int isoperator(char c) //Checking what elements are operator
    {
        switch(c)
        {
        case '+':
        case '-':
        case '/':
        case '*': return(1);break; //if c equal to '+' or '-' or '/' or '*' then return 1
        default : return(0); //if c not equal above operator then return 0
        }
    }


    void evaluate(char ch)
    {
        static int i=0; //Static variables are initialized only once.
        static int j=-1;
        char x[10]={'1','2','3','4','5','6','7','8','9'};
        char op1;
        char op2;
        op2 = pop(); //calling pop function and return value store op2
        op1 = pop(); //calling pop function and return value store op1
        if(isalpha(op1)) //if op1 is alphabet character then if condition is true(isalpha function is check the what elements are alphabet)
        {
            //places the operand op1 into the register.
            printf("\nLD\t%c",op1); //if op1 equal to the A then print "LD A"
            j++;  //increases j by 1

        }else
        {
            //places the operand op1 into the register.
            printf("\nLD\tTEMP%c",op1); //if op1 equal to the char 1 then print "LD TEMP1"
            j++; //increases j by 1
        }
        switch(ch)
        {
        case '+' : // ch = +
                if(isalpha(op2)) //if op2 is alphabet character then if condition is true.
                {
                    //adds the contents of variable po2 to the register.
                    printf("\nAD\t%c",op2); //if op2 equal to the A then print "AD A"
                    //places the contents of the register into the variable op2.
                    printf("\nST\tTEMP%c",x[i]); //if x[i] equal to the char 1 then print "ST TEMP1"
                    push(x[i]); //push character x[i] in to the stack
                }else
                {
                    //adds the contents of variable po2 to the register.
                    printf("\nAD\tTEMP%c",op2); //if op2 equal to the char 1 then print "AD TEMP1"
                    push(x[i]); //push character x[i] in to the stack
                    printf("\nST\tTEMP%c",x[j]); //if x[i] equal to the char 1 then print "ST TEMP1"

                }
                break;

         case '*' :
                if(isalpha(op2))
                {
                    //multiplies the contents of the register by the variable op2.
                    printf("\nML\t%c",op2); //if op2 equal to the A then print "ML A"
                    printf("\nST\tTEMP%c",x[i]);
                    push(x[i]);
                }else
                {
                    printf("\nML\tTEMP%c",op2); //if op2 equal to the char 1 then print "ML TEMP1"
                    push(x[i]);
                    printf("\nST\tTEMP%c",x[j]);

                }
                break;
            case '-' :
                if(isalpha(op2))
                {
                    //subtracts the contents of the variable op2 from the register.
                    printf("\nSB\t%c",op2); //if op2 equal to the A then print "SB A"
                    printf("\nST\tTEMP%c",x[i]);
                    push(x[i]);
                }else
                {
                    printf("\nSB\tTEMP%c",op2); //if op2 equal to the char 1 then print "SB TEMP1"
                    push(x[i]);
                    printf("\nST\tTEMP%c",x[j]);


                }
                break;
            case '/' :
                if(isalpha(op2))
                {
                    //divides the contents of the register by the variable A.
                    printf("\nDV\t%c",op2); //if op2 equal to the A then print "DV A"
                    printf("\nST\tTEMP%c",x[i]);
                    push(x[i]);
                }else
                {
                    printf("\nDV\tTEMP%c",op2); //if op2 equal to the char 1 then print "DV TEMP1"
                    push(x[i]);
                    printf("\nST\tTEMP%c",x[j]);


                }
            default:
                break;

        }
        i++; //increases i by 1

    }


int main()
{
    int i;
    st.top = -1; //Initialize  stack top
    char exp[30],c;
    printf("\nEnter Expression ");
    gets(exp); //Input the Expression
    if(strlen(exp)%2==0) //check exp is valid expression
    {
        printf("\nInvalid expression ");
        getch();
        exit(0);
    }
    for(i=0; exp[i]!='\0'; i++)
    {
        c = exp[i];

        if(isalpha(c))
        {
            push(c); //calling push function

        }else if(isoperator(c)) //calling isoprerator function and check the return value
        {
            evaluate(c); //calling evaluate function

        }else
        {
            printf("\nInvalid Expression");
            getch();
            exit(0);
        }
    }
    getch();
}

#include <fstream>
#include <stdlib.h>

using namespace std;


struct Stack
{
    char *val;
    int top;

    void initialize(int n)
    {
        val=(char *) malloc(n*sizeof(char));
        top=-1;
    }
    int isEmpty()
    {
        if(top==-1)
            return 1;
        else 
            return 0;
    }
    char peek()
    {
        if(isEmpty())
            return '\0';
        else
        {
            return val[top];
        }
    }
    char pop()
    {
        if(isEmpty())
            return '\0';
        else
        {
            char ch= val[top];
            top--;
            return ch;
        }
    }
    void push(char op)
    {
        top++;
        val[top]=op;
    }
    ~Stack(){}
    
};



void getToken(char *exp, char *t, int &i)
{
    int j=1;
    t[0]=exp[i++];
    if(t[0]<'0' || '9'<t[0])
        return;
    while('0'<=exp[i] && exp[i]<='9')
    {
        t[j++]=exp[i++];
        
    }
    t[j]='\0';
    return;
    
}
int isOperand(char *t)
{
    if('0'<=t[0] && t[0]<='9')
        return 1;
    else
    {
        return 0;
    }
    
}
int isOperator(char *t)
{
    if(t[0]=='*' || t[0]=='/' || t[0]=='%' || t[0]=='+' || t[0]=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int precedence(char op1, char op2)
{
    int p1,p2;
    if(op1=='(' || op1==')')
        p1=3;
    else if(op1=='*' || op1=='/' || op1=='%')
        p1=2;
    else
    {
        p1=1;
    }
    if(op2=='(' || op2==')')
        p2=3;
    else if(op2=='*' || op2=='/' || op2=='%')
        p2=2;
    else
    {
        p2=1;
    }
    return p2-p1;
}

void convert(char* exp)
{
    char temp[100];
    int i=0,j=0;
    Stack st;
    st.initialize(100);
    
    while(exp[j]!='\r' && exp[j]!='\n' &&exp[j]!='\0')
    {
        char t[15];
        getToken(exp,t,j);
        if(isOperand(t))
        {
            int k=0;
            while('0'<=t[k] && t[k]<='9')
                temp[i++]=t[k++];
            temp[i++]=' ';
        }
        else if(isOperator(t))
        {
            char op1=t[0],op2;
            op2=st.peek();
            while(!st.isEmpty())
            {
                op2=st.peek();
                if(op2=='(')
                    break;
                if(precedence(op1,op2)>=0)
                {
                    temp[i++]=op2;
                    temp[i++]=' ';
                    st.pop();
                }
                else 
                    break;
            }
            st.push(op1);
            
        }
        else if(t[0]=='(')
        {
            st.push(t[0]);
        }
        else if(t[0]==')')
        {
            while(st.peek()!='(')
            {
                temp[i++]=st.pop();
                temp[i++]=' ';
            }
            st.pop();
        }
    }
    while(!st.isEmpty())
            {
                temp[i++]=st.pop();
                temp[i++]=' ';
            }
    temp[i]='\0';
    for(j=0;j<=i;++j)
        exp[j]=temp[j];
    
    
}

int main()
{
    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open( "part1-output.txt");
    while (!fin.eof())
    {   
        char exp[100];
        fin.getline(exp,100);
        
        convert(exp);
        if(exp[0])
        fout<<exp<<"\n";
        
    }
    fin.close();
    fout.close();
    
    return 0;
}
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Stack
{
    long long  *val;
    int top;

    void initialize(int n)
    {
        val=(long long  *) malloc(n*sizeof(char));
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
            return 0;
        else
        {
            return val[top];
        }
    }
    long long  pop()
    {
        if(isEmpty())
            return '\0';
        else
        {
            long long  ch= val[top];
            top--;
            return ch;
        }
    }
    void push(long long  op)
    {
        top++;
        val[top]=op;
    }
    ~Stack(){}
    
};


void getToken(char *exp, char *temp, int &i)
{
    int j=0;
    while(exp[i]!=' ')
    {
        temp[j++]=exp[i++];
    }
    temp[j]='\0';
    i++;
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
long long calc(long long x, long long y, char *t)
{
    if(t[0]=='*')
        return x*y;
    if(t[0]=='/')
        return x/y;
    if(t[0]=='%')
        return x%y;
    if(t[0]=='+')
        return x+y;
    if(t[0]=='-')
        return x-y;
}
long long evaluate(char* exp)
{
    int i=0;
    Stack st;
    st.initialize(100);
    while(exp[i]!='\0')
    {
        char t[15];
        getToken(exp,t,i);
        if(isOperand(t))
        {
            long long x=atoll(t);
            st.push(x);
        }
        else if(isOperator(t))
        {
            long long x,y,res;
            y=st.pop();
            x=st.pop();
            res=calc(x,y,t);
            st.push(res);

        }
    }
    return st.pop();

}

int main()
{
    ifstream fin;
    fin.open("part1-output.txt");
    ofstream fout;
    fout.open( "part2-output.txt");
    while (!fin.eof())
    {   
        char exp[100];
        fin.getline(exp,100);
        if(exp[0]){
        long long ans=evaluate(exp);
        fout<<ans<<"\n";
        }
    }
    fin.close();
    fout.close();
    
    return 0;
}
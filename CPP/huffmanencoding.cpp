#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


struct HuffMan
{
    int freq[37];//0 - 25 a-z, 26-35 0-9
    int nodeid;
    char *H[36];
    struct node 
    {
        char symbol[20];
        int frequency;
        node *next;
        node *left;
        node *right;
    }*root;
    int getKey(char ch)
    {
        if('0'<=ch && ch<='9')
        {
            return 26+int(ch-'0');
        }
        else if('a'<=ch && ch<='z')
        {
            return int(ch-'a');
        }
        else
        {
            return 36;
        }
        
        
    }
    char keyToSym(int i)
    {
        if(i>25)
        {
            return char(i-26+(int)'0');
        }
        else 
        {
            return char(i+(int)'a');
        }
    }
    void init()
    {
        for(int i=0;i<37;++i)
            freq[i]=0;
        nodeid=1;
        root=NULL;
        return ;
    }
    void insertStr(char* str)
    {
        int i=0;
        while (str[i]!='\0')
        {
            freq[getKey(str[i])]++;
            i++;
        }
        return;
    }
    int getFreq(char ch)
    {
        return freq[getKey(ch)];
    }
    void insertLink(char sym, int freq)
    {
        if(root==NULL)
        {
            root=new node;
            root->frequency=freq;
            (root->symbol)[0]=sym;
            (root->symbol)[1]='\0';
            root->next=NULL;
            root->left=NULL;
            root->right=NULL;
            return;
        }
        node *temp=root,*temp2;
        while ((temp->next)!=NULL)
        {
            temp=temp->next;
        }
        
        
        temp2=new node;
        temp2->frequency=freq;
        (temp2->symbol)[0]=sym;
        (temp2->symbol)[1]='\0';
        
        temp2->left=NULL;
        temp2->right=NULL;
        temp2->next=NULL;
        temp->next=temp2;
        return;
        // if(freq < temp->frequency)
        // {
        //     temp=new node;
        //     temp->frequency=freq;
        //     (temp->symbol)[0]=sym;
        //     (temp->symbol)[1]='\0';
        //     temp->next=root;
        //     temp->left=NULL;
        //     temp->right=NULL;
        //     root=temp;
        //     return;
        // }
        // while (temp->frequency < freq && temp->next)
        // {
            
        // }
        
        
    }
    void makeLinkedList()
    {
        int done[36];
        for(int i=0;i<36;++i)
        {
            done[i]=0;
        }
        for(int i=0;i<36;++i)
        {
            int minKey=0,f=INT32_MAX;
            for(int j=0;j<36;++j)
            {
                if(done[j]==1) continue;
                if(freq[j]<f)
                {
                    minKey=j;
                    f=freq[j];
                }
            }
            done[minKey]=1;
            insertLink(keyToSym(minKey),f);
            
        }
        return;
    }   
    void pr()
    {
        node *temp =root;
        while(temp!=NULL)
        {
            cout<<temp->symbol<<" ";
            cout<<temp->frequency<<endl;
            temp=temp->next;
        }
        return;
    }

    void process ()
    {
        node *supnode;
        supnode = new node;
        supnode->frequency=root->frequency;
        sprintf(supnode->symbol,"N%d",nodeid++);
        supnode->left=root;
        root=root->next;
        supnode->left->next=NULL;
        supnode->right=root;
        supnode->frequency= (supnode->frequency + root->frequency);
        root=root->next;
        supnode->right->next=NULL;

        node *temp=root;
        if(temp==NULL)
        {
            root = supnode;
            root->next=NULL;
            return;
        }
        node *p=NULL;
        while(temp!=NULL)
        {
            if(temp->frequency < supnode->frequency)
            {
                p=temp;
                temp=temp->next;
            }
            else if (temp->frequency == supnode->frequency)
            {
                if(temp->symbol[0]=='N')
                {
                    p=temp;
                    temp=temp->next;
                    continue;
                }
                else
                {
                    if(p==NULL)
                    {
                        supnode->next=root;
                        root=supnode;
                        return;
                    }
                    else
                    {
                        p->next=supnode;
                        supnode->next=temp;
                        return;
                    }
                    
                }
                
            }
            else
            {
                    if(p==NULL)
                    {
                        supnode->next=root;
                        root=supnode;
                        return;
                    }
                    else
                    {
                        p->next=supnode;
                        supnode->next=temp;
                        return;
                    }
            }
            
        }
        if(p==NULL)
        {
            root=supnode;
        }
        else
        {
            p->next=supnode;
        }
        return;

    }
    void superNode()
    {
        while (root->next!=NULL)
        {
            process();
        }
        return;
    }
    void preOrderTraversal(node *t,ofstream &fout)
    {
        if(t==NULL) return;
        fout<<t->symbol<<"("<<t->frequency<<"),";
        preOrderTraversal(t->left,fout);
        preOrderTraversal(t->right,fout);
        return;
    }
    void preOrderTraversal(ofstream &fout)
    {
        preOrderTraversal(root,fout);
        fout<<"\n";
        return;
    }
    void treeTraverse(node *t,char *prefix,ofstream &fout)
    {
        if(t->left==NULL && t->right==NULL)
        {
            H[getKey((t->symbol)[0])]=new char[200];
            strcpy(H[getKey((t->symbol[0]))],prefix);
        }
        else
        {
            char x[100],y[100];
            strcpy(x,prefix);
            treeTraverse(t->left,strcat(x,"0"),fout);
            strcpy(y,prefix);
            treeTraverse(t->right,strcat(y,"1"),fout);
        }
        return;
    }
    void treeTraverse(ofstream &fout)
    {
        char prefix[1000]="";
        treeTraverse(root,prefix,fout);
        return;
    }
    void prH(ofstream &fout)
    {
        for(int i=0;i<36;++i)
        {
            fout<<keyToSym(i)<<" "<<H[i]<<"\n";
        }
    }
    
};
int main()
{
    ifstream fin;
    char str[1000];
    fin.open("log.txt");

    ofstream fout;
    fout.open( "output.txt");
    HuffMan hf;
    hf.init();
    int n;
    fin.getline(str,1000);
    n=atoi(str);
    
    for(int i=0;i<n;++i)
    {
        fin.getline(str,1000);
        //fout<<str<<endl;
        hf.insertStr(str);
    }
    fout<<"a="<<hf.getFreq('a');
    for(char ch='b';ch<='z';++ch)
    {
        fout<<","<<ch<<"="<<hf.getFreq(ch);
    }
    for(char ch='0';ch<='9';++ch)
    {
        fout<<","<<ch<<"="<<hf.getFreq(ch);
    }
    fout<<"\n";
    hf.makeLinkedList();
    //hf.pr();
    hf.superNode();
    hf.preOrderTraversal(fout);
    hf.treeTraverse(fout);
    hf.prH(fout);
    fin.close();
    fout.close();
    return 0;

}
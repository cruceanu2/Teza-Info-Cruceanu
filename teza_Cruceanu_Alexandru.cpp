/* Teza Cruceanu Alexandru
Exercitu: 1. stive simple*/
#include<iostream>
using namespace std;
struct Element
{
    int value;
    Element *next;
};
struct Stiva
{
    int length;
    Element *start, *finalist;
};
Stiva *mystack = new Stiva;
int init()
{
    mystack->length = 0;
    mystack->start = mystack->finalist = NULL;
}
int showlist()
{
    Element *calaret = new Element;
    calaret = mystack->start;
    for(int i = 0; i < mystack->length; i++)
    {
        cout<<calaret->value<<" ";
        calaret = calaret->next;
    }
    return 0;
}
int push(int toadd)
{
    Element *calaret = new Element;
    calaret->value = toadd;
    if(mystack->length == 0)
    {
        mystack->start = mystack->finalist = calaret;
        mystack->length++;
        return 0;
    }
    mystack->finalist->next = calaret;
    mystack->finalist = calaret;
    mystack->length++;
    return 0;
}
Element *searchforbeforefinalist()
{
    Element *ala_misto = new Element;
    ala_misto = mystack->start;
    for(int i = 1; i < mystack->length; i++)
    {
        ala_misto = ala_misto->next;
    }
    return ala_misto;
}
int pop()
{
    if(mystack->length == 0)
    {
        return 0;
    }
    if(mystack->length == 1)
    {
        mystack->finalist = mystack->start = NULL;
        mystack->length--;
        return 0;
    }
    Element *celdinainte = new Element;
    celdinainte = searchforbeforefinalist();
    delete mystack->finalist;
    mystack->finalist = celdinainte;
    mystack->length--;
    return 0;
}
int main()
{
    init();
    cout<<"Adaugam 3 elemente: "<<endl;
    for(int i = 1; i < 4; i++)
    {
        push(i);
        showlist();
        cout<<endl;
    }
    cout<<"Acum scoatem ce am pus: "<<endl;
    for(int i = 1; i < 4; i++)
    {
        pop();
        showlist();
        cout<<endl;
    }
}

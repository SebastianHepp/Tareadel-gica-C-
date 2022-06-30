/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;
void callMenuList();
void showList(bool);
void createList();
void addelementList();
void RemoveElementList();
void insertElementList(char product[15], int account, int position);


struct LIST{
    char product[15];
    int account;
    struct LIST *next;
};
    struct LIST *shoppinglist = NULL; // 0x00000000
    
void callMenuList(){
    int  option;
    do{
        cout<<endl<<endl<<"Manager of Shopping;" <<endl;
        cout<<"1- Show Shopping List."<<endl;
        cout<<"2- Add Article"<<endl;
        cout<<"3- Remove Article"<<endl;
        cout<<"4- Create default Shopping List"<<endl;
        cout<<"5- Exit"<<endl;
        cout<<"Type the option: ";
        cin>> option;
    }
    while(option<1 || option> 5);
    switch(option){
        case 1:
            showList(true); break;
        case 2:
            addelementList(); break;
        case 3:
            RemoveElementList(); break;
        case 4:
            createList(); break;
        case 5:
            break;
    }
}
void showList(bool optionalMenu){
    struct LIST *item= shoppinglist;
    
    cout<<"Shopping list: "<<endl<<endl;
    
    for (int i=1; item ;i++){
        cout<<"Article "<< i << ": " << item-> product << " x " <<item->account <<endl;
        item= item->next;
    }
    if (optionalMenu) callMenuList();
}


void RemoveElementList(){
    showList(false);
    
    int number;
    cout<<"Type the number of the article you want to Remove: ";
    cin>>number;
    
    if (number == 1 and shoppinglist != NULL) shoppinglist = shoppinglist->next;
    else{ 
        struct LIST *item= new LIST[1];
        item = shoppinglist;
        
        for (int i= 1; item; i++){
            if (number== i-1){
                if (item->next->next == NULL) item->next = NULL;
                else item-> next = item->next->next;
                
                item = NULL;
                delete[] item;
                
                
            }
            if (item) item=item->next;
        }
    }
    
    
    callMenuList();
}



void addelementList(){
    
    char product[15];
    int account;
    int position;
    
    showList(false);
    cout<<endl<< "Other number for the last position ";
    
    
    
    cout<<"Type the product you want to buy: ";
    cin>>product;
    cout<<"Type the account: ";
    cin>> account;
    cout<<"Type the position: ";
    cin>> position;
    insertElementList(product, account, position);
    
    
    callMenuList();
    
}

void  insertElementList(char product[15], int account, int position){
    struct LIST *article= new LIST[1];
    strcpy(article->product, product);
    article->account= account;
    article->next = NULL;
    
    struct LIST *item= new LIST[1];
    
    if (position ==1){
        article->next = shoppinglist;
        shoppinglist = article;
    }
    else{
        item = shoppinglist;
        for ( int i=1; item; i++){
            if ( i== position-1) break;
            item = item->next;
        }
        article-> next = item->next;
        item->next= article;
    }
    
    article= NULL;
    delete[] article;
    item=NULL;
    delete[] item;
}
void createList(){
    char product[15];
    strcpy(product, "gel");
    insertElementList (product, 2, 1);
    
    
    strcpy(product, "orange");
    insertElementList (product, 20, 2);
    
    
    strcpy(product, "chocolate");
    insertElementList (product, 50, 3);
    
    
    cout<<endl<< "Default shopping list added"<<endl;
    
    callMenuList();
}

int main()
{
    //callOperations();
    //callArrays();
    //callOrder();
    //callMultidimensionalArrays();
    callMenuList();
    
    cout<< "\n \n";
}


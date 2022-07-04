/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

void countdown(int number){
    cout << endl << number;
    if (number > 0){
        countdown(number - 1);
    } 
    else{
       cout<< endl << "BOOM"; 
    } 
}
int factorialRecursion(int number){
    
    if(number > 1){
        int aux;
        aux= factorialRecursion(number - 1);
        number = number * aux;
    }
    return number;
}

void hanoi(int n, int source, int destination, int aux){
    if(n > 0){
        hanoi(n-1, source, aux, destination);
        cout<<"Disco from position  "<< source<< " to " << destination<<endl;
        hanoi( n - 1, aux, destination, source);
    }
}

void callRecursion(){
    cout<<"---Nivel Principiante---";
    countdown(3);
    cout<<endl<<"---Nivel Medio---";
    cout<<endl<<"!5: " << factorialRecursion(3)<<endl;
    cout<<"---Nivel Avanzado---"<<endl;
    hanoi(4,1,3,2);
}

int main()
{
    callRecursion();
}

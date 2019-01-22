#include<iostream>

using namespace std;

void fibo(int first,int second,int howmany);
int factorial(int x);
int digitSum(int x);
void swap(int *x,int *y);
void search(int *p);

int main(){
    int a=20 , b=10 , array[]={10,25,60,15,27,13};

    fibo(0,1,6);

    cout<<"FACTORIAL : "<< factorial(4) <<endl;

    cout<<"Sum of digit : "<< digitSum(567) <<endl;

    swap(&a,&b);

    search(array);

    return 0;
}

void fibo(int first,int second,int howmany){
    int tmp;

    cout<<"Fibonacci numbers : ";

    for(int i=0;i<howmany;i++){
        cout<<first;

        if(i+1<howmany){
            cout<<",";
        }

        tmp = first;
        first = second;
        second = tmp;
        first = first+tmp;
    }

    cout<<endl;
}

int factorial(int x){
    int factorial = 1;

    for(x;x>0;x--){
        factorial = x*factorial;
    }

    return factorial;
}

int digitSum(int x){
    int tmpNum , sum=0;

    while(x!=0){
        tmpNum = x%10;
        x = x/10;
        sum = sum + tmpNum;
    }

    return sum;
}

void swap(int *x,int *y){
    int tmpNum = *x;
    *x = *y;
    *y = tmpNum;

    cout<<"After swapping : "<<*x<<","<<*y<<endl;
}

void search(int *p){
    int FirstMax=0 , SecondMax;
    int size = sizeof(p);
    cout<<size<<endl;

    for(int i=0;i<6;i++){
        if(p[i]>FirstMax){
            SecondMax = FirstMax;
            FirstMax = p[i];
        }
    }

    cout<<"First maximum number is : "<<FirstMax<<endl;
    cout<<"Second maximum number is : "<<SecondMax<<endl;
}

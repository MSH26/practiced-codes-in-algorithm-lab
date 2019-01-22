#include<iostream>

using namespace std;

int fact(int x){

    if(x==0){
        return 1;
    }

    return fact(x-1)*x;
}

int NaturalOdd(int x){
    if(x==0){
        return 1;
    }
    return NaturalOdd(x-1)+2;
}

int power(int x){
    if(x==0){
        return 1;
    }
    return power(x-1)*2;
}

int K_th_EvenNum(int k){
    if(k==0){
        return 0;
    }
    return K_th_EvenNum(k-1)+2;
}

int K_th_PowerNum(int k){
    if(k==0){
        return 1;
    }
    return K_th_PowerNum(k-1)*2;
}

int SeqSearch(int L[],int i,int j,int x){
    if(i<=j){
        if(L[i]==x){
            return i;
        }
        else{
            return SeqSearch(L,i+1,j,x);
        }
    }
    else
        return 0;
}

int Func1(int x){
    if(x==0){
        return 2;
    }
    return Func1(x-1)+2;
}

int Func2(int x){
    if(x==0){
        return 2;
    }
    return Func2(x-1)*3;
}

int Func3(int x){
    if(x==0){
        return 2;
    }
    return Func3(x-1)*2;
}

int Func(int x){
    cout<<Func1(x)<<endl;
    cout<<Func2(x)<<endl;
    cout<<Func3(x)<<endl;
}

int Com_Func_a(int x){
    if(x==0){
        return 1;
    }
    else if(x<0){
        return 0;
    }
    else{
        return Com_Func_a(x-1)+(Com_Func_a(x-2)*3);
    }
}

int Com_Func_b(int x){
    if(x==0){
        return 1;
    }
    return Com_Func_b(x-1)*Com_Func_b(x-1)*Com_Func_b(x-1);
}

int Com_Func(int x){
    cout<<Com_Func_a(x)<<endl;
    cout<<Com_Func_b(x)<<endl;
}

int SumEven(int x){
    if(x==0){
        return 0;
    }
    return SumEven(x-1)+2*x;
}

int SumOdd(int x){
    if(x==0){
        return 1;
    }
    return SumOdd(x-1)+2*(x-1)-1;
}

int Mult(int x,int y){
    if(y==0){
        return 1;
    }
    return Mult(x,y-1)*x;
}

int fibo(int x,int y){
    cout<<x<<" ";
    if(x<20){
        fibo(y,x+y);
    }
}

int main(){
    int tmpVar1, arr[]={2,4,5,0,13};

    //cin>>tmpVar1;

 //   cout<<fact(tmpVar1)<<endl;

 //   cout<<NaturalOdd(tmpVar1)<<endl;

 //   cout<<power(tmpVar1)<<endl;

 //   cout<<K_th_EvenNum(tmpVar1)<<endl;

 //   cout<<K_th_PowerNum(tmpVar1)<<endl;

 //   cout<<SeqSearch(arr,0,4,0)+1<<endl;

 //   Func(tmpVar1);

 //   Com_Func(tmpVar1);

 //   cout<<SumEven(tmpVar1);

 //   cout<<SumOdd(tmpVar1);

 //   cout<<Mult(5,4)<<endl;

    fibo(0,1);

    return 0;
}

#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
#include<string>

using namespace std;

queue<int>Q;

int decimalToBinary(int x);
int binaryToDecimal(int x);
int naiveMultiplication(int x, int y);
int naiveMultiplicationVersion2(int x, int y);
void swapFunction(int x, int y);
void insertion(int arr[] , int N);
void selection(int a[],int N);
void bouble(int a[],int N);


int main(){
    int var1=4 , var2=8 , size;
    int arr[]={3,5,1,9,8};
    size = 5;

    cout<< decimalToBinary(var1)<<endl;
    cout<< binaryToDecimal(decimalToBinary(var1))<<endl;
    cout<< naiveMultiplication(var1 , var2)<<endl;
    cout<< naiveMultiplicationVersion2(var1 , var2)<<endl;
 /*
    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size];
    cout<<"Enter arrray elements : ";

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
 */
    insertion(arr , size);
    cout<<endl;
    selection(arr , size);
    cout<<endl;
    bouble(arr , size);
    cout<<endl;

    return 0;
}

int decimalToBinary(int x){
    int remainder,TmpMult=1,BinaryNum=0;
    while(x!=0){
        remainder=x%2;
        Q.push(remainder);
        BinaryNum=BinaryNum+remainder*TmpMult;
        TmpMult=TmpMult*10;
        x=x/2;
    }

    return BinaryNum;
}
int binaryToDecimal(int x){
    int remainder,count=0, DecimalNum=0;

    while(x>0){
        remainder = x%2;
        x = x/10;
        DecimalNum = DecimalNum + remainder*pow(2,count);
        count++;
    }

    return DecimalNum;
}

int naiveMultiplication(int x, int y){
    int count=1 , Mult=0;

    while(count<=x){
        Mult = Mult + y;
        count++;
    }

    return Mult;
}

int naiveMultiplicationVersion2(int x, int y){

    y = y<<x;
    cout<<y;

    return y;
}

void swapFunction(int x, int y){
    //x =
}

void selection(int a[],int N){
    int Smallsub , tmp;

    for(int i=0;i<N-1;i++){
        Smallsub = i;
        for(int j=i+1;j<N-1;j++){
            if(a[j]<a[Smallsub]){
                Smallsub = j;
            }
        }
        tmp = a[i];
        a[i] = a[Smallsub];
        a[Smallsub] = tmp;
    }

    for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
}

void insertion(int arr[] , int N){
    int j,tmp;
    for(int i=1;i<N;i++){
        j=i;
        while(j>0 && arr[j]<arr[j-1]){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j = j-1;
        }
    }

    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
}

void bouble(int a[],int N){

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(a[i]>a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
}

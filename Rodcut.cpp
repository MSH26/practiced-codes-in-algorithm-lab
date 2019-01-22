#include<iostream>

using std::cin;
using std::cout;
using std::endl;


void bottomUpRodcut(int n , int* price , int* revenue);
int max(int x , int y);


int main(){
int n=8;
    int p[] = {1,5,8,9,10,17,17,20} , r[] = {0,0,0,0,0,0,0,0,0 };

    bottomUpRodcut(n , p , r);

    return 0;
}

void bottomUpRodcut(int n , int* price , int* revenue){

    int q ;
    revenue[0]=0;

    for(int j=0 ; j<=n ; j++){
        q = -1 ;
        for(int i=0 ; i<=j ; i++){
            q = max(q , price[i]+revenue[j-i]);
        }
        revenue[j+1] = q ;
    }

    for(int i=1 ; i<=n ; i++){
        cout<<revenue[i]<<endl;
    }

}

int max(int x , int y){

    if(x<y){
        return y;
    }

    return x;
}

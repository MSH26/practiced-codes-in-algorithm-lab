#include<iostream>

using std::cin;
using std::cout;
using std::endl;


void extendedBottomUpRodcut(int n , int* price , int* revenue , int* CuttingPoint);
int max(int x , int y);


int main(){
    int n=8;
    int p[] = {1,5,8,9,10,17,17,20} , r[] = {0,0,0,0,0,0,0,0,0} , s[] = {};

    extendedBottomUpRodcut(n , p , r ,s);

    return 0;
}

void extendedBottomUpRodcut(int n , int* price , int* revenue , int* CuttingPoint){

    int q ;
    revenue[0]=0;

    for(int j=0 ; j<=n ; j++){
        q = -1 ;
        for(int i=0 ; i<=j ; i++){
            if(q < price[i]+revenue[j-i]){
                q = price[i]+revenue[j-i];
                CuttingPoint[j] = i;
            }
        }
        revenue[j+1] = q ;
    }

    for(int i=1 ; i<=n ; i++){
        cout<<revenue[i]<<" ";
    }

    for(int i=1 ; i<n ; i++){
        cout<<CuttingPoint[i]<<" ";
    }


}

int max(int x , int y){

    if(x<y){
        return y;
    }

    return x;
}

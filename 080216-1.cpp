#include<iostream>

using namespace std;

int BinarySearch(int A[],int value,int low,int high);
int Binary_Search_I(int A[], int key, int low, int high);
void Merge(int A[],int p,int q,int r);
void MergeSort(int A[],int p,int r);
void selection(int a[],int N);
void insertion(int arr[] , int N);
void bouble(int a[],int N);
void Counting();
int Partision(int A[],int p,int r);
void QuickSort(int A[],int p,int r);



int BinarySearch(int A[],int value,int low,int high){
    int mid;

    if(high<low){
        cout<<"Not found!!!"<<endl;
        return NULL;
    }

    mid = (low+high)/2;

    if(A[mid]>value){
        return BinarySearch(A,value,low,mid-1);
    }

    else if(A[mid]<value){
        return BinarySearch(A,value,mid+1,high);
    }

    else{
        cout<<"Found!!!"<<endl;
        return mid;
    }
}

int Binary_Search_I(int A[], int key, int low, int high){
    int mid;
    while(low<=high){

        mid = (low+high)/2;

        if(A[mid]>key){
            high = mid-1;
        }

        else if(A[mid]<key){
            low = mid + 1;
        }

        else{
            cout<<"Found!!!"<<endl;
            return mid;
        }
    }

    cout<<"Not found"<<endl;

    return NULL;
}

void Merge(int A[],int p,int q,int r){
    int i , j , k , B[r+1];

    k = p;
    i = p;
    j = q+1;

    while(i<=q && j<=r){
        if(A[i]<=A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }

    while(i<=q){
        B[k++] = A[i++];
    }

    while(j<=r){
        B[k++] = A[j++];
    }

    for(i=p ; i<(r+1) ; i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[],int p,int r){
    int q;

    if(p<r){
        q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
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
}

void Counting(){

}

int Partision(int A[],int p,int r){
    int x , i;

    x = A[r];
    i = p-1;

    for(int j=p ; j<r ; j++){
        if(A[j]<=x){
            i = i+1;
            A[i] = A[j];
        }
    }

    A[i+1] = A[r];

    return i+1;
}

void QuickSort(int A[],int p,int r){
    int q;

    if(p<r){
        q = Partision(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main(){
    int value , arr[]={2,5,6,7,10} ,arry[]={5,7,2,6,4,9,1,15,4,50,8,0};

    cin>>value;
    cout<<endl;

    BinarySearch(arr,value,-1,4);
    Binary_Search_I(arr,value,-1,4);

    //MergeSort(arry,0,11);

    insertion(arry , 11);
    selection(arry , 11);
    bouble(arry , 11);

    QuickSort(arry,0,11);

    for(int i=0;i<12;i++){cout<<arry[i]<<" ";}

    return 0;
}

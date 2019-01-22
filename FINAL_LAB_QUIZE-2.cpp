#include<iostream>
#include<climits>

using namespace std;

class Graph{

    int **adjMatrix;
    int vertexCount;

    int* key;
    int* distance;
    int* parent;

    int minMstCost;

public:

    Graph( int vertex ){

        vertexCount = vertex ;

        this->key = new int[vertexCount] ;
        this->distance = new int[vertexCount] ;
        this->parent = new int[vertexCount] ;

        minMstCost = 0 ;

        this->adjMatrix = new int* [vertexCount] ;

        for( int i=0 ; i<vertexCount ; i++ ){

            this->adjMatrix[i] = new int[vertexCount] ;

            for( int j=0 ; j<vertexCount ; j++ ){

                this->adjMatrix[i][j] = 0 ;
               // this->adjMatrix[j][i] = 0 ;
            }
        }
    }

    ~Graph(){
        for( int i=0 ; i<vertexCount ; i++ ){
            delete[] adjMatrix[i] ;
            delete[] adjMatrix ;
        }
    }

    void initialize(){
        for(int i=0 ; i<vertexCount ; i++ ){
            this->key[i] = 0 ;
            this->distance[i] = INT_MAX ;
            this->parent[i] = -1 ;
        }
    }

    void addWeightedEdge( int i , int j , int cost ){
        this->adjMatrix[i][j] = cost ;
        this->adjMatrix[j][i] = cost ;
    }

    void removeEdge( int i , int j ){
        this->adjMatrix[i][j] = 0 ;
        this->adjMatrix[j][i] = 0 ;
    }

    void display(){
        for( int i=0 ; i<vertexCount ; i++ ){

            for( int j=0 ; j<vertexCount ; j++ ){
                    cout<<adjMatrix[i][j]<<" ";
            }

            cout<<endl;
        }
    }

    void showKeyInfo(){
        for(int i=0 ; i<vertexCount ; i++ ){
            cout<<"Key of"<<i<<" is "<<key[i]<<endl;
        }
    }

    void showParentInfo(){
        for(int i=0 ; i<vertexCount ; i++ ){
            cout<<"Parent of"<<i<<" is "<<parent[i]<<endl;
        }
    }

    void showDistanceInfo(){
        for(int i=0 ; i<vertexCount ; i++ ){
            cout<<"Distance of"<<i<<" is "<<distance[i]<<endl;
        }
    }

    bool isEdge(int i , int j ){
        if(i>=0 && i<vertexCount && j>=0 && j<vertexCount){
            return adjMatrix[i][j];
        }
        return 0;
    }

    bool isAllKeyTrue(){
        for(int i=0 ; i<vertexCount ; i++ ){
            if( key[i]==0 ){
                return 0;
            }
        }
        return 1 ;
    }

    int findMinMstNode(){
        int minMstNode , minMstNodeDistance ;
        minMstNodeDistance = INT_MAX ;

        for(int i=0 ; i<vertexCount ; i++ ){
            if(minMstNodeDistance > this->distance[i] && this->key[i]==0){
                minMstNode = i;
                minMstNodeDistance = this->distance[i];
            }
        }

        return minMstNode ;
    }

    void MST_Prims(int startNode){
        int minMstNode;// = startNode ;

        initialize();

        this->distance[startNode] = 0 ;

        while(!this->isAllKeyTrue()){

            minMstNode = findMinMstNode() ;
            key[minMstNode] = 1 ;
            minMstCost += this->distance[minMstNode] ;

            for( int i=0 ; i<vertexCount ; i++ ){
                if( this->isEdge(minMstNode,i) && this->key[i]==0 && this->distance[i]>adjMatrix[minMstNode][i]){
                    this->parent[i] = minMstNode ;
                    this->distance[i] = adjMatrix[minMstNode][i] ;
                }
            }
        }
    }

    int MST_Cost(){
        return minMstCost ;
    }
};


int main(){
    Graph G1(10) ;

    G1.addWeightedEdge( 0 , 1 , 4 ) ;
    G1.addWeightedEdge( 0 , 3 , 1 ) ;
    G1.addWeightedEdge( 1 , 2 , 4 ) ;
    G1.addWeightedEdge( 1 , 3 , 4 ) ;
    G1.addWeightedEdge( 3 , 7 , 5 ) ;
    G1.addWeightedEdge( 3 , 9 , 6 ) ;
    G1.addWeightedEdge( 1 , 9 , 10 ) ;
    G1.addWeightedEdge( 2 , 4 , 2 ) ;
    G1.addWeightedEdge( 2 , 5 , 1 ) ;
    G1.addWeightedEdge( 4 , 6 , 2 ) ;
    G1.addWeightedEdge( 5 , 6 , 3 ) ;
    G1.addWeightedEdge( 5 , 8 , 5 ) ;
    G1.addWeightedEdge( 6 , 8 , 3 ) ;
    G1.addWeightedEdge( 6 , 9 , 4 ) ;
    G1.addWeightedEdge( 8 , 9 , 3 ) ;
    G1.addWeightedEdge( 7 , 9 , 2 ) ;

    G1.display() ;

    G1.MST_Prims(0) ;
    cout<<G1.MST_Cost()<<endl ;
    cout<<endl;

    G1.showDistanceInfo();
    G1.showParentInfo();
    G1.showKeyInfo();

    return 0 ;
}

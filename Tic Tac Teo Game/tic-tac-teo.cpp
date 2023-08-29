/******************************************************************************

XO Game ./ Project for Dr.Mostafa Saad . Multidimentional Arrays Hard homework.

*******************************************************************************/

#include <iostream>

using namespace std;
int checkRow(int x , int arr[][100] , int n ){
    int num = arr[x][0] ;
    for(int j = 1 ; j < n ; j++){
        if(arr[x][j] != arr[x][j-1]){
            return 0 ;
        }
    }
    return num ;
}

int checkCol(int j , int arr[][100] , int n ){
    int num = arr[0][j] ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i][j] != arr[i-1][j]){
            return 0 ;
        }
    }
    return num ;
}

int checkMainDiag(int arr[][100] , int n ){
    int num = arr[0][0] ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i-1][i-1] != arr[i][i]){
            return 0 ;
        }
    }
    return num ;
}

int checkSecDiag(int arr[][100] , int n ){
    int num = arr[0][n-1] ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i][n-i-1] != arr[i-1][n-i]){
            return 0 ;
        }
    }
    return num ;
}

void display(int arr[][100] , int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i][j] == 1){ cout<<'x' ; }else if(arr[i][j] == 2){ cout<< 'o' ;}else{cout<<'.' ;} 
        }
        cout<<"\n";
    }
}


int main()
{
     int n ;              cout<<"Enter grid dimentions : " ;        cin>> n ; int arr[100][100] ; // 0 for empty 1 for x  2 for o .
    
    int steps = n*n ;
    int turn = 0 ;
    int x , y ;
    while(steps){
        
        if(turn == 0){
            char ch = 'x' ;
            cout<<"Player " << ch << " turn. "<<"Enter empty location (r , c ) " ;          cin>>x >> y ;
            if(arr[x-1][y-1] != 0 || x > n || y > n || x < 1 || y < 1){
                cout<<"\nEnter valid location \n" ;
                continue ;
            }else{
                arr[x-1][y-1] = 1 ;
                display(arr, n ) ;
                turn = 1 ;
                steps-- ;
            }
        }else{
            char ch = 'o' ;
            cout<<"Player " << ch << " turn. "<<"Enter empty location (r , c ) " ;          cin>>x >> y ;
            if(arr[x-1][y-1] != 0 || x > n || y > n || x < 1 || y < 1){
                cout<<"\nEnter valid location \n" ;
                continue ;
            }else{
                arr[x-1][y-1] = 2 ;
                display(arr , n) ;
                turn = 0 ;
                steps-- ;
            }
        }
        
        int max = 0 ;
        if(max < checkRow(x-1 , arr , n) ) {
            max = checkRow(x-1 , arr ,n ) ;
        }
        if(max < checkCol(y-1 , arr , n) ) {
            max = checkCol(y-1 , arr ,n ) ;
        }
        if(max < checkMainDiag(arr , n) ){
            max = checkMainDiag(arr , n) ;
        }
        if(max < checkSecDiag(arr , n) ) {
            max = checkSecDiag(arr , n ) ;
        }
        if(max != 0 ){
            cout<<"Player " ;
            if(max ==1 ){cout<<'x' ;} else if(max == 2){cout<<'o' ; }
            cout<<" win \n" ;
            return 0 ;
        }
    }
    
    cout<<"tie" ;

    return 0;
}

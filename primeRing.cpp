#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int );
void dfs(int* , int , int );

int main(int argc, char** argv){
    int cur = 1;
    int size;
    while(cin >> size){
        int* arr = new int[size];
        arr[0] = 1;
        dfs(arr, size, cur);
        delete [] arr;
    }
    return 0;
}

bool isPrime(int n) { 
    if (n <= 1) return false; 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) return false; 
    return true; 
} 

void dfs(int* arr, int size, int cur){
    if(cur == size && isPrime(arr[0] + arr[size-1])){
        for(int i = 0; i < size; ++i) cout << arr[i] << ' ';
        cout << endl;
    } else{
        for(int i = 2; i <= size; ++i){
            if(!isPrime(arr[cur-1] + i)) continue;
            bool flag = true;
            for(int j = 1; j < cur; ++j){
                if(arr[j] == i) flag = false; 
            }
            if(flag){
                arr[cur] = i;
                dfs(arr, size, cur+1);
            }    
        }
    }
}

#include<ctime>
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<vector>
using namespace std;

int increaseCount(vector<int>& arr, int index){
    assert(index >= 0);
    int count = 1;
    if(index == 0){
        return 1;
    }
    for(int i = index; i > 0; --i){
        if(arr[i] <= arr[i - 1])
            return count;
        ++count;
    }
    return count;
}

int decreaseCount(vector<int>& arr, int index){
    assert(index >= 0);
    int count = 1;
    if(index == arr.size() - 1){
        return 1;
    }
    for(int i = index; i < arr.size() - 1; ++i){
        if(arr[i] <= arr[i + 1])
            return count;
        ++count;
    }
    return count;
}

int maxof(int first, int second){
    if(first > second){
        return first;
    }
    return second;
}

int candies(int n, vector<int> arr) {
    int totalCandies = 0;
    vector<int> distribution;
    for(int i = 0; i < n; ++i){
        totalCandies += maxof(increaseCount(arr, i), decreaseCount(arr, i));
    }
    return totalCandies;
}

int main(int argc, char** argv){
    int size, read;
    cin >> size;
    vector<int> candy;
    candy.reserve(size);
    for(int i = 0; i < size; ++i){
        cin >> read;
        candy.push_back(read);
    }
    clock_t start = clock();
    int total = candies(size, candy);
    clock_t totalTime = clock() - start;
    cout << total << endl;
    cout << totalTime << endl; 
    return 0;
}

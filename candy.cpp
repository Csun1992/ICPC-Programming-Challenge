/* Challenge Description: 
   
   Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  All
the children sit in a line and each of them has a rating score according to his or her performance
in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each
other, then the one with the higher rating must get more candies. Alice wants to minimize the total
number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. She gives the students candy in
the following minimal amounts: [1, 2, 1, 2, 3, 1]. She must buy a minimum of 10 candies.

Function Description

Complete the candies function in the editor below. It must return the minimum number of candies
Alice must buy.

candies has the following parameter(s):

    n: an integer, the number of children in the class
    arr: an array of integers representing the ratings of each student
         Input Format

         The first line contains an integer, , the size of . 
         Each of the next  lines contains an integer  indicating the rating of the student at
         position .

         Constraints

         Output Format

         Output a single line containing the minimum number of candies Alice must buy.

*/






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

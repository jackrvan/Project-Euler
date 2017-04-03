#include<iostream>
#include<map>
#include<cmath>
#include<vector>

using namespace std;

int getFactors(int a, map<int, int> &myMap) {
    int numFactors = 0;
    if(a % 2 == 0) ++numFactors;
    while(a % 2 == 0) {
        //How many times does two go into our number
        myMap[2]++;
        a /= 2;
    }
    for(int i = 3; i <= a/2; i += 2) {
        //How many times does 3,5,7,9... go into our number
        if(a % i == 0) ++numFactors;
        while(a % i == 0) {
            myMap[i]++;
            a /= i;
        }
    }
    if(a > 2) {
        //This means we ended up with a prime at the end which we must add to our factor list
        myMap[a]++;
        ++numFactors;
    }
    return numFactors;
}

bool differentFactors(vector<map<int, int>> myMap) {
    for(auto it = myMap[0].begin(); it != myMap[0].end(); ++it) {
        //Compare our first map with our 2, 3, and 4 map to make sure no duplicated
        if((it->second == (myMap[1][it->first])) || (it->second == (myMap[2][it->first])) || (it->second == (myMap[3][it->first]))) { return false; }
    }
    for(auto it = myMap[1].begin(); it != myMap[1].end(); ++it) {
        //Compare second map to map 3 and 4 to ensure no duplicates
        if(((it->second > 0) && (it->second == (myMap[2][it->first]))) || ((it->second > 0) && (it->second == myMap[3][it->first]))) { return false; }
    }
    for(auto it = myMap[2].begin(); it != myMap[2].end(); ++it) {
        //Compare map 3 and 4
        if((it->second > 0 && (it->second == myMap[3][it->first]))) { return false; }
    }
    return true; //No duplicates
}

int main() {
    int a;
    for(a = 2; ; ++a) {
        vector<map<int, int>> myMap(4); //vector of maps
        int num = getFactors(a, myMap[0]);
        int num2 = getFactors(a+1, myMap[1]);
        int num3 = getFactors(a+2, myMap[2]);
        int num4 = getFactors(a+3, myMap[3]);
        if(num != 4 || num2 != 4 || num3 != 4 || num4 != 4) { continue; } //Make sure each number has 4 factors
        if(differentFactors(myMap)) break;
    }
    cout << a << endl;
}

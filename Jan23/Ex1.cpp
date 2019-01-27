
/*
Baker as you know, is a Smart cat, he won regionals and classified to the next cat programming World Finals. Baker is planning his trip in which he has to travel a distance of exactly X kilometers. Baker wants to travel in several days (always more than one) so he can get to know and visit more places and also avoid jetlag. 
For his trip, Baker decided that the first day he will travel for d kilometers, the second day he will travel for d+1, the next one d+2 and so on until he arrives at his destination traveling exactly X kilometers. 
Baker’s owner knows how annoying is to do a lot of short trips, she wants Baker to travel the longest possible distance in the first day, so that he can have a more enjoying trip to the World Finals. Help Baker to find what should be his initial distance d.
Input:
3
2012
30
7

Output:
case 1: 248
case 2: 9
case 3: 3
*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int x, sum, j;
    bool canFinish;

    for (int i = 0; i < t; i++) {
        canFinish = true;
        sum = 1;
        j = 2;
        cin >> x;
        while ((x - sum) % j != 0 && canFinish) {
            if (sum > x)
                canFinish = false;
            sum += j;
            j++;
        }
        if (canFinish)
            cout << (x - sum) / j << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
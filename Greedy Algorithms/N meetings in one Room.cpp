#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Meeting {
    int start;
    int end;
    int index;
};

bool compareMeetings(const Meeting& a, const Meeting& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.index < b.index;
}


int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    int count=1;
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].index = i + 1; 
    }

    sort(meetings.begin(), meetings.end(), compareMeetings);

    vector<int> result;
    int lastEndTime = -1; 

    for (int i = 1; i < n; ++i) {
        
        if (meetings[i].start >= lastEndTime) {
            count=count+1;
            result.push_back(meetings[i].index);
            lastEndTime = meetings[i].end;
        }
    }

    return count;
}

int main() {
 
    vector<int> start1 = {0,3,1,5,5,8};
    vector<int> end1 = {5,4,2,9,7,9};
    int scheduledMeetings1 = maxMeetings(start1, end1);

    cout << "Total Scheduled meetings : "<<scheduledMeetings1;
   
    cout << endl; 


    return 0;
}


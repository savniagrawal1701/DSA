#include <bits/stdc++.h>
using namespace std;
class ShortestJobFirst {
public:
   
    float calculateAverageWaitTime(vector<int>& jobs) {
       
        sort(jobs.begin(), jobs.end());

        float waitTime = 0;  
        int totalTime = 0;  
        int n = jobs.size(); 

        for (int i = 0; i < n; i++) {
            waitTime += totalTime; 
            totalTime += jobs[i];  
        }

        return waitTime / n;
    }
};

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for (int job : jobs) cout << job << " ";
    cout << endl;

    ShortestJobFirst sjf;
    float ans = sjf.calculateAverageWaitTime(jobs);

    cout << "Average waiting time: " << ans << endl;
    return 0;
}
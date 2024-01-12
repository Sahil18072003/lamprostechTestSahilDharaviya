#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareJobs(const pair<int, int> &job1, const pair<int, int> &job2)
{
    return job1.second > job2.second; // Sort jobs by deadlines in descending order
}

vector<pair<int, int>> jobScheduling(vector<pair<int, int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    vector<int> schedule(n, 0);    // Initialize an array to store the schedule
    vector<pair<int, int>> result; // Initialize a vector to store the final schedule

    return result;
}

int main()
{
    // Example usage
    vector<pair<int, int>> jobs = {{1, 2}, {2, 1}, {3, 3}};
    vector<pair<int, int>> outputSchedule = jobScheduling(jobs);

    // Display the schedule
    cout << "Scheduled Jobs:" << endl;

    return 0;
}

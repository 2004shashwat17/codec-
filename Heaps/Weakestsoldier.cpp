#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define a Row class to store row data
class Row {
public:
    int count; // Number of soldiers in the row
    int idx;   // Index of the row

    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    // Overload the < operator for min-heap priority queue
    bool operator<(const Row& obj) const {
        if (this->count == obj.count) { // Compare by count first
            return this->idx > obj.idx; // If counts are equal, compare by index
        }
        return this->count > obj.count; // Min-heap: smallest count first
    }
};

// Function to find the K weakest rows
void weakestSoldier(vector<vector<int>> matrix, int K) {
    vector<Row> rows;

    // Count the soldiers in each row
    for (int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        rows.push_back(Row(count, i));
    }

    // Create a priority queue (min-heap) with the rows
    priority_queue<Row> pq(rows.begin(), rows.end());

    // Output the K weakest rows
    cout << "The " << K << " weakest rows are:" << endl;
    for (int i = 0; i < K && !pq.empty(); i++) {
        cout << "Row " << pq.top().idx << " with " << pq.top().count << " soldiers." << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };

    weakestSoldier(matrix, 2);
    return 0;
}

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Standard solution:
// Complexity Analysis:
// Time Complexity: O(n + n log(weightsT - maxW + 1)) ~ O(n log(weightsT)), where n is the number
// of packages and weightsT is the total weight of all packages. The initial for loop iterates
// through all n packages to calculate weightsT and maxW, costing O(n). The binary search then
// searches the ship-capacity range [maxW, weightsT], which contains weightsT - maxW + 1 possible
// capacities, requiring O(log(weightsT - maxW + 1)) iterations. For each binary-search iteration,
// the inner for loop scans the packages and performs O(1) work per package, costing O(n) in the
// worst case. Therefore, the total time complexity is
// O(n + n log(weightsT - maxW + 1)) ~ O(n log(weightsT)).
// Space Complexity: O(1), where n is the number of packages. The algorithm uses only a constant
// amount of extra space for the variables weightsS, weightsT, maxW, shipWMax, shipWMin, shipW,
// searchS, mid, tempT, and daysT. No additional data structures whose size depends on n are
// allocated.

class Solution {
  public:
    int shipWithinDays(vector<int>& weights, int days) {
        int weightsT = 0;
        int maxW = 0;

        for (const int& weight : weights) {
            maxW = max(weight, maxW);
            weightsT += weight;
        }

        int shipWMax = weightsT;
        int shipWMin = maxW;
        int shipW = 0;

        while (shipWMax >= shipWMin) {
            int searchS = shipWMax - shipWMin;
            int mid = shipWMin + searchS / 2;
            int tempT = 0;
            int daysT = 1;

            for (const int& weight : weights) {
                if (tempT + weight > mid) {
                    daysT++;
                    tempT = 0;
                }

                tempT += weight;
            }

            if (daysT <= days) {
                shipW = mid;
                shipWMax = mid - 1;
            } else {
                shipWMin = mid + 1;
            }
        }

        return shipW;
    }
};

// My optimized solution:
// Complexity Analysis:
// Time Complexity: O(n + n log(shipWMax - shipWMin + 1)) ~ O(n log(shipWMax)), where n is the
// number of packages. The initial for loop processes all n packages once to calculate
// tShipWMax, maxW, and the chunk-based shipWMax, costing O(n). The binary search then operates
// over the capacity range [shipWMin, shipWMax], which contains shipWMax - shipWMin + 1 possible
// capacities, requiring O(log(shipWMax - shipWMin + 1)) iterations. For each binary-search
// iteration, the inner for loop scans all n packages in the worst case, costing O(n). Therefore,
// the total time complexity is
// O(n + n log(shipWMax - shipWMin + 1)) ~ O(n log(shipWMax)).
// Space Complexity: O(1), where n is the number of packages. The algorithm uses only a constant
// amount of extra space for the variables weightsS, avgWPD, shipWMax, maxW, tShipWMax, chunkSize,
// shipWMin, shipW, searchS, mid, tempT, and daysT. No additional data structures whose size
// depends on n are allocated.

class Solution {
  public:
    int shipWithinDays(vector<int>& weights, int days) {
        int weightsS = static_cast<int>(weights.size());
        int avgWPD = (weightsS + days - 1) / days;
        int shipWMax = 0;
        int maxW = 0;
        int tShipWMax = 0;
        int chunkSize = 0;

        for (const int& weight : weights) {
            tShipWMax += weight;
            maxW = max(weight, maxW);

            if (++chunkSize == avgWPD) {
                shipWMax = max(tShipWMax, shipWMax);
                tShipWMax = 0;
                chunkSize = 0;
            }
        }

        shipWMax = max(tShipWMax, shipWMax);
        int shipWMin = max(maxW, avgWPD);
        int shipW = 0;

        while (shipWMax >= shipWMin) {
            int searchS = shipWMax - shipWMin;
            int mid = shipWMin + searchS / 2;
            int tempT = 0;
            int daysT = 1;

            for (const int& weight : weights) {
                if (tempT + weight > mid) {
                    daysT++;
                    tempT = 0;
                }

                tempT += weight;
            }

            if (daysT <= days) {
                shipW = mid;
                shipWMax = mid - 1;
            } else {
                shipWMin = mid + 1;
            }
        }

        return shipW;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    // Find the minimum ship capacity
    int result = solution.shipWithinDays(weights, days);

    // Print the result
    cout << result << "\n";

    return 0;
}
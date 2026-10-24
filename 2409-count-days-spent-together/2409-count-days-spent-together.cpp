class Solution {
    private:
    // Days in each month for a non-leap year
    const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" to day number (1 to 365)
    int dateToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        int totalDays = 0;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonth[i];
        }
        return totalDays + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {  // Convert all input strings to day numbers
        int aliceStart = dateToDayOfYear(arriveAlice);
        int aliceEnd = dateToDayOfYear(leaveAlice);
        int bobStart = dateToDayOfYear(arriveBob);
        int bobEnd = dateToDayOfYear(leaveBob);
        
        // Find the intersection window
        int startOverlap = std::max(aliceStart, bobStart);
        int endOverlap = std::min(aliceEnd, bobEnd);
        
        // If they overlap, return the total inclusive days; otherwise 0
        if (startOverlap <= endOverlap) {
            return endOverlap - startOverlap + 1;
        }
        
        return 0;
        
    }
};
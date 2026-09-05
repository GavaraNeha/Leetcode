class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0)
                    return false;

                five--;
                ten++;
            }
            else { // bill == 20
                // Prefer using one $10 and one $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // Otherwise use three $5 bills
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
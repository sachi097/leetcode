class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        reverse(sandwiches.begin(), sandwiches.end());
        int left = 0, size = 0, right = students.size() - 1;
        while(sandwiches.size() && size != sandwiches.size()){
            size = sandwiches.size();
            while(left <= right && students[left] != *sandwiches.rbegin()){
                students.push_back(students[left++]);
            }
            if(left > right){
                break;
            }
            left++;
            sandwiches.pop_back();
            right = students.size() - 1;
        }
        return students.size() - left;
    }
};


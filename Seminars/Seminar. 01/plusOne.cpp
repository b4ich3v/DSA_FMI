#include <iostream>
#include <vector>

class Solution 
{
public:

    std::vector<int> plusOne(std::vector<int>& digits)
    {
      
        int index = digits.size() - 1;
      
        while (index >= 0 && digits[index] == 9) 
        {
          
            digits[index] = 0;  
            index--;            
          
        }
      
        if (index < 0) 
        {
          
            digits.insert(digits.begin(), 1);
          
        } 
        else 
        {
          
            digits[index]++;
          
        }

        return digits;  
      
    }

};

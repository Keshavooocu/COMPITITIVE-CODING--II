class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int csum=0;
            while(num>0){
                csum += num %10;
                num /= 10 ;
            }
            num = csum;
        }
        return num;
        
    }
};
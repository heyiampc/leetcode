class Solution {
public:
    int addDigits(int num) {       
        int sum=0;
        do
        {
            sum=0;
        while(num)
        {
            // cout<<sum<<" "<<num<<endl;
            sum+=num%10;
            num/=10;
        }
            num=sum;
    }while(sum>9);
        return sum;
    }
};
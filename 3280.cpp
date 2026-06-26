// You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
// date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
// Return the binary representation of date.

class Solution {
private:
    string toBinary(int num){
        if(num==0){
            return "0";
        }
        string bin="";
        while(num>0){
            if(num%2==0){
                bin+='0';
            }
            else{
                bin+='1';
            }
            num/=2;
        }
        reverse(bin.begin(),bin.end());
        return bin;
    }
public:
    string convertDateToBinary(string date) {
        int yyyy=stoi(date.substr(0,4));
        int mm=stoi(date.substr(5,2));
        int dd=stoi(date.substr(8,2));
        return toBinary(yyyy)+"-"+toBinary(mm)+"-"+toBinary(dd);
    }
};

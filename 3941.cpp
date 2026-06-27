// You are given a string password.
// The strength of the password is calculated based on the following rules:
// 1 point for each distinct lowercase letter ('a' to 'z').
// 2 points for each distinct uppercase letter ('A' to 'Z').
// 3 points for each distinct digit ('0' to '9').
// 5 points for each distinct special character from the set "!@#$".
// Each character contributes at most once, even if it appears multiple times.
// Return an integer denoting the strength of the password.

class Solution {
public:
    int passwordStrength(string password) {
        int count=0;
        unordered_set<char> seen;
        for(char c:password){
            if(seen.count(c)){
                continue;
            }
            seen.insert(c);
            if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' ||
               c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z'){
                count+=1;
            }
            else if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' || c=='F' || c=='G' || c=='H' || c=='I' || c=='J' || c=='K' || c=='L' || c=='M' || c=='N' || c=='O' || c=='P' ||
                    c=='Q' || c=='R' || c=='S' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='Z'){
                count+=2;
            }
            else if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
                count+=3;
            }
            else if(c=='!'||c=='@'||c=='#'||c=='$'){
                count+=5;
            }
            else{
                return 0;
            }
        }
        return count;
    }
};

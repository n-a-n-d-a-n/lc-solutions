// Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.
// Answers within 10-5 of the actual value will be accepted as correct.

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12){
            hour=0;
        }
        double angle=abs(30*hour-5.5*minutes);
        if(angle>180){
            angle=360-angle;
        }
        return angle;
    }
};

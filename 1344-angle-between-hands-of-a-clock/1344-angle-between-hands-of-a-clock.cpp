class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double h = (double)hour;
        double m = (double)minutes;

        h = h*60 + m;
        if(h>=720){
            h  = h - 720;
        }

        m = m*12;
        if(m>=720)m = m-720;
        double re = abs(h-m);

        re = re*0.5;
        re = min(re , 360-re);
     return re;
    }
};
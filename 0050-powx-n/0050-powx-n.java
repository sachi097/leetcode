class Solution {
    public double myPow(double x, int n) {
        if(n<0) {
            return 1/apowb(x,n-2*n);
        }
        return apowb(x,n);
        
    }

    public double apowb(double x,int y) {
        if(y==0)
        return 1d;
        double power = (apowb(x,y/2));
        if(y%2==0) {
            return ((power)*(power));
        }
        return (x*(power*power));
    }
}
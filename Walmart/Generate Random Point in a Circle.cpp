class Solution {
public:
    double radius,centerX,centerY;
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        centerX=x_center;
        centerY=y_center;
    }
    
    vector<double> randPoint() {
        double length,theta;
        double random=(double)rand()/RAND_MAX;
     
        theta=(random)*(2)*(3.141592653589793238);
        double random2=(double)rand()/RAND_MAX;
        length=sqrt(random2)*radius;
        
        double x=centerX+length*cos(theta);
        double y=centerY+length*sin(theta);
        
        return vector<double>({x,y});
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
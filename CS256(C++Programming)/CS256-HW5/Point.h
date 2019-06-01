template<typename T>
class Point
{
private:
	T x, y;
public:
	Point();
	Point(double d1, double d2);
	double& getX();
	double& getY();
	void setX(double num);
	void setY(double num);
};
#include <iostream>
class XY {
    public:
    XY(int x, int y);
    friend bool operator<(const XY& xy_lcmp, const XY& xy_rcmp);
    friend std::ostream& operator<<(std::ostream& os, const XY& xy); 
    friend float operator%(const XY& xy_lcmp, int divisor);
    private:
    int x;
    int y;
};

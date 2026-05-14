
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    // 如果不交换x,y，可不可以这样写
    // int d = exgcd(b, a % b, y, x);
    // y -= a/b*x;
    int d = exgcd(b, a % b, x, y);
    int lastx = x, lasty = y;
    x = lasty; y = (lastx - a/b * lasty);
    return d;
}
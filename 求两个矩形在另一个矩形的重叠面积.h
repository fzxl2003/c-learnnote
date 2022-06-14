#include <stdio.h>
typedef struct dsjakl{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
}node;
long long max(long long a,long long b)
{
    return a>b?a:b;
}
long long min(long long a,long long b)
{
    return a<b?a:b;
}
long long chongdiemianji(node a,node b)     //计算矩形a b的重叠面积
{

    long long left = max(a.x1,b.x1);
    long long right = min(a.x2,b.x2);
    long long up = min(a.y2,b.y2);
    long long down = max(a.y1,b.y1);
    long long s=0;
    if(left < right && up > down)  s = (right-left)*(up-down);
    return s;
}
node chongdiejuxing(node a,node b) //输出矩形a b的重叠矩形，未重叠输出0
{
    node c;node cc={0,0,0,0};
    c.x1 = max(a.x1,b.x1);
    c.x2 = min(a.x2,b.x2);
    c.y1 = max(a.y1,b.y1);
    c.y2 = min(a.y2,b.y2);
    if(c.x1 < c.x2 && c.y1 < c.y2) return c;
    return cc;
}
node zuobiangenggai(node a)   //将矩形坐标输出为左下右上
{
    node b;
    b.x1=min(a.x1,a.x2);
    b.x2= max(a.x2,a.x1);
    b.y1= min(a.y1,a.y2);
    b.y2=max(a.y1,a.y2);
    return b;
}
long long mianji(node a)
{

    a=zuobiangenggai(a);
    return ((a.x2-a.x1)*(a.y2-a.y1));
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        node jx[3];
        int x1,y1,x2,y2;
        for (int i = 0; i < 3; ++i) {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            jx[i].x1=min(x1,x2);
            jx[i].x2= max(x1,x2);
            jx[i].y1= min(y1,y2);
            jx[i].y2= max(y1,y2);
        }
        long long sa= mianji(jx[0]);
        sa-= chongdiemianji(jx[0],jx[1]);
        sa-= chongdiemianji(jx[0],jx[2]);
        if (chongdiemianji(jx[1],jx[2])!=0)
        {
            node ccc= chongdiejuxing(jx[1],jx[2]);
            sa+= chongdiemianji(ccc,jx[0]);
        }
        printf("%lld\n",sa);
    }
}

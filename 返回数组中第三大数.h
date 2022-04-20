
int aaa(int a[],int l,int r) {    //返回a数组中l-r之间的第三大数
    int i;
    int max1 = 1 << 31, max2 = 1 << 31, max3 = 1 << 31;
    for (i = l; i <= r; ++i)
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        } else if (a[i] > max3) max3 = a[i];
    return max3;
}
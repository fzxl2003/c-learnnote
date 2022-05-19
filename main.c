#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char items[1030][35]; // ⽤于存储⽂件夹名
int total_items = 0;
int find_item(char *s) {
    // 找到⽂件夹名为s的⽂件夹，返回其在items数组中的索引
    for (int i = 0; i < total_items; i++) {
        if (strcmp(s, items[i]) == 0) {
            return i;
        }
    }
    return -1;
}
int set_item(char *s) {
    // 如果⽂件夹名为s的⽂件夹不在items数组中，存储它。返回s在items数组中的索引
    int idx = find_item(s);
    if (idx == -1) {
        strcpy(items[total_items], s);
        idx = total_items++;
    }
    return idx;
}
char *get_item(int idx) {
    return items[idx];
}
int tree[1030][1030], node_cnt[1030]; // tree为邻接表，node_cnt维护每个结点的孩⼦数
int cmp(const void *pa, const void *pb) {
    int a = *(int *)pa, b = *(int *)pb;
    return strcmp(get_item(a), get_item(b));
}
void print_tree(int idx, char *prefix) {
    // 打印以items[idx]为根结点的树，prefix维护需要在⽂件夹名之前打印的字符串
    int len = (int)strlen(prefix);
    for (int i = 0; i < node_cnt[idx]; i++) {
        printf(i == node_cnt[idx] - 1 ? "%s`-- %s\n" : "%s|-- %s\n", prefix,
               get_item(tree[idx][i])); //打印整⾏
        print_tree(tree[idx][i], strcat(prefix, i == node_cnt[idx] - 1 ? " " : "|")); // 递归调⽤
        prefix[len] = 0; // 还原prefix字符串

    }
}
int main(int argc, const char * argv[]) {

    char father[35], child[35];
    int have_father[1030] = {0}, t; // have_father数组维护结点是否有⽗亲
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", father, child);
        int fa_idx = set_item(father), ch_idx = set_item(child);
        have_father[ch_idx] = 1;
        tree[fa_idx][node_cnt[fa_idx]++] = ch_idx; // 在邻接表中添加元素
    }

    int root = 0;
    for (int i = 0; i < total_items; i++) {
        if (have_father[i] == 0) {
            root = i;
        }
        qsort(tree[i], node_cnt[i], sizeof(int), cmp); //将结点的孩⼦按⽂件夹名字典序升序排序
    }

    char prefix[5000] = {0}, dir[35]; // 令prefix为空字符串
    printf("%s\n", get_item(root));
    print_tree(root, prefix); // 打印整棵树
    while (~scanf("%s", dir)) {
        printf("%s\n", dir);
        print_tree(find_item(dir), prefix); // 打印⼦树
    }

    return 0;
}
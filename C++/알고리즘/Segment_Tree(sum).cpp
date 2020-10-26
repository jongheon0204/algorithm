// 부분합 + 갱신을 반복하는 경우 사용
#include <cmath>
#define SIZE 100
#define ll long long

// 트리의 높이 - 1
int h = (int)ceil(log2(SIZE));
int arr[SIZE];
ll * tree = new ll[1<<(h+1)];

// 배열 값을 토대로 트리 초기화
ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2 + 1, start, mid) + init(node * 2 + 2, mid + 1, end);
}

// 배열 값 업데이트 시 트리에 반영
void update(int node, int start, int end, int idx, ll dif){
    if(idx < start || end < idx) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(node * 2 + 1, start, mid, idx, dif);
    update(node * 2 + 2, mid + 1, end, idx, dif);
}

// left ~ right 범위 원소의 총 합을 구한다
ll sum(int node, int start, int end, int left, int right){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2 + 1, start, mid, left, right) + sum(node * 2 + 2, mid + 1, end, left, right);
}
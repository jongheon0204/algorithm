// 부분 배열 원소들 중 최고값 구하기 + 갱신을 반복하는 경우 사용
#include <cmath>
#define SIZE 100
#define ll long long
#define MIN_VAL -1000000000
#define max(a, b) ((a) < (b) ? (b) : (a))

// 트리의 높이 - 1
int h = (int)ceil(log2(SIZE));
ll arr[SIZE];
ll * minTree = new ll[1<<(h+1)];
ll * maxTree = new ll[1<<(h+1)];

ll initMax(int node, int start, int end){
    if(start == end) return maxTree[node] = arr[start];
    int mid = (start + end) / 2;
    return maxTree[node] = max(initMax(node * 2 + 1, start, mid), initMax(node * 2 + 2, mid + 1, end));
}

void updateMax(int node, int start, int end, int idx, ll val){
    if(idx < start || end < idx) return;
    maxTree[node] = max(maxTree[node], val);
    if(start == end) return;
    int mid = (start + end) / 2;
    updateMax(node * 2 + 1, start, mid, idx, val);
    updateMax(node * 2 + 2, mid + 1, end, idx, val);
}

ll getMax(int node, int start, int end, int left, int right){
    if(right < start || end < left) return MIN_VAL;
    if(left <= start && end <= right) return maxTree[node];
    int mid = (start + end) / 2;
    return max(getMax(node * 2 + 1, start, mid, left, right), getMax(node * 2 + 2, mid + 1, end, left, right));
}
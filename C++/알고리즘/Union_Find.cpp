#define SIZE 100

int parent[SIZE];
int level[SIZE];

void swap(int & u, int & v){
    int t = u;
    u = v;
    v = t;
}

bool isRange(int u){
    return (0 <= u && u < SIZE);
}

// 해당 정점이 속한 그래프의 정점을 반환
int find(int u){
    if(!isRange) return -1;
    while(u != parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

// 정점 u, v를 하나의 그래프로 합칠 수 있는지 판단
bool merge(int u, int v){
    u = find(u);
    v = find(v);

    if(v == u) return false;

    if(level[u] > level[v]){
        swap(u, v);
    }

    parent[u] = v;
    if(level[u] == level[v]){
        level[v]++;
    }
    return true;
}
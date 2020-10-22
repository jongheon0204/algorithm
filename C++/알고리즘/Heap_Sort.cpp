// 힙 정렬 : O(nlogn)
template <typename T>
T heap_pop(T * items, int len){
    T ret = items[0];
    items[0] = items[len];
    for(int i=0; i<len - 1;){
        int nextIdx = i * 2 + 1;
        if(nextIdx >= len) break;
        if(nextIdx + 1 < len && items[nextIdx + 1] < items[nextIdx]){
            nextIdx++;
        }
        if(items[nextIdx] > items[i]) break;
        T tmp = items[i];
        items[i] = items[nextIdx];
        items[nextIdx] = tmp;
        i = nextIdx;
    }
    return ret;
}

template <typename T>
void heap_push(T * items, T item, int idx){
    items[idx] = item;
    while(idx){
        if(items[idx] < items[(idx - 1) / 2]){
            T tmp = items[idx];
            items[idx] = items[(idx - 1) / 2];
            items[(idx - 1) / 2] = tmp;
            idx = (idx - 1) / 2;
        }else{
            break;
        }
    }
}

template <typename T>
void heap_sort(T * items, int len){
    T * heap = new T[len];
    for(int i=0; i<len; i++){
        heap_push(heap, items[i], i);
    }
    for(int i=0; i<len; i++){
        items[i] = heap_pop(heap, len-i-1);
    }
}
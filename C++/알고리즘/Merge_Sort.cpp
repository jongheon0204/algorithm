// 병합 정렬 : O(nlogn)
template <typename T>
void merge(T * items, int left, int right){
    int mid = (left + right) / 2;
    int l = left;
    int m = mid + 1;
    int idx = 0;
    int size = (right - left + 1);
    T * arr = new T[size];
    while(l <= mid && m <= right){
        if(items[l] < items[m]){
            arr[idx++] = items[l++];
        }else {
            arr[idx++] = items[m++];
        }
    }
    while(l <= mid){
        arr[idx++] = items[l++];
    }
    while(m <= right){
        arr[idx++] = items[m++];
    }
    for(int i=0; i<size; i++){
        items[i+left] = arr[i];
    }
    Print(arr, size);
    delete arr;
}

template <typename T>
void merge_sort(T * items, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(items, left, mid);
        merge_sort(items, mid + 1, right);
        merge(items, left, right);
    }
}
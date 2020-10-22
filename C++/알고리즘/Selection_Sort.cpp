// 선택 정렬 : O(n^2)
template <typename T>
void selection_sort(T * items, int len){
    for(int i=0; i<len; i++){
        int minIdx = i;
        for(int j=i+1; j<len; j++){
            if(items[minIdx] > items[j]){
                minIdx = j;
            }
        }
        T tmp = items[i];
        items[i] = items[minIdx];
        items[minIdx] = tmp;
    }
}
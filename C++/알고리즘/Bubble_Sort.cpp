// 버블 정렬 : O(n^2)
template <typename T>
void bubble_sort(T * items, int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(items[j] > items[j+1]){
                T tmp = items[j];
                items[j] = items[j+1];
                items[j+1] = tmp;
            }
        }
    }
}
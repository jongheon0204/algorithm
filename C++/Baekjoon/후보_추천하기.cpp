// https://www.acmicpc.net/problem/1713
// 1713.후보 추천하기 - 2020.10.04

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define STUDENT_MAX_NUM 100
#define ti3 tuple<int, int, int>

using namespace std;

// tuple에 저장될 3개의 값 : {추천 수, 등록 순서, 학생 번호}
enum Tuple{
    recommendNum,
    registeredAt,
    studentNum
};

int main() {
    // n : 사진틀 개수, m : 총 추천 횟수
    int n, m; cin>>n>>m;
    // 학생 번호는 1 ~ 100, 배열을 통해 사진틀에 게시되는지 검사
    vector<bool> isPhoto(STUDENT_MAX_NUM + 1);
    // 사진틀에 게시된 학생의 정보 저장
    vector<ti3> photoFrame;

    for(int i=0; i<m; i++){
        // 현재 추천받은 학생의 번호
        int s; cin>>s;
        // 추천받은 학생이 사진틀에 게시되어 있는 경우
        if(isPhoto[s]){
            // 사진틀을 찾아 정보 업데이트 (n이 20 이하의 자연수 라서 가능)
            for(int j=0; j<photoFrame.size(); j++){
                if(get<studentNum>(photoFrame[j]) == s){
                    get<recommendNum>(photoFrame[j])++;
                    break;
                }
            }
        }else{
            // 사진틀에 사진이 n개 있는 경우 하나 제거해줘야 한다
            if(photoFrame.size() == n) {
                // O(nlogn) -> 0 < n <= 20
                sort(photoFrame.rbegin(), photoFrame.rend());
                isPhoto[get<studentNum>(photoFrame.back())] = false;
                photoFrame.pop_back();
            }
            photoFrame.push_back({1, i, s});
            isPhoto[s] = true;
        }
    }
    for(int i=0; i<=STUDENT_MAX_NUM; i++){
        if(isPhoto[i]) cout<<i<<' ';
    }
}
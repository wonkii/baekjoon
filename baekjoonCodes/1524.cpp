/*각 전투에서 살아있는 병사중 제일 약한 병사가 죽는다. 만약 제일 약한 병사가 여러 명이고, 제일 약한 병사가 모두 같은 편에 있다면,
그 중에 한 명이 임의로 선택되어 죽는다. 하지만, 제일 약한 병사가 여러 명이고, 양 편에 모두 있다면, 세비의 제일 약한 병사 중 한 명이 임의로 선택되어 죽는다.
전쟁은 한 명의 병사를 제외하고 모두 죽었을 때 끝난다.
제일 약한 병사가 죽는다. -> 힘이 약하면 죽음 5 (1 1 1) 이러면 세준이가 이기는 거임 한명이어도 그러면 굳이 여러개 있을 필요없이 set함수로 줄여도 되지않나?
또, 가장 큰 값만 비교하면 되는거 아닌가? 가장 큰값을 비교해서 한쪽이 크면 출력하고, 같으면 세비꺼가 죽는거니까 세준이가 이기는걸로 하면 되는거 아님?
그러면 비길 때는 왜 나오는거임? 비길수가 없는데?  
*/
#include <iostream>
#include <set>

int main(){
    int Testcase, N, M;
    int Np, Mp, biggest1 = 0, biggest2 = 0;
    std::cin >> Testcase;

    for(int i = 0; i < Testcase; i++){
        std::cin >> N >> M; //병사들의 숫자 입력
        for(int j=0; j<N; j++){
            std::cin >> Np; // 세준 병사들의 힘 입력
            if(biggest1 < Np) biggest1 = Np; // 병사 중 가장 쎈 힘
        }
        for(int j=0; j<M; j++){
            std::cin >> Mp; // 세비 병사들의 힘 입력 
            if(biggest2 < Mp) biggest2 = Mp; 
        }
        return (biggest1 > biggest2) ? 'S' : 'B';
    }
    return 'C';

}
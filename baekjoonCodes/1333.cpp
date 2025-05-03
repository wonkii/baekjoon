//노래 N / 노래길이 L / 간격 5초 / 전화벨 D / 전화벨소리 1초 / 
// while문 (노래간격 일 때, 혹은 노래가 끝났고 다음 전화벨이 울릴 때
#include <iostream>
#include <vector>

int main() {
	int N, L, D;
	int Index = 0;
	std::cin >> N >> L >> D;
	int Plus = D;
	int last = 0;
	// std::cout << N << ' ' << L << ' ' << D; 공백을 사이에 두고 입력된 3개의 정수
	bool isMusic = true;
	std::vector<bool> Time((N * L) + 5 * (N - 1)); //시간이 흘러감을 표현해 줄 벡터 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			Time[j + Index] = isMusic;
		}
		Index += L + 5;
	}//음악이 작동하고 있는 시간대에만 true값을 넣어둠
	while (true) {
		if (D > (N * L) + 5 * (N - 1)) {
			std::cout << D;
			break;
		}
		else if (Time[D] != true) {
			std::cout << D;
			break;
		}
		D += Plus;
	}
}
/*
#include <iostream>

int main() {
	int N, L, D;
	std::cin >> N >> L >> D;

	// 총 재생 시간: 각 노래는 L초 + 5초의 정적 구간
	int totalDuration = (L + 5) * (N - 1) + L;  // 마지막 곡은 정적 없음

	for (int time = D; ; time += D) {
		// 이 time이 음악이 나오는 시간인지 확인
		// 곡 번호 = time / (L + 5)
		int songIndex = time / (L + 5);
		int offset = time % (L + 5);

		if (time > totalDuration || offset >= L) {
			std::cout << time << '\n';
			break;
		}
	}

	return 0;
}
*/
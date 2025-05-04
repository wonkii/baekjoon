// 1356
#include <iostream>
#include <string>

int main() {
	std::string Number; std::string pre; std::string post;
	std::cin >> Number;
	int Index = (Number.size() - 1);

	for (int i = 0; i < (Number.size() - 1); i++) { //반복은 숫자의 요소개수 -1번
		float PreNum = 1, PosNum = 1;
		post = Number.substr(Index); // 문자열 끝에서 부터 저장 
		pre = Number.substr(0, Index); // 문자열 처음부터 Index까지 저장
		
		for (char c : post) PosNum *= (c-'0');
		for (char c : pre) PreNum *= (c-'0');
		// 앞 뒤 문자열요소 곱 구하기++

		if (PosNum == PreNum) {
			std::cout << "YES";
			return 0;
		} // 만약 앞 뒤 곱이 같은 경우가 있다면, Yes출력 후 프로그램 종료
		Index--;
	}
	std::cout << "NO";
	return 0; // 같은 경우 없이 반복문 종료 시 No출력 후 프로그램 종료
}
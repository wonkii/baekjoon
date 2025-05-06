#include <iostream>
#include <string>
/*
* 1296번
연두의 이름과 팀 갯수를 받고
팀 갯수만큼의 배열을 만들고 그 안에 이름을 적어, 출력한다.
*/
int Count(std::string Name, std::string TeamName, char C) {
	int count = 0; int index = 0;
	std::string Rstr = Name + TeamName;
	while (true) {
		index = Rstr.find(C, index);
		if (index == std::string::npos) // <- -1 대신 npos 사용
			break;
		count++;
		index++; // 다음 문자로 이동
	}
	return count;
}

int main() {
	std::string name;
	int teamCounts;
	int counts = 0;
	getline(std::cin, name); //연두의 이름 받기
	std::cin >> teamCounts; //팀 갯수 받기

	std::string* teamNames = new std::string[teamCounts];
	for (int i = 0; i < teamCounts; i++) {
		std::cin >> teamNames[i];
	} // 팀 갯수만큼의 이름 받기

	int* L = new int[teamCounts];
	int* O = new int[teamCounts];
	int* V = new int[teamCounts];
	int* E = new int[teamCounts];
	int* result = new int[teamCounts];

	for (int j = 0; j < teamCounts; j++) {
		L[j] = Count(name, teamNames[j], 'L');
		O[j] = Count(name, teamNames[j], 'O');
		V[j] = Count(name, teamNames[j], 'V');
		E[j] = Count(name, teamNames[j], 'E');
		result[j] = ((L[j] + O[j]) * (L[j] + V[j]) * (L[j] + E[j]) * (O[j] + V[j]) * (O[j] + E[j]) * (V[j] + E[j])) % 100;
		// 각 teamNames마다 연두의 이름과 팀의 이름에 포함되어있는 단어의 갯수를 저장한다.
		// 요소에 저장된 값을 나타내기 위해 요소값을 저장해줘야함
	}
	int bigIndex = 0;
	int biggest = result[0]; // biggest변수 첫 팀의 함수식 결과로 초기화 biggest와 같은 결과를 가지는 팀이 있다면? 그 팀을 찾아서 팀 이름을 비교해야함.
	for (int i = 1; i < teamCounts; i++) {
		if (biggest == result[i] && teamNames[bigIndex] > teamNames[i]) {
			biggest = result[i];
			bigIndex = i;
		} // result 결과가 같고 만약 사전 순서가 지금것이 더 느리다면, 바꿔준다.
		else if (biggest < result[i]) {
			biggest = result[i];
			bigIndex = i;
		}
	}
	// result에는 입력된 팀의 순서대로 함수식의 결과가 들어있음. 이를 비교해서 가장 큰 팀 이름을 출력해야함.
	std::cout << teamNames[bigIndex];
	delete[] teamNames;

	return 0;
}

/*
* 최적화 버전
#include <iostream>
#include <string>
#include <vector>

std::pair<int, std::string> computeScore(const std::string& yeondu, const std::string& teamName) {
	int L = 0, O = 0, V = 0, E = 0;
	std::string combined = yeondu + teamName;

	for (char c : combined) {
		switch (c) {
			case 'L': L++; break;
			case 'O': O++; break;
			case 'V': V++; break;
			case 'E': E++; break;
		}
	}

	int score = ((L + O) * (L + V) * (L + E) *
				 (O + V) * (O + E) * (V + E)) % 100;
	return {score, teamName};
}

int main() {
	std::string yeondu;
	int teamCount;
	std::cin.ignore(); // 혹시 이전 줄에 cin이 있었다면
	std::getline(std::cin, yeondu);
	std::cin >> teamCount;

	std::vector<std::string> teams(teamCount);
	for (int i = 0; i < teamCount; ++i) {
		std::cin >> teams[i];
	}

	std::pair<int, std::string> best = computeScore(yeondu, teams[0]);

	for (int i = 1; i < teamCount; ++i) {
		auto current = computeScore(yeondu, teams[i]);
		if (current.first > best.first ||
			(current.first == best.first && current.second < best.second)) {
			best = current;
		}
	}

	std::cout << best.second << std::endl;
	return 0;
}
*/
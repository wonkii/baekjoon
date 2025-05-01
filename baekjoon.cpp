#include <iostream>
using namespace std;

int main(void) {
    int a, b;

    while (true) {
        cin >> a >> b;
        if (cin.eof() == true) {
            break;
        }
        cout << a + b << endl;
    }
}
// Ctrl+Z를 입력하면 프로그램이 종료된다.

#include <iostream>

int main() {
	int score;
	std::cin >> score;

	if (90 <= score && score <= 100) {
		std::cout << 'A';
	}
	else if (80 <= score && score < 90) {
		std::cout << 'B';
	}
	else if (700 <= score && score < 80) {
		std::cout << 'C';
	}
	else if (60 <= score && score < 70) {
		std::cout << 'D';
	}
	else {
		std::cout << 'F';
	}
	return 0;
}
// C++에서 논리연산자가 중요한 이유이다. 90<= X <=100으로 쓰면 우측 방정식이 항상 성립해서 A만 출력되게 된다.

// baekjoon 1145번 
// 주어진 정수 5개 중 3개를 선택해서 최소공배수를 만들 때, 가장 작은 최소공배수를 구하시오
#include <iostream>

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;  // 곱셈 후 나눗셈을 수행하여 오버플로우 방지
}
int lcm(int a, int b,int c) {
	return (lcm(lcm(a, b), c));  // 곱셈 후 나눗셈을 수행하여 오버플로우 방지
}

int main() {
	int p[5];
	int array[10];
	for (int i = 0; i < 5; i++) {
		std::cin >> p[i];
	}
	array[0] = lcm(p[0], p[1], p[2]);
	array[1] = lcm(p[0], p[1], p[3]);
	array[2] = lcm(p[0], p[1], p[4]);
	array[3] = lcm(p[0], p[2], p[3]);
	array[4] = lcm(p[0], p[2], p[4]);
	array[5] = lcm(p[0], p[3], p[4]);
	array[6] = lcm(p[1], p[2], p[3]);
	array[7] = lcm(p[1], p[2], p[4]);
	array[8] = lcm(p[1], p[3], p[4]);
	array[9] = lcm(p[2], p[3], p[4]);

	int biggest = array[0];
	for (int j = 1; j < 10; j++) {
		if (biggest > array[j]) {
				biggest = array[j];
		}
	}
	std::cout << biggest;
	return 0;
}

#include <iostream>
#include <string>

int main() {
	std::string s;
	std::getline(std::cin, s, '\n');

	bool Ischaracter = false;
	int count = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			if (Ischaracter == false) {
				count++;
			}
			Ischaracter = true;
		}
		else {
			Ischaracter = false;
		}
	}

	std::cout << count;
	return 0;
}
/*
-The Curious Case of Benjamin Button
The Curious Case of Benjamin Button
The Curious Case of Benjamin Button-


*/
#include <iostream>

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int a, b, result = 1;
		std::cin >> a >> b;

		a %= 10;

		if (a == 0) {
			std::cout << 10 << '\n';
			continue;
		}
		else {
			for (int k = 0; k < b; k++) {
				result = (result * a) % 10;
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}

#include <iostream>
#include <string>

int main() {
	int N, F, D;
	std::cin >> N >> F; // 428392 17


	int S = N - (N % 100); // 428300
	int J = S / F; // 428300 / 17


	while (true) {

		if (S % F == 0) {
			std::cout << "00";
			break;
		}

		int result = F * J; // 17*25194

		if (result > S) {
			std::string s = std::to_string(result % 100);
			if (s.size() == 1) {
				std::cout << '0' << s;
				break;
			}
			else {
				std::cout << std::to_string(result % 100);
				break;
			}
		}
		J++;
	}
	return 0;
}
/*
맨뒤 두 문자 버리고 앞 문자만 가지고와서
23442

23400
75*x > 23400 클 때 -> 100으로 나눠 -> 출력해
428300
*/
#include <iostream>
#include <set>
#include <algorithm>

int main() {
	int array[10];
	int A, count = 1;
	for (int i = 0; i < 10; i++) {
		std::cin >> A;
		array[i] = A % 42;
	}
	std::set<int> s;

	for (int j = 0; j < std::size(array); j++) {
		s.insert(array[j]);
	}

	std::for_each(s.begin(), s.end(), [](int n) {
		std::cout << n << std::endl;        //output : -1, 1, 3, 200
		});
	return 0;
}

/*
3052
두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다.

수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.

출력
첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.
*/

#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<double> Subjects(N);


	for (int i = 0; i < N; i++) {
		std::cin >> Subjects[i];
		if (Subjects[i] < 0 || Subjects[i] > 100) {
			return 0;
		}

	} // 과목 점수를 입력받고, 과목 점수가 음수거나 100초과 일 때 종료

	int M = Subjects[0];
	for (int j = 0; j < N; j++) {
		if (M < Subjects[j]) {
			M = Subjects[j];
		}
	} // M값을 결정하기

	double avg = 0;
	std::vector<double> array(N);

	for (int i = 0; i < N; i++) {
		array[i] = Subjects[i] / M * 100;
		avg += array[i];
	} // 새로운 배열에 점수/M *100 값을 집어넣는다. 그리고 합을 구한다.

	std::cout << avg / N;

	return 0;
}

/*
3
40 80 60
*/

/*
#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> Subjects(N); // 동적 배열처럼 사용 가능

	return 0;
}
메모리 자동조정, 크기조정가능
*/

#include <iostream>
#include <string>
#include <set>

int main() {
	int N;
	std::cin >> N;
	std::string* s = new std::string[N];
	std::string Cs;
	std::set<int> index;

	for (int i = 0; i < N; i++) {
		std::cin >> s[i];
	} // 문자열을 N개 받는다
	Cs = s[0]; // 기준이 되는 string을 정해준다.

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < Cs.length(); j++) {
			if (Cs[j] != s[i][j]) {
				index.insert(j);
			}
		}
	}// Cs의 index마다 문자를 모든 s의 같은 index의 문자를 같은 지 다른 지 확인 후 다르면 '?'를 삽입한다. index를 저장하는 방식은 set을 사용하여 겹치지 않게 저장한다.

	for (int idx : index) {
		if (idx < Cs.length()) {  // 유효한 인덱스인지 확인
			Cs[idx] = '?';
		}
	}
	std::cout << Cs;

	return 0;
}

/*

	std::string s[50];
	s[0] = "Hi";
	std::cout << s[0][0];

	https://popawaw.tistory.com/46
	https://velog.io/@doorbals_512/C-find-%ED%95%A8%EC%88%98
	https://ldgeao99.tistory.com/220
	https://hwan-shell.tistory.com/130
	for (int idx : indexSet) {
		if (idx < a.length()) {  // 유효한 인덱스인지 확인
			a[idx] = '?';
		}
	}



	// 1037
#include <iostream>
#include <set>

int main() {
	int C; // 진짜 약수의 갯수
	std::cin >> C;
	std::set<int> S;

	for (int i = 0; i < C; i++) {
		int num;
		std::cin >> num;
		S.insert(num);
	} // 약수를 받아줌 만약 A의 갯수가 1개라면
	int min = *S.begin();
	int max = *S.rbegin();

	if (C == 1) {
		std::cout<< min*min;
		return 0;
	}

	else {
		std::cout << min * max;
	}

	return 0;
}

//https://hwan-shell.tistory.com/119
//https://hwan-shell.tistory.com/130
/* 이렇게 약수들을 받으면, 서로가 나눠지는 경우와 안나눠지는 경우가 있다.
서로가 나눠지는 경우에, 1과 N이 추가되어야 하므로 약수의 갯수는 C+2개이다. 그런데 13과 9와 같은 경우에 필연적으로 3을 가질 수 밖에 없으니 문제가 틀린게 되어버린다.
이런 유형을 제외하고 답이 되는 경우만 추가하여만 한다.
서로가 안나눠지는 경우에,
6
3 4 2 12 6 8

2, 3, 5, 7등 솟수로 나눠보고 안나눠 1이 나올때까지 반복한다. -> 이게 말이 안된다. 솟수를 다 지정해줄 수 없다.
즉 최대공약수 함수를 참고해보자 주어진 약수들의 최소공배수가 답아닌가? 그런데 작업이 너무 많아지므로, 최대공약수를 들어오는 대로 구하고 트리도형을 그린다.

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;  // 곱셈 후 나눗셈을 수행하여 오버플로우 방지
}
*/

/*
0보다 크거나 같고, 99보다 작거나 같은 정수가 주어질 때 다음과 같은 연산을 할 수 있다. 먼저 주어진 수가 10보다 작다면 앞에 0을 붙여 두 자리 수로 만들고, 각 자리의 숫자를 더한다.
그 다음, 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 합의 가장 오른쪽 자리 수를 이어 붙이면 새로운 수를 만들 수 있다. 다음 예를 보자.

26부터 시작한다. 2+6 = 8이다. 새로운 수는 68이다. 6+8 = 14이다. 새로운 수는 84이다. 8+4 = 12이다. 새로운 수는 42이다. 4+2 = 6이다. 새로운 수는 26이다.

string으로 변환해서 N받아주고 인덱스 접근 일의 자리 10의 자리 따로 나눠주고 각각의 char? string 저장할까 문자열 하나니까 굳이 char형이어도
근데 char형으로 하면 string에 삽입 간으?stoi/ASCII -'0'

while문을 사용해서 cycle값을 올려주다가 출력
위의 예는 4번만에 원래 수로 돌아올 수 있다. 따라서 26의 사이클의 길이는 4이다.

N이 주어졌을 때, N의 사이클의 길이를 구하는 프로그램을 작성하시오.

*/
#include <iostream>
#include <string>
#include <vector>

int main() {
	int N, N2, cycle = 0;
	std::cin >> N;
	std::vector<int> vec(2);
	N2 = N;

	while (true) {
		vec[0] = N2 % 10; // 일의 자리수
		vec[1] = (N2 - vec[0]) / 10; // 십의 자리수
		int sum = vec[0] + vec[1];
		int first = sum % 10;

		std::string result = std::to_string(vec[0]) + std::to_string(first);
		cycle++;

		if (stoi(result) == N) {
			std::cout << cycle;
			break;
		}
		N2 = stoi(result);
	}
	return 0;
}
/*
std::string s = std::to_string(N);
	std::cout << s;

	if (s.length() == 1) {
		char a = s[0];
		s.push_back(a);
		s[0] = '0';
		std::cout << s;
	} // 0~9일 때 십의 자리수에 '0'삽입


	char first, second;
	std::string s2, firstone;
	int cycle = 0;

	while (true) {
		first = s[0];
		second = s[1];
		int N2 = (first-'0') + (second-'0');
		s2.push_back(second);

		firstone = std::to_string(N2).back();
		s2.append(firstone);
		cycle++;
		s = s2;

		if (stoi(s2) == N) {
			std::cout << cycle;
			break;
		}
	}
	return 0;
	*/

	/*알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.
	string 형으로 문자열 받기

	2. 가장 겹치는 문자를 구하고 갯수 count -> 대문자 출력
	count겹치면 ? 출력
	입력
	첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

	출력
	첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.*/

#include <iostream>
#include <string>
#include <algorithm>

int main() {

	std::string Input;
	getline(std::cin, Input);

	std::transform(Input.begin(), Input.end(), Input.begin(), ::toupper); // Input 대문자로 변환

	if (Input.size() == 1) {
		std::cout << Input;
		return 0;
	} // 하나만 받았을 때

	int Alphabet[26] = { };

	for (int i = 0; i < Input.size(); i++) {
		Alphabet[int(Input[i]) - 65] += 1;
	} // 알파벳은 26개가 있으므로 배열 0을 A에 25를 Z에 대응해서 발견할 때마다 1씩 높여준다 
	//A B C D E F G H I J K  L  M   N  O  P  Q  R  S  T  U  V  W  X  Y  Z
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

	int Maxindex = 0;
	for (int i = 1; i < 26; i++) {
		if (Alphabet[Maxindex] < Alphabet[i])
			Maxindex = i;
	} // 갯수가 가장 큰 index를 저장한다.

	for (int i = 0; i < 26; i++) {
		if (Maxindex != i && Alphabet[Maxindex] == Alphabet[i]) {
			std::cout << '?';
			return 0;
		}
	} // Maxindex와는 다른 i인데, 같은 count값을 가진다면, 중복되는 것이니 ?를 출력하고 프로그램을 종료한다.

	std::cout << char(Maxindex + 65);


	return 0;
}
/*
* https://happy-runner.tistory.com/70
* https://code-getset.tistory.com/112
Mississipi

	https://mutpp.tistory.com/entry/C-%EB%8C%80%EB%AC%B8%EC%9E%90%EC%86%8C%EB%AC%B8%EC%9E%90-%EB%B3%80%ED%99%98 C++ 대문자 소문자 변환
	if (Input.size() == 2) {
		if (Input[0] == Input[1]) {
			std::cout << Input[0];
			return 0;
		}
		std::cout << '?';
		return 0;
	}

	for (int i = 0; i < Input.size(); i++) {
		count = 0;
		char c = '.';
		for (int j = i + 1; j < Input.size(); j++) {
			if (Input[i] == Input[j]) {
				count++;
				Input[j] = c++;
			}
		}
		vec[i] = count;
	}

	// 이중포문 하나를 기준으로 문자열 끝까지 하나씩 같은 지 검사하고 같으면 count를 1씩 올린다.
	int index = 0;
	int biggest = vec[0];

	std::set<int> s;
	for (int i = 0; i < Input.size(); i++) {
		s.insert(vec[i]);
	}
	if (s.size() != Input.size()) {
		std::cout << '?';
		return 0;
	}

	for (int i = 1; i < Input.size() - 1; i++) {
		if (vec[i] > biggest) {
			biggest = vec[i];
			index = i;
		}
	}
	std::cout << Input[index];

	// vec배열 중 가장 큰 count값을 찾아낸다

	return 0;
}
	*/
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

int main() {

	int start = 0, Index = 0;
	std::vector<std::string> Inputstr;
	std::string Input;

	std::getline(std::cin, Input, '0');

	for (int i = 0; i < Input.size(); i++) {
		if (typeid(Input[i]).name() != "int") {
			Inputstr.push_back(Input.substr(start, i - start));
			start = i;
		} // int형이 아니라면..start에서 시작해서 i - start갯수 만큼 따로 문자열 빼서 가져와 저장

		if (i == Input.size() - 1) {
			Inputstr.push_back(Input.substr(start, Input.size()));
		}
	}

	return 0;
}


/*
getline함수의 세 번재 파라메터를 '0'으로 지정해서 0이 입력되면 종료되게 하고 입력된 문자열을 Input에 저장합니다
각 숫자들은 Enter혹은 빈칸으로 구분되어 있기 때문에, bool타입 Isinteger?를 만들고 숫자가 아니면 그 인덱스 전까지를 substr해서 저장해줍니다.

따라서 벡터 string을 선언해주고 하나 씩 인덱스 칸 하나하나 받아줍니다. 이후 그거에 사이즈의 반만큼씩 돌려서 앞뒤가 같은 지 확인하고 같으면 yes 다르면 no를 출력합니다.

https://doomed-lab.tistory.com/62
1 2 1
0 1 2  3

1 2 3 1
4 5 6 7  8

3 1 2 3
9 10 11 12  13

1  2  4  2  1
14 15 16 17 18

0
*/	


// 최대공약수 gcd()만드는 법 = 두 개의 수를 받아서 1부터 작은 하나까지 나눠주는데, 둘 다 나뉘는 수중 가장 큰 수

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
	delete[]teamNames;

	return 0;
}

/*

이환이가 만든 공식은 사용하려면 먼저 다음 4가지 변수의 값을 계산해야 한다.

L = 연두의 이름과 팀 이름에서 등장하는 L의 개수
O = 연두의 이름과 팀 이름에서 등장하는 O의 개수
V = 연두의 이름과 팀 이름에서 등장하는 V의 개수
E = 연두의 이름과 팀 이름에서 등장하는 E의 개수

((L+O) × (L+V) × (L+E) × (O+V) × (O+E) × (V+E)) mod 100
LOVE
3
JACOB
FRANK
DANO

*/


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
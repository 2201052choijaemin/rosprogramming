1. 일반 함수와 람다식의 차이를 자세히 설명하시오. 일반 함수로 정의 하는 대신에 람다식을 사용할 때 장점은 무엇인가?

일반 함수: def로 이름을 정해 만들어 두고 필요할 때 호출함.

람다식: 이름 없이 간단한 함수를 한 줄로 표현하는 방식.

2. 함수에 인자로 람다식을 사용하는 예제를 인터넷에서 찾아서 실행해보고 소스코드를 자세히 설명하시오.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};    // 정수형 동적 배열(vector)을 생성하고 값을 저장

    for_each(vec.begin(), vec.end(), [](int num) {  // 벡터의 처음부터 끝까지 람다식을 실행
        cout << num * 2 << " ";                    // 각 원소에 2를 곱해서 출력
    });

    cout << endl;                         // 줄 바꿈

    return 0;                             // 프로그램 종료
}
실형 결과: 2 4 6 8 10

3. 함수포인터와std::function 객체의 차이를 자세히 설명하시오.

함수 포인터: 함수의 주소를 저장하는 포인터이다. 일반 함수를 가리키고 호출할 수 있으며, 구조가 간단하고 빠르다

std::function 객체: 함수 포인터뿐만 아니라 람다식, 함수 객체, 멤버 함수 등 다양한 호출 가능한 대상을 저장하고 호출할 수 있다.

4. 23페이지 예제처럼 인터넷에서 std::function 클래스를 함수에 매개변수에 사용한 예제를 찾아서실행해보고 소스코드를 자세히 설명하시오

#include <iostream>
#include <functional>
using namespace std;

void process(int num, function<void(int)> func) {  // std::function을 매개변수로 받음
    func(num);                                     // 전달받은 함수 실행
}

int main() {
    int num = 10;                                  // 정수 변수 생성

    process(num, [](int x) {                       // 람다식을 함수의 인자로 전달
        cout << x * 2 << endl;                     // 전달받은 값에 2를 곱해서 출력
    });

    process(num, [](int x) {                       // 다른 람다식을 다시 전달
        cout << x + 5 << endl;                     // 전달받은 값에 5를 더해서 출력
    });

    return 0;                                      // 프로그램 종료
}

실행 결과
20
15

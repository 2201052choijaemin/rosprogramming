1. 일반 함수와 람다식의 차이를 자세히 설명하시오. 일반 함수로 정의 하는 대신에 람다식을 사용할 때 장점은 무엇인가?

일반 함수: def로 이름을 정해 만들어 두고 필요할 때 호출함.

람다식: 이름 없이 간단한 함수를 한 줄로 표현하는 방식.

2. 함수에 인자로 람다식을 사용하는 예제를 인터넷에서 찾아서 실행해보고 소스코드를 자세히 설명하시오.
 #include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(),
        [](int num) {
            std::cout << num * 2 << " ";
        });

    return 0;
}


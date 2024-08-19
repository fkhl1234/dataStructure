#include <array>
#include <iostream>
#include <type_traits>

template<typename... Args> // template parameter pack : several parameters
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)> {
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...};
} 
/* 
    common_type : extract common type from inputed datas 
    std::common_type::type : common type among input datas
    forward : lvalue / rvalue 참조 참고 : 아직 잘 모르겠음
*/

int main() {
    auto data = build_array(1, 0u, 'a', 3.2f, false);

    for(auto i:data) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << typeid(data).name() << std::endl;
}

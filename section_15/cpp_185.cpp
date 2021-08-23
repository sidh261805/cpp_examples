#include<iostream>

#ifdef __has_include
#   if __has_include(<filesystem>)
#       include<filesystem>
        namespace fs = std::filesystem;
#   else
#       include<experimental/filesystem>
        namespace fs = std::experimental::filesystem;
#   endif
#endif

int main(){
    fs::path p{"/home/vector/xpad/cpp/section_15"};
    std::cout << __cpp_inline_variables << std::endl;   //part of c++20 standards
    std::cout << __cpp_capture_star_this << std::endl;  //part of c++20 standards
    return 0;
}
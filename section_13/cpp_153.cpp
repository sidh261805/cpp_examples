#include<iostream>
#include<vector>

// Not good for interstion/deletion anywhere except at end

int main(){
    std::vector<int> vec{1,2,3,4,5};
    for (int i=0; i<5 ; i++){
        vec.push_back(i*10);
        std::cout << vec.size() << " " << std::endl;
    }

    vec[0] = 200;

    for (int i=0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;
    auto it = vec.begin();
    while(it != vec.end()){
        std::cout << *it++ << " ";
    }

    vec.insert(vec.begin(),300);
    vec.erase(vec.end()-4);
    vec.pop_back();
}

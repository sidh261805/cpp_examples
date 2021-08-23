#include<iostream>
#include<forward_list>
//forward linked list
int main(){
    std::forward_list<int> f_ls;
    for(int i = 0;i < 10;++i){
        f_ls.push_front(i * 10);
    }
    auto itr = f_ls.begin();
    while(itr != f_ls.end()){
        std::cout << *itr++ << " ";  //print from back (front)
    }
    f_ls.insert_after(f_ls.begin(),10);
    f_ls.erase_after(f_ls.begin());
    return 0;
}
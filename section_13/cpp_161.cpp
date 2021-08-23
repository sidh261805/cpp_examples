#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>

void unset(){
    std::unordered_set<std::string> sset;
    sset.insert("Auto");
    sset.insert("kartoffel");
    sset.insert("sidd");
    sset.insert("Iron man");
    sset.insert("superman");
    sset.insert("avenger");
    sset.insert("heman");
    sset.insert("batman");
    sset.insert("hulk");

    for(auto x : sset){
        std::cout << "Bucket number "<< sset.bucket(x) << " : " << x << std::endl;
    }

    std::cout << "Bucket count: " << sset.bucket_count() << std::endl;
    std::cout << "Number of element : " << sset.size() << std::endl;
    std::cout << "Load factor : " << sset.load_factor() << std::endl;

    std::unordered_multiset<std::string> usset;  // allow multiple value same

    usset.insert("Auto");
    usset.insert("kartoffel");
    usset.insert("sidd");
    usset.insert("Iron man");
    usset.insert("superman");
    usset.insert("Auto");
    usset.insert("heman");
    usset.insert("sidd");
    usset.insert("Auto");

    for(const auto x : usset){
        std::cout << "Bucket number "<< usset.bucket(x) << " : " << x << std::endl;
    }
}

void UnMap(){
    std::unordered_map<std::string,std::string> umap;
    umap["Batman"] = "Brue wayne";
    umap["Superman"] = "lala";
    umap["ironman"] = "Tony stark";

    for(const auto x : umap){
        std::cout << "Bucket # "<< umap.bucket(x.first) << " -> " <<x.first << ":" << x.second << std ::endl;
    }
    std::cout << std::endl;
    std::unordered_multimap<std::string,std::string> ummap;
    ummap.insert(std::make_pair("Batman","lala0"));
    ummap.insert(std::make_pair("Superman","lala"));
    ummap.insert(std::make_pair("ironman","tony stark"));
    ummap.insert(std::make_pair("Batman","lala1"));
    for(const auto x : ummap){
        std::cout << "Bucket # "<< ummap.bucket(x.first) << " -> " <<x.first << ":" << x.second << std ::endl;
    }
}

int main(){
    // unset();
    UnMap();
    return 0;
}
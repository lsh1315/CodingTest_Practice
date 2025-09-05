#include <iostream>
#include <string>
#include <vector>
#include <sstream> // stringstream을 사용하기 위해 필요

int main() {
    std::string text = "apple banana orange";
    std::stringstream ss(text);
    std::string word;
    std::vector<std::string> words;

    // stringstream이 공백을 기준으로 단어를 자동으로 추출
    while (ss >> word) {
        words.push_back(word);
    }

    std::cout << "분리된 단어들:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << std::endl;
    }

    std::cout << "\n-----------------\n" << std::endl;

    // 쉼표(,)를 구분자로 사용
    std::string text_with_commas = "cat,dog,mouse";
    std::stringstream ss_comma(text_with_commas);
    std::string segment;
    std::vector<std::string> segments;

    // getline의 세 번째 인자로 구분자를 지정
    while(std::getline(ss_comma, segment, ',')) {
       segments.push_back(segment);
    }
    
    std::cout << "분리된 세그먼트:" << std::endl;
    for(const auto& s : segments) {
        std::cout << s << std::endl;
    }
    
    return 0;
}
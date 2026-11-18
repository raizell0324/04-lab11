// 1. 본인이름학번의 네임스페이스

// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 3727500일 경우 KimPro3727500

// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.

// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }

// -네임스페이스 지정자 예: std::cout << "Enter your id: ";



// 2. 클래스1.h: 지난 실습에서 사용한 클래스에 다음을 변경 

// -input: 매개변수를 std::istream&로, 기본값은 std::cin으로

// -입력연산자>>: input함수를 이용

// -print: 매개변수를 std::ostream&로, 기본값은 std::cout으로, 공백채움문자설정과 출력폭설정으로 변경하기

// -출력연산자<<: print함수를 이용



// 3. 클래스1Data.txt: 클래스1의 입력연산자에서 멤버데이터를 읽는 순서대로 
// 데이터를 여러개 넣어 텍스트파일을 만듭니다. -> 입력 파일 만들기 위해 

#include <iostream>
#include "book.h"
#include <vector>
#include <fstream>
namespace Leeseonghui2649027
{
    // 리턴은 없고, 매개변수는 std::ifstream&형과 std::ofstream&형 2개입니다. 
// 클래스1형 std::vector를 선언합니다. 
// 입력파일스트림객체에서 데이터를 파일 끝까지 읽어서 클래스1형 std::vector에 값을 넣습니다. (push_back 이용) 
// 이때, std::cout.rdbuf()함수를 이용해 표준스트림으로 값을 읽을때 
// "Enter ... "등을 출력되지 않게 합니다.  
    void readWritebookDataFile(std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<book> v;  
        std::streambuf* origBuf{ std::cout.rdbuf()};
        std::cout.rdbuf(nullptr);
        while (!fin.eof())
        {
            book b; fin >>b;
            v.push_back(b);

        }
        std::cout.rdbuf(origBuf);
       
        for (const auto& vi : v)
        {
            fout << vi; 
        }
        
    }

}


int main()
{
    using namespace Leeseonghui2649027;
    std::ifstream fin{"bookData.txt"} ;
    if (fin.fail())
    {
        std::cout<< "Input file opening failed.\n";
        std::exit(1); 
    }
    
    std::ofstream fout{"out.txt"};
    if (fout.fail())
    {
        std::cout<< "Output file opening failed.\n";
        std::exit(1); 
    }
    
    readWritebookDataFile(fin, fout);\
    fin.close(); 
    fout.close(); 
    
    return 0; 
}

// 4. main.cpp: 테스트

// 본인이름학번의 네임스페이스안에 readWrite클래스1DataFile 함수를 정의하세요.

// -readWrite클래스1DataFile 함수



// 출력파일스트림객체에 클래스형 std::vector를 출력합니다. 



// -main

// 입력파일스트림객체를 선언하고 3의 텍스트파일을 열고 파일이 잘 열렸는지 확인합니다. 

// 출력파일스트림객체를 선언하고 파일명을 표준스트림으로 입력받고, 파일이 잘 열리는지 확인합니다. 

// readWrite클래스1DataFile 함수에 인자로 입력파일스트림객체와 출력파일스트림객체를 넣고 호출합니다.

// 입출력파일스트림객체와 파일의 연결을 끊어줍니다 (파일을 닫아줍니다). 

/*
 * studyClass.cpp
 *
 *  Created on: 2016. 8. 24.
 *      Author: hanseul
 */

/*
 * classStudy.cpp
 *
 *  Created on: 2016. 8. 24.
 *      Author: hanseul
 *
 *      //파일의 처음에 필요한 주석
		Program함수/프로그램이름 :
		File파일 이름 :
		Function함수(프로그램)가 하는 일 :
		Description프로그램의 동작 방법에 대한 기술 :
		Author작자 이름 :
		Environment이 프로그램을 만들기 위해 쓰여진 컴파일러, 링커, 그리고 다른 도구들 :
		필요한 추가 사항notes :
		revisions수정기록 :
 */

#include <iostream>
using namespace std;
typedef unsigned short int USHORT;
typedef unsigned long int ULONG;
enum BOOL { FALSE, TRUE }; //false true값을 갖는 bool이라는 배열상수
enum CHOICE { DrawRect = 1, GetArea, GetPerim, ChangeDimensions, Quit};

//Rectangle class define
class Rectangle {
public:
	//생성자, 소멸자 선언
	Rectangle(USHORT width, USHORT height);
	~Rectangle();

	//getter, setter 구현
	USHORT GetHeight() const {
		return itsHeight;
	}
	USHORT GetWidth() const {
		return itsWidth;
	}
	//const :
	ULONG GetArea() const {
		return itsHeight*itsWidth;
	}
	ULONG GetPerim() const {
		return 2*itsHeight + 2*itsWidth;
	}
	//class method 선언
	void SetSize(USHORT newtWidth, USHORT newHeight);

	//기타 연산자 = function?
	void DrawShape() const;

private:
	USHORT itsWidth;
	USHORT itsHeight;
};

//class method define구현
void Rectangle::SetSize(USHORT newWidth, USHORT newHeight){
	itsWidth = newWidth;
	itsHeight = newHeight;
}

//생성자 구현
Rectangle::Rectangle(USHORT width, USHORT height){
	itsWidth = width;
	itsHeight = height;
}
//소멸자 구현
Rectangle::~Rectangle() {}

USHORT DoMenu();
void DoDrawRect(Rectangle);
void DoGetArea(Rectangle);
void DoGetPerim(Rectangle);

int main(){
	return 0;
}

USHORT DoMenu(){
	USHORT choice;
	cout << "\n\n *** Menu *** \n";
	cout << "(1) Draw Rectangle \n";
	cout << "(2) Area\n";
	cout << "(3) Perimeter\n";
	cout << "(4) Resize\n";
	cout << "(5) Quit\n";

	cin >> choice;
	return choice;
}

void DoDrawRect(Rectangle theRect){
	USHORT height = theRect.GetHeight();
	USHORT width = theRect.GetWidth();

	for(USHORT i = 0; i<height; i++){
		for(USHORT j = 0 ; j<width; j++) {
			cout <<"*";
		}
		cout <<"\n";
	}
}

void DoGetArea(Rectangle theRect){
	cout<<"Area:"<<theRect.GetArea() << endl;
}

void DoGetPerim(Rectangle theRect){
	cout << "Perimeter: "<<theRect.GetPerim() << endl;
}




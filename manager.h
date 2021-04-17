#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
 char name[20];
 int weight;
 int price;
 int star;
 int star_count;
} Product;

int selectMenu();

int createProduct(Product *p); // 제품을 생성, 추가하는 함수

void readProduct(Product p); // 하나의 제품 출력 함수

void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력

int selectDataNo(Product *p, int count); // 선택된 데이터 가져오기

int updateProduct(Product *p); // 제품 수정

void searchName(Product *p, int count); // 제품이름 검색

void searchPrice(Product *p, int count); // 제품 가격대(원하는 가격 입력 후, 그것보다 낮거나 같은 가격대의 제품 검색)

void searchStar(Product *p, int count); // 제품의 별점 검색(원하는 별점 이상의 제품 검색)

int deleteProduct(Product *p); // index에 위치한 제품 삭제

void saveData(Product *p, int count); // 제품을 File에 저장

int loadData(Product *p); // 파일에서 제품 불러오기

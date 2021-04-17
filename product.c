#include "product.h"

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 제품 조회\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 수정\n");
    printf("4. 제품 삭제\n");
    printf("5. 제품 저장\n");
    // printf("6. 제품 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createProduct(Product *p){
    printf("제품명은? ");
    getchar();
    scanf("%[^\n]s", p->name);
    printf("무게는? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("별점은? ");
    scanf("%d", &p->star);
    printf("별점 개수는? ");
    scanf("%d", &p->star_count);
    return 1;
} // 제품을 생성, 추가하는 함수

void readProduct(Product p){
    if(p.price != -1){
        printf("제품명[무게]        가격  별점[별점개수]\n");
        printf("%s[%d]  %d %d[%d]\n", p.name, p.weight, p.price, p.star, p.star_count);
    }
} // 하나의 제품 출력 함수

int listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력, 이번 과제는 필요 없다

int selectDataNo(Product *p, int count); // 선택된 데이터 가져오기, 이거도 필요 없다

int updateProduct(Product *p){
    printf("제품명은? ");
    getchar();
    scanf("%[^\n]s", p->name);
    printf("무게는? ");
    scanf("%d", &p->weight);
    printf("가격은? ");
    scanf("%d", &p->price);
    printf("별점은? ");
    scanf("%d", &p->star);
    printf("별점 개수는? ");
    scanf("%d", &p->star_count);
    printf("=> 업데이트 성공! ");
    return 1;
} // 제품 수정

void searchName(Product *p, int count); // 제품이름 검색, 이거도 필요 없다

void searchPrice(Product *p, int count); // 제품 가격대(원하는 가격 입력 후, 그것보다 낮거나 같은 가격대의 제품 검색) 필요 x

void searchStar(Product *p, int count); // 제품의 별점 검색(원하는 별점 이상의 제품 검색) 필요 x

int deleteProduct(Product *p, int count){
    p->price = -1;
    p->star = -1;
    p->star_count = -1;
    p->weight = -1;
    printf("=> 삭제됨! ");
    return 0;
} // index에 위치한 제품 삭제, count는 필요없다

void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    fprintf(fp, "%d %d %d %d %s\n", p->price, p->weight, p->star, p->star_count, p->name);

    fclose(fp);
    printf("=> 저장됨! ");
} // 제품을 File에 저장

int loadData(Product *p){
    FILE *fp;
    if(access("product.txt", 00) == -1){
        printf("=> 파일 없음");
        return 0;
    }
    fp = fopen("product.txt", "rt");

    fscanf(fp, "%d", &p->price);
    fscanf(fp, "%d", &p->weight);
    fscanf(fp, "%d", &p->star);
    fscanf(fp, "%d", &p->star_count);
    fscanf(fp, "%[^\n]s", p->name);

    fclose(fp);
    printf("=> 로딩 성공!");
    return 1;
} // 파일에서 제품 불러오기

int main() {
    Product p;
    int count=0, menu;

    count = loadData(&p);
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
          if(count != 0)
            readProduct(p);
        }
        else if (menu == 2){
          count = createProduct(&p);
        }
        else if (menu == 3){
          count = updateProduct(&p);
        }
        else if (menu == 4){
          count = deleteProduct(&p, 1);
        }
        else if (menu == 5){
          saveData(&p, 1);
        } // 파일 저장, 불러오기는 기본 옵션인줄 알고 미리 했습니다
        // else if (menu == 6){
        //   count = sear(&p);
        // } 
    }
    printf("종료됨!\n");
    return 0;
}

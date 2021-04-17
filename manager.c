#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 제품 조회\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 수정\n");
    printf("4. 제품 삭제\n");
    printf("5. 제품 저장\n");
    printf("6. 제품 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int createProduct(Product *p){
    printf("제품명은? ");
    getchar();
    scanf("%[^\n]s", p->name);
    getchar();
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
        printf("%s[%d]  %d %d[%d]\n", p.name, p.weight, p.price, p.star, p.star_count);
    }
} // 하나의 제품 출력 함수

void listProduct(Product *p, int count){
    printf("제품명[무게]        가격  별점[별점개수]\n");
    for(int i=0;i<count;i++){
        if(p[i].price == -1) continue;
        printf("%2d ", i+1);
        readProduct(p[i]);
    }
}// 전체 등록된 제품 리스트 출력, 이번 과제는 필요 없다

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p, count);
    printf("번호는? (취소:0)? ");
    scanf("%d", &no);
    return no;
}// 선택된 데이터 가져오기, 이거도 필요 없다

int updateProduct(Product *p){
    printf("제품명은? ");
    getchar();
    scanf("%[^\n]s", p->name);
    getchar();
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

void searchName(Product *p, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("제품명[무게]        가격  별점[별점개수]\n");
    for(int i=0;i<count;i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)){
        printf("%2d ", i+1);
        readProduct(p[i]);
        scnt++;
        }
    }
    if(scnt == 0) printf("=>검색된 데이터 없음!");
    printf("\n");
} // 제품이름 검색

void searchPrice(Product *p, int count){
    int scnt = 0;
    int price;

    printf("원하는 가격은? ");
    scanf("%d", &price);

    printf("제품명[무게]        가격  별점[별점개수]\n");
    for(int i=0;i<count;i++){
        if(p[i].price == -1) continue;
        else if(p[i].price <= price){
            printf("%2d ", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=>검색된 데이터 없음!");
    printf("\n");
} // 제품 가격대(원하는 가격 입력 후, 그것보다 낮거나 같은 가격대의 제품 검색)

void searchStar(Product *p, int count){
    int scnt = 0;
    int s;

    printf("원하는 별점은? ");
    scanf("%d", &s);

    printf("제품명[무게]        가격  별점[별점개수]\n");
    for(int i=0;i<count;i++){
        if(p[i].price == -1) continue;
        else if(p[i].star >= s){
            printf("%2d ", i+1);
            readProduct(p[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=>검색된 데이터 없음!\n");
    printf("\n");
} // 제품의 별점 검색(원하는 별점 이상의 제품 검색) 필요 x

int deleteProduct(Product *p){
    p->price = -1;
    p->star = -1;
    p->star_count = -1;
    p->weight = -1;
    printf("=> 삭제됨! \n");
    return 0;
} // index에 위치한 제품 삭제, count는 필요없다

void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i=0;i<count;i++){
        if(p[i].price == -1) continue;
        fprintf(fp, "%d %d %d %d %s\n", p[i].price, p[i].weight, p[i].star, p[i].star_count, p[i].name);
    }
    fclose(fp);
    printf("=> 저장됨! \n");
} // 제품을 File에 저장

int loadData(Product *p){
    FILE *fp;
    if(access("product.txt", 00) == -1){
        printf("=> 파일 없음");
        return 0;
    }
    fp = fopen("product.txt", "rt");
    int i=0;
    for(; i<100;i++){
        fscanf(fp, "%d", &p[i].price);
        if(feof(fp)) break;
        fscanf(fp, "%d", &p[i].weight);
        fscanf(fp, "%d", &p[i].star);
        fscanf(fp, "%d", &p[i].star_count);
        fscanf(fp, "%[^\n]s", p[i].name);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
} // 파일에서 제품 불러오기

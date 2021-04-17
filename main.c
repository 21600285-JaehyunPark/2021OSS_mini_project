#include "manager.h"

int main() {
    Product p[100];
    int count=0, menu, index = 0;

    count = loadData(p);
    index = count;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
          if(count != 0)
            listProduct(p, index);
        }
        else if (menu == 2){
          count += createProduct(&p[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(p, index);
            if(no > 0){
                updateProduct(&p[no-1]);
            }
        }
        else if (menu == 4){
          int no = selectDataNo(p, index);
            if( no > 0){
                int deleteok ;
                printf("정말로 삭제하시겠습니까? (삭제:1)");
                scanf("%d", &deleteok);
                if(deleteok == 1){
                    deleteProduct(&p[no-1]);
                    count--;
                }
            }
        }
        else if (menu == 5){
          saveData(p, index);
        } 
        else if (menu == 6){
            int no;
            printf("무엇으로 검색하시겠습니까? (1:제품 이름, 2:가격, 3:별점)\n");
            scanf("%d", &no);
            if(no == 1){
                searchName(p, index);
            } else if(no == 2){
                searchPrice(p, index);
            } else if(no == 3){
                searchStar(p, index);
            } else{
                printf("잘못 입력함\n");
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}

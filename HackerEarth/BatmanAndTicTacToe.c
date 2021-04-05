#include <stdio.h>

int main(){
    int i, j, t, flag;
    char a[5][5] = {0};
    scanf("%d\n",&t);
    while(t>0){
        flag=0;
        for(i=0;i<4;i++){
            scanf("%s",a[i]);
        }
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                    if(j+2<4&&flag==0){
                        if((a[i][j]=='x'&&a[i][j+1]=='x'&&a[i][j+2]=='.')||
                        (a[i][j]=='x'&&a[i][j+1]=='.'&&a[i][j+2]=='x')||
                        (a[i][j]=='.'&&a[i][j+1]=='x'&&a[i][j+2]=='x')){
                            flag = 1;
                            printf("YES\n");
                            break;
                        }
                    }
                    if(j-2>=0&&flag==0){
                        if((a[i][j]=='x'&&a[i][j-1]=='x'&&a[i][j-2]=='.')||
                            (a[i][j]=='x'&&a[i][j-1]=='.'&&a[i][j-2]=='x')||
                            (a[i][j]=='.'&&a[i][j-1]=='x'&&a[i][j-2]=='x')){
                                flag = 1;
                                printf("YES\n");
                                break;
                        }
                    }
                    if(i+2<4&&flag==0){
                        if((a[i][j]=='x'&&a[i+1][j]=='x'&&a[i+2][j]=='.')||
                        (a[i][j]=='x'&&a[i+1][j]=='.'&&a[i+2][j]=='x')||
                        (a[i][j]=='.'&&a[i+1][j]=='x'&&a[i+2][j]=='x')){
                            flag = 1;
                            printf("YES\n");
                            break;
                        }
                    }
                    if(i+2<4&&j+2<4&&flag==0){
                            if((a[i][j]=='x'&&a[i+1][j+1]=='x'&&a[i+2][j+2]=='.')||
                        (a[i][j]=='x'&&a[i+1][j+1]=='.'&&a[i+2][j+2]=='x')||
                        (a[i][j]=='.'&&a[i+1][j+1]=='x'&&a[i+2][j+2]=='x')){
                            flag = 1;
                            printf("YES\n");
                            break;
                        }
                    }
                    if(i+2<4&&j-2>=0&&flag==0){
                        if((a[i][j]=='x'&&a[i+1][j-1]=='x'&&a[i+2][j-2]=='.')||
                        (a[i][j]=='x'&&a[i+1][j-1]=='.'&&a[i+2][j-2]=='x')||
                        (a[i][j]=='.'&&a[i+1][j-1]=='x'&&a[i+2][j-2]=='x')){
                            flag = 1;
                            printf("YES\n");
                            break;
                        }
                    }
            }
        }
        if(flag==0){
            printf("NO\n");
        }
        t--;
    }
    return 0;
}
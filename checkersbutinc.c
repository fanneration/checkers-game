#include<stdio.h>
#include<math.h>
#include<conio.h>
int xvalold,xvalnew,yold,ynew,piececountblack=12,piececountwhite=12;
char display[8][8]={
    {'o','#','o','#','o','#','o','#'},
    {'#','o','#','o','#','o','#','o'},
    {'o','#','o','#','o','#','o','#'},
    {'#','-','#','-','#','-','#','-'},
    {'-','#','-','#','-','#','-','#'},
    {'#','x','#','x','#','x','#','x'},
    {'x','#','x','#','x','#','x','#'},
    {'#','x','#','x','#','x','#','x'}
},xold,xnew;
int main(){
    printf("how to play: type the coordinates of the piece you want to move and the coordinates of where you want to move that piece to separated by a space. (ex.: a3 b4), to take you move the piece to the position of the piece you want to take. you cannot do multiple takes in a single turn.\ntype anything to start: ");
    getch();
    while (!(piececountblack==0||piececountwhite==0)){
    printf("\033[2J\033[1;1H");
    for (int i=7;i>=0;i--){
        printf("%i",i+1);
        for (int j=0;j<8;j++){
            printf(" %c",display[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\nwhite to play: ");
    scanf("%c %i %c %i",&xold,&yold,&xnew,&ynew);
    yold--;
    ynew--;
    xvalold=xold-97;
    xvalnew=xnew-97;
    if(display[yold][xvalold]=='o'){
        if (xvalold>7||xvalnew>7||yold>7||ynew>7||display[yold][xvalold]!='o'||(display[ynew][xvalnew]!='-'&&display[ynew][xvalnew]!='x')||(abs(ynew-yold)!=1||(abs(xvalnew-xvalold))!=1)){
            printf("illegal move, fuck you.\n");
            break;
        }else if (display[ynew][xvalnew]!='x'){
            if (ynew==yold+1){
            display[yold][xvalold]='-';
            display[ynew][xvalnew]='o';
            }else{
                printf("illegal move, fuck you.\n");
                break;
            }
        }else{
            if (ynew>yold&&xvalnew>xvalold){
                if (display[ynew+1][xvalnew+1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew+1][xvalnew+1]='o';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew>yold&&xvalnew<xvalold){
                if (display[ynew+1][xvalnew-1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew+1][xvalnew-1]='o';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew<yold&&xvalnew>xvalold){
                if (display[ynew-1][xvalnew+1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew-1][xvalnew+1]='o';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew<yold&&xvalnew<xvalold){
                if (display[ynew-1][xvalnew-1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew-1][xvalnew-1]='o';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }
        }
    }else if (display[yold][xvalold]=='O'){
        if (xvalold>7||xvalnew>7||yold>7||ynew>7||display[yold][xvalold]!='O'||(display[ynew][xvalnew]!='-'&&display[ynew][xvalnew]!='x')||xvalold==xvalnew||yold==ynew){
            printf("illegal move, fuck you.\n");
            break;
        }else if (display[ynew][xvalnew]!='x'){
            display[yold][xvalold]='-';
            display[ynew][xvalnew]='O';
        }else{
            if (ynew>yold&&xvalnew>xvalold){
                if (display[ynew+1][xvalnew+1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew+1][xvalnew+1]='O';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew>yold&&xvalnew<xvalold){
                if (display[ynew+1][xvalnew-1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew+1][xvalnew-1]='O';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew<yold&&xvalnew>xvalold){
                if (display[ynew-1][xvalnew+1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew-1][xvalnew+1]='O';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew<yold&&xvalnew<xvalold){
                if (display[ynew-1][xvalnew-1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew-1][xvalnew-1]='O';
                    piececountblack--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }
        }
    }else{
        printf("illegal move, fuck you.\n");
        break;
    }
    if (ynew==7){
        display[ynew][xvalnew]='O';
    }else if (ynew==6&&display[ynew][xvalnew]=='-'){
        if (xvalnew>xvalold){
            display[ynew+1][xvalnew+1]='O';
        }else{
            display[ynew+1][xvalnew-1]='O';
        }
    }
    printf("\033[2J\033[1;1H");
    for (int i=0;i<8;i++){
        printf("%i",i+1);
        for (int j=7;j>=0;j--){
            printf(" %c",display[i][j]);
        }
        printf("\n");
        }
    printf("  h g f e d c b a\nblack to play: ");
    scanf("%c %i %c %i",&xold,&yold,&xnew,&ynew);
    yold--;
    ynew--;
    xvalold=xold-97;
    xvalnew=xnew-97;
    if (display[yold][xvalold]=='x'){
        if (xvalold>7||xvalnew>7||yold>7||ynew>7||display[yold][xvalold]!='x'||(display[ynew][xvalnew]!='-'&&display[ynew][xvalnew]!='o')||(abs(ynew-yold)!=1||(abs(xvalnew-xvalold))!=1)){
             printf("illegal move, fuck you.\n");
            break;
        }else if (display[ynew][xvalnew]!='o'){
            if (ynew==yold-1){
                display[yold][xvalold]='-';
                display[ynew][xvalnew]='x';
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
        }else{
             if (ynew>yold&&xvalnew>xvalold){
                if (display[ynew+1][xvalnew+1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew+1][xvalnew+1]='x';
                    piececountwhite--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew>yold&&xvalnew<xvalold){
                if (display[ynew+1][xvalnew-1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew+1][xvalnew-1]='x';
                    piececountwhite--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew<yold&&xvalnew>xvalold){
                if (display[ynew-1][xvalnew+1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew-1][xvalnew+1]='x';
                    piececountwhite--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }else if (ynew<yold&&xvalnew<xvalold){
                if (display[ynew-1][xvalnew-1]=='-'){
                    display[ynew][xvalnew]='-';
                    display[yold][xvalold]='-';
                    display[ynew-1][xvalnew-1]='x';
                    piececountwhite--;
                }else{
                    printf("illegal move, fuck you.\n");
                    break;
                }
            }
        }
    }else if (display[yold][xvalold]=='X'){
        if (xvalold>7||xvalnew>7||yold>7||ynew>7||display[yold][xvalold]!='X'||(display[ynew][xvalnew]!='-'&&display[ynew][xvalnew]!='o')||yold==ynew||xvalold==xvalnew){
            printf("illegal move, fuck you.\n");
           break;
       }else if (display[ynew][xvalnew]!='o'){
               display[yold][xvalold]='-';
               display[ynew][xvalnew]='X';
       }else{
            if (ynew>yold&&xvalnew>xvalold){
               if (display[ynew+1][xvalnew+1]=='-'){
                   display[ynew][xvalnew]='-';
                   display[yold][xvalold]='-';
                   display[ynew+1][xvalnew+1]='X';
                   piececountwhite--;
               }else{
                   printf("illegal move, fuck you.\n");
                   break;
               }
           }else if (ynew>yold&&xvalnew<xvalold){
               if (display[ynew+1][xvalnew-1]=='-'){
                   display[ynew][xvalnew]='-';
                   display[yold][xvalold]='-';
                   display[ynew+1][xvalnew-1]='X';
                   piececountwhite--;
               }else{
                   printf("illegal move, fuck you.\n");
                   break;
               }
           }else if (ynew<yold&&xvalnew>xvalold){
               if (display[ynew-1][xvalnew+1]=='-'){
                   display[ynew][xvalnew]='-';
                   display[yold][xvalold]='-';
                   display[ynew-1][xvalnew+1]='X';
                   piececountwhite--;
               }else{
                   printf("illegal move, fuck you.\n");
                   break;
               }
           }else if (ynew<yold&&xvalnew<xvalold){
               if (display[ynew-1][xvalnew-1]=='-'){
                   display[ynew][xvalnew]='-';
                   display[yold][xvalold]='-';
                   display[ynew-1][xvalnew-1]='X';
                   piececountwhite--;
               }else{
                   printf("illegal move, fuck you.\n");
                   break;
               }
           }
       }
    }else{
        printf("illegal move, fuck you.\n");
        break;
    }
    if (ynew==0){
        display[ynew][xvalnew]='X';
    }else if (ynew==1&&display[ynew][xvalnew]=='-'){
        if (xvalnew>xvalold){
            display[ynew-1][xvalnew+1]='X';
        }else{
            display[ynew-1][xvalnew-1]='X';
        }
    }
}
if (piececountblack==0){
    printf("white wins!!!");
}else{
    printf("black wins!!!");
}
getch();
return 0;
}
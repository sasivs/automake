#include<stdio.h>
#include"stacks1.h"
int safeCol(int c1, int c2){
    if (c1==c2){
        return 0;
    }
    return 1;
}
int safeDiag(int r1, int r2, int c1, int c2){
    if(r1+c1==r2+c2 || r1-c1==r2-c2){
        return 0;
    }
    return 1;
}
int isFeasible(struct stacks1* s, int row1, int col1, int size){
    int row2=size, col2, i=0;
    int colList[size];
    while(!isEmpty(s)){
        pop(s,&col2);
        colList[i]=col2;
        if (!safeCol(col1,col2) || !safeDiag(row1,row2,col1,col2)){
            while((i+1)!=0){
                push(s,colList[i]);
                i--;
            }
            return 0;
        }
        row2--;
        i++;
    }
    i--;
    while((i+1)!=0){
        push(s,colList[i]);
        i--;
    }
    return 1;
}
int printSolution(struct stacks1* s, int size){
    int c;
    while(size!=0){
        pop(s,&c);
        printf("(%d,%d)\n",size,c);
        size--;
    }
    return 1;
}
int nQueens(int n){
    struct stacks1* s=NULL;
    init(&s);
    int r=1,c=1,size=0;
    while(c<=n && r<=n){
        if(isFeasible(s,r,c,size)){
            push(s,c);
            size++;
            r=r+1;
            c=1;
        }
        else{
            while(c>=n){
                if(!isEmpty(s)){
                    pop(s,&c);
                    r=size;
                    size--;
                }
                else{
                    break;
                }
            }
            c++;
        }
    }
    if(!isEmpty(s)){
        printf("Solution for this %dX%d configuration is: \n",n,n);
        printSolution(s,size);
    }
    else{
        printf("No solution for this %dX%d configuration\n",n,n);
    }
    destroy(&s);
    return 1;
}
int main(){
    int n;
    printf("Enter the size of chess board: ");
    scanf("%d",&n);
    nQueens(n);
    return 0;
}

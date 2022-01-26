#include<stdio.h>
#include<stdlib.h>
int Nhap(){
      int n;
      printf("***Nhap so dia can di chuyen: ");
      scanf("%d",&n);
      return n;
}
int giaithuat(int n,char x,char y,char z){
    if(n==1) return 1;
    else if(n>=2){
        return giaithuat(n-1,'1','2','3')+ giaithuat(1,'1','3','2')+giaithuat(n-1,'2','3','1');
    }
    
}
void menu(){
    printf("CHUONG TRINH TIM SO BUOC NHAY - THAP HA NOI\n");
    printf("********************OoO********************\n");
    printf("1.Nhap so dia \n");
    printf("2.Giai thuat\n");
    printf("3.Ket thuc chuong trinh\n");
    printf("Chon lua chon: ");
}
int main(){
    int n;
    int x=0;
	while (x!=3)
	{	
        menu();
        scanf("%d",&x);
		switch (x)
    {
    case 1:
        n=Nhap();
        break;
    case 2:
        printf("****tong so buoc can di chuyen %d dia la: %d \n",n,giaithuat(n,'1','3','2'));
        break;
    case 3:
        exit(1);  
    }
	}
    return 0;
}
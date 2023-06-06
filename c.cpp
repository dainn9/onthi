#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

typedef struct ThietBi{
    char TTB[20];
    int NSD;
    float G;
} TB;

void nhapdsTB(int *n, TB ds[]);
void xuatdsTB(int n, TB ds[]);
void ghiFILE(int n, TB ds[]);
void swap (TB &a, TB &b);
void sort(int n, TB ds[]);
void timkiemTB(int n, TB ds[]);
void maxG(int n, TB ds[]);
void thongke(int n, TB ds[]);


int main(){
    int n;
    TB ds[100];
    nhapdsTB(&n,ds);
    printf("\nDanh sach thiet bi truoc khi sap xep");
    xuatdsTB(n,ds);
    sort(n,ds); 
    printf("\nDanh sach thiet bi sau khi sap xep");
    xuatdsTB(n,ds);
    ghiFILE(n,ds);
    timkiemTB(n,ds);
    maxG(n,ds);
    thongke(n,ds);
    getch();
}
// het ham main
void nhapdsTB(int *n, TB ds[])
{
    printf("\nNhap n: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap thiet bi thu %d\n",i+1);
        printf("Nhap ten tb: ");
        fflush(stdin);
        gets(ds[i].TTB);
        printf("Nhap NSD: ");
        scanf("%d",&ds[i].NSD);
        printf("Nhap G: ");
        scanf("%f",&ds[i].G);
    }
}

void xuatdsTB(int n, TB ds[])
{
    printf("\n\t\t---DANH SACH THIET BI---\n");
    printf("%-20s %-15s %-10s","TEN THIET BI", "NAM SU DUNG", "Gia");

    for (int i = 0; i < n; i++)
        printf("\n%-20s %-15d %10.3f",ds[i].TTB, ds[i].NSD, ds[i].G);
}

void ghiFILE(int n, TB ds[])
{
    FILE *f = fopen("Danhsach.txt","w");
    if (f == NULL)
    {
        printf("\nLoi");
        exit(1);
    }
    fprintf(f,"%-20s %-15s %-10s\n","TEN THIET BI", "NAM SU DUNG", "GIA");
    for (int i = 0; i < n; i++)
    {
        fprintf(f,"%-20s %-15d %10.3f",ds[i].TTB, ds[i].NSD, ds[i].G);
        if (i<n-1)
            fprintf(f,"\n");
    }
    fclose(f);
}

void swap(TB &a, TB &b)
{
    TB temp = a;
    a = b;
    b = temp;
}

void sort(int n, TB ds[])
{
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (ds[i].NSD < ds[j].NSD)
                swap(ds[i],ds[j]);

}

void timkiemTB(int n, TB ds[])
{
    char name[20];
    printf("\nNhap ten thiet biet can tim: ");
    fflush(stdin);
    gets(name);

    int timthay = 0;
        printf("\nThiet bi can tim:\n");
        printf("%-20s %-15s %-10s","TEN THIET BI", "NAM SU DUNG", "GIA");
    for (int i = 0; i < n; i++)
        if (strcmp(ds[i].TTB, name) == 0)
        {
            printf("\n%-20s %-15d %10.3f",ds[i].TTB, ds[i].NSD, ds[i].G);
            timthay = 1;
        }
       if (!timthay)
        printf("\nKhong co thiet bi can tim");
}

void maxG(int n, TB ds[])
{
    float max = ds[0].G;
    int temp;
    for (int i = 0; i < n ; i++)
        if (ds[i].G > max)
        {
            max = ds[i].G;
            temp = i;
        }

    printf("\nThiet bi co gia cao nhat la\n");
    printf("%-20s %-15s %-10s","TEN THIET BI", "NAM SU DUNG", "GIA");
    printf("\n%-20s %-15d %10.3f",ds[temp].TTB, ds[temp].NSD, ds[temp].G);
}

void thongke(int n, TB ds[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
        if (ds[i].NSD > max)
            max = ds[i].NSD;

    int *thongke = (int*)calloc(max+1,sizeof(int));

    for (int i = 0; i < n; i++)
        thongke[ds[i].NSD]++;

    printf("\n-----BANG THONG KE THEO NAM SU DUNG-----\n");
    printf("%-15s %-5s","NAM SU DUNG", "SO LUONG");
    for (int i = 0; i <= max; i++)
        if (thongke[i] > 0)
            printf("\n%-15d %-5d",i, thongke[i]);
}
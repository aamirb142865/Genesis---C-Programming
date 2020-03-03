// NAME: AAMIR SUHAIL BURHAN
// ID: 142865
#include<stdio.h>
#include<stdlib.h>
typedef enum oem{IPhone,Samsung,HTC,Sony}oem;
typedef struct mobile{
    int model_Number;
    oem company;
    int disp_Size;
    int battery_Capacity;
    int ram;
    int rom;
    int price;
    char cam_Res;
    }mob;
const int size=50;
int new_Size=0, choice=0,umc,least_Val,highest_Val,sc;
oem m;
void unique_No(const mob*,int,int);
void max_Battery(mob*,int);
void max_Camres(mob*,int);
void avg_Price(const mob* ,int);
void numb_Models(const mob*,int,int,int,int);
void numb_Storage(const mob*,int,int);
int main()
{
    mob *mo=(mob*)(malloc(size*sizeof(mob)));
    printf("Enter Details");
    for(int i=0;((i<size)&&(choice==0));i++)
    {
        choice=0;
        printf("\nModel Number\tOEM\tDisplay Size\tBattery Capacity\tAvailable Memory\tInternal Storage\tCamera Resolution\tPrice\n");
        scanf("\n%d %d %d %d %d %d %c %d",&mo[i].model_Number,&mo[i].company,&mo[i].disp_Size,&mo[i].battery_Capacity,&mo[i].ram,&mo[i].rom,&mo[i].cam_Res,&mo[i].price);
        new_Size++;
        printf("\nEnter 1 if you want to stop entering records, else enter 0\t");
        scanf("%d",&choice);
    }

    printf("\nEnter the unique model number you want to find\t");
    scanf("%d",&umc);
    unique_No(mo,umc,new_Size);
    avg_Price(mo,new_Size);
    printf("\nModel with maximum battery capacity\n");
    max_Battery(mo,new_Size);
    printf("\nModel with maximum Camera Resolution\n");
    max_Camres(mo,new_Size);
    printf("Enter the min storage capacity\n");
    scanf("%d",&sc);
    numb_Storage(mo,size,sc);
    printf("Enter the oem name(0-IPHONE 1- SAMSUNG 2-HTC 3-SONY) and price range in the format least value and highest value\n");
    scanf("%s %d %d",m,&least_Val,&highest_Val);
    numb_Models(mo,m,least_Val,highest_Val,new_Size);
    return 0;
}
void unique_No(const mob* ptr,int MN,int size)
{
    char found=0;
    for(int i=0;((i<size)&&(found==0));i++)
    {
        if(ptr[i].model_Number==MN)
        {
            printf("\nRecord Found\n");
            printf("\nModel Number:%d\tOEM:%d\tDisplay Size:%d\tBattery Capacity:%d\tAvailable Memory:%d\tInternal Storage:%d\tCamera Resolution:%c\tPrice:%d\n",ptr[i].model_Number,ptr[i].company,ptr[i].disp_Size,ptr[i].battery_Capacity,ptr[i].ram,ptr[i].rom,ptr[i].cam_Res,ptr[i].price);
            found=1;
        }
    }
}
void avg_Price(const mob* ptr,int size)
{
    float average_Price=0;
    for(int i=0;i<size;i++)
    {
        average_Price+=ptr[i].price;
    }
    printf("Average Price of all models = RS. %f\n",(average_Price/size));
}
void max_Battery(mob* ptr,int size)
{
    int highest=0,i;
    for(i=1;i<size;i++)
    {
        if(ptr[i].battery_Capacity>ptr[highest].battery_Capacity)
            highest=i;
    }
    printf("\nModel Number:%d\tOEM:%d\tDisplay Size:%d\tBattery Capacity:%d\tAvailable Memory:%d\tInternal Storage:%d\tCamera Resolution:%c\tPrice:%d\n\n",ptr[highest].model_Number,ptr[highest].company,ptr[highest].disp_Size,ptr[highest].battery_Capacity,ptr[highest].ram,ptr[highest].rom,ptr[highest].cam_Res,ptr[highest].price);
}
void max_Camres(mob* ptr,int size)
{
    int highest=0,i;
    for(i=1;i<size;i++)
    {
        if(ptr[i].cam_Res>ptr[highest].cam_Res)
            highest=i;
    }

    printf("\nModel Number:%d\tOEM:%d\tDisplay Size:%d\tBattery Capacity:%d\tAvailable Memory:%d\tInternal Storage:%d\tCamera Resolution:%c\tPrice:%d\n\n",ptr[highest].model_Number,ptr[highest].company,ptr[highest].disp_Size,ptr[highest].battery_Capacity,ptr[highest].ram,ptr[highest].rom,ptr[highest].cam_Res,ptr[highest].price);
}
void numb_Models(const mob* ptr,int make,int lv ,int rv,int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if((ptr[i].company==make)&&((ptr[i].price>=lv)&&(ptr[i].price<=rv)))
           count++;
    }
    printf("Number of Models with the specified manufacturer and range are:%d",count);
}
void numb_Storage(const mob* ptr,int size,int st_Cap)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(ptr[i].rom>=st_Cap)
           count++;
    }
    printf("Number of Models with the minimum specified storage is:%d",count);
}

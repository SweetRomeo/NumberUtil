//
// Created by BERKE on 14.03.2023.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define Max(x,y) (x > y ? x : y)
#define Min(x,y) (x < y ? x : y)


int getOnesDigit(int val){ return  val % 10;}
int getTensDigit(int val){ return  val / 10 % 10;}
int getHundredsDigit(int val){ return  val / 100;}

bool isPrime(int);
int getPrimeFactorsSum(int);
int reverseNumber(int);
int getDigitsSum(int val);

bool areFriends(const int x,const int y)
{
    return x == getPrimeFactorsSum(y) && y == getPrimeFactorsSum(x) && x != y;
}

int Mid(const int val1,const int val2,const int val3)
{
    if(val1 > val2 && val2 > val3 || val3 > val2 && val2 > val1)
        return val2;
    if(val2 > val1 && val1 > val3 || val3 > val1 && val1 > val2)
        return val1;
    return val3;
}
void printDiamond(const int n)
{
    bool directionFlag = true;
    int x = 0;
    while(1){
        for(int i = x;i < n - 1;++i)
            printf(" ");
        for(int i = 0;i < 2 * x + 1;++i)
            printf("*");
        if(x == n - 1)
            directionFlag = false;
        if(directionFlag)
            ++x;
        else
            --x;
        printf("\n");
        if(x < 0)
            break;
    }

}
void BallShape(int height,const int width)
{
    bool directionFlag = true;
    int Ballindex = 0;
    while(height--){
        printf("|");
        for (int i = 0; i < Ballindex; ++i) {
            printf(" ");
        }
        printf("*");
        for (int i = Ballindex; i < width - 1 ; ++i) {
            printf(" ");
        }
        printf("|");
        if(directionFlag && Ballindex == width - 1)
            directionFlag = false;
        if(!directionFlag && Ballindex == 0)
            directionFlag = true;
        if(directionFlag)
            Ballindex++;
        else
            Ballindex--;
        printf("\n");
    }
}
void BallShapeTest()
{
    int height,width;
    printf("Enter Height?\n");
    scanf("%d",&height);
    printf("Enter Width?\n");
    scanf("%d",&width);
    BallShape(height,width);
}
int calculateDigitalRoot(int val)
{
    int sum;
    while(1){
        sum = getDigitsSum(val);
        val = sum;
        if(sum / 10 == 0)
            break;
    }
    return sum;
}
int calculateFactorial(const int n)
{
    int result = 1;
    for(int i = 2;i <= n;++i)
        result *= i;
    return result;
}
double calculate_e_number()
{
    double e = 0.;
    for(int i = 0;i <= 13;++i){
        e += 1./ calculateFactorial(i);
    }
    return e;
}
bool crapsGame()
{
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int dice_sum = dice1 + dice2;
    if(dice_sum == 2 || dice_sum == 3 || dice_sum == 12)
        return false;
    if(dice_sum == 7 || dice_sum == 11)
        return true;
    int temp_dice = dice_sum;
    while(1){
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        dice_sum = dice1 + dice2;
        if(dice_sum == 7)
            return false;
        if(dice_sum == temp_dice)
            return true;
    }
}

void crapsGameTest(const int number_of_plays)
{
    int number_of_wins = 0;
    for(int i = 0;i < number_of_plays;++i){
        if(crapsGame())
            number_of_wins++;
    }
    printf("%lf",(double)number_of_wins / number_of_plays);
}
void displayCollatz(int n)
{
   while(1) {
       if(n == 1){
           break;
       }
       if (n % 2 == 0) {
           n /= 2;
           printf("%d ", n);
       } else {
           n = 3 * n + 1;
           printf("%d ", n);
       }
   }
}
int getScale1()
{
    return rand() % 99 + 1;
}
int getScale2(int scale1)
{
    int scale2;
    while ((scale2 = rand() % 99 + 1) == scale1)
        ;
    return scale2;
}
int getScale3(int scale1,int scale2)
{
    int scale3;
    while ((scale3 = rand() % 99 + 1) == scale1 || scale3 == scale2)
        ;
    return scale3;
}

bool lottoGame1()
{
     int scale1 = getScale1();
     int scale2 = getScale2(scale1);
     int scale3 = getScale3(scale1,scale2);
     return  scale1 + scale2 + scale3 < 150;
}
void lotto_game1_test(const int number_of_plays)
{
    int number_of_wins = 0;
    for(int i = 0;i < number_of_plays;++i){
        if(lottoGame1())
            number_of_wins++;
    }
    printf("%lf",(double)number_of_wins / number_of_plays);
}

bool lottoGame2()
{
    int scale1 = getScale1();
    int scale2 = getScale2(scale1);
    int scale3 = getScale3(scale1,scale2);
    return isPrime(scale1 + scale2 + scale3);
}
void lotto_game2_test(const int number_of_plays)
{
    int number_of_wins = 0;
    for(int i = 0;i < number_of_plays;++i){
        if(lottoGame2())
            number_of_wins++;
    }
    printf("%lf",(double)number_of_wins / number_of_plays);
}
bool lottoGame3()
{
    int scale1 = getScale1();
    int scale2 = getScale2(scale1);
    int scale3 = getScale3(scale1,scale2);
    int max = Max(Max(scale1,scale2),scale3);
    int mid = Mid(scale1,scale2,scale3);
    int min = Min(Min(scale1,scale2),scale3);
    return max - min > mid;
}
void lotto_game3_test(const int number_of_plays)
{
    int number_of_wins = 0;
    for(int i = 0;i < number_of_plays;++i){
        if(lottoGame3())
            number_of_wins++;
    }
    printf("%lf",(double)number_of_wins / number_of_plays);
}
void printPrimeFactors(int val)
{
    int factor = 2;
    while(val != 1){
        if(val % factor == 0) {
            printf("%d ", factor);
            val /= factor;
        }
        else
            factor++;
    }
}
int getPrimeFactorsSum(int val)
{
    int sum = 0;
    int factor = 1;
    while(1){
        if(val % factor == 0)
            sum += factor;
        factor++;
        if(val / 2 < factor)
            break;
    }
    return sum;
}
bool isPerfect(const int val)
{
    return val == getPrimeFactorsSum(val);
}
int mypow(int a,int b)
{
    int result = 1;
    for(int i = 0;i < b;++i){
        result *= a;
    }

    return result;
}
bool isOkay(int val)
{
    int a = getHundredsDigit(val),b = getTensDigit(val),c = getOnesDigit(val);
    int rev = reverseNumber(val);
    if(rev <= val)
        return false;
    if(isPrime(rev) && isPrime(val) && isPrime(10 * a + b) && isPrime(10 * b + a) && isPrime(10 * b + c) && isPrime(10 * c + b))
        return true;
    return false;
}
int getPrimeIndex(const int val)
{
    int index = 0;
    for(int i = 0;i <= val;++i){
        if(isPrime(i)){
            index++;
        }
    }
    return index;
}
int getDigitsSum(int val)
{
    int sum = 0;
    while(val){
        sum += val % 10;
        val /= 10;
    }
    return sum;
}
int getDigitsCount(int val)
{
    int count = 0;
    do{
        count++;
        val /= 10;
    }while(val);

    return count;
}
void gSwap(void* vp1,void* vp2,size_t size)
{
    char* cp1 = vp1;
    char* cp2 = vp2;
    while (size--){
        char temp = *cp1;
        *cp1 = *cp2;
        *cp2 = temp;
    }
}
bool isArmstrong(const int val)
{
    int temp = val;
    int sum = 0;
    while(temp){
        int count = getDigitsCount(val);
        sum += mypow(val % 10,count);
        temp /= 10;
    }
    return val == sum;
}
bool isDecimalHarshad(int val)
{
    return val % getDigitsSum(val);
}
bool isFactorian(int val)
{
    int sum = 0, temp = val;
    do{
        sum += calculateFactorial(temp % 10);
        temp /= 10;
    }while(temp);
    return val == sum;
}
bool isPrime(const int val)
{
    if(val <= 1)
        return false;
    if(val % 2 == 0)
        return val == 2;
    if(val % 3 == 0)
        return val == 3;
    if(val % 5 == 0)
        return val == 5;
    if(val % 7 == 0)
        return val == 7;
    if(val % 11 == 0)
        return val == 11;
    for(int i = 13;i * i < val;i += 2)
        if(val % i == 0)
            return false;
    return true;
}

static bool isPrimeX(int val)
{
    while(1){
        if(!isPrime(val))
            return false;
        if(val / 10 == 0)
            return true;
        val = getDigitsSum(val);
    }
}
static bool isSuperPrime(const int val)
{
    return isPrime(val) && isPrime(getPrimeIndex(val));
}
int reverseNumber(int val)
{
    int result = 0;
    while (val){
        result *= 10;
        result += val % 10;
        val /= 10;
    }
    return result;
}
static void Operation()
{
    int sum = 0,min = INT_MAX,max = INT_MIN,count = 0;
    while(printf("Yeni bir deger girmek istiyor musun?")){
        int ch;
        while((ch = getchar()) != '1' && ch != '0')
            ;
        if('0'== ch)
            break;
        printf("Bir sayi giriniz?\n");
        int val;
        scanf("%d",&val);
        while(val > 100 || val < 0){
            printf("Gecersiz deger!\n");
            printf("Yeni bir deger giriniz?\n");
            scanf("%d",&val);
        }
        sum += val;
        count++;
        if(min > val)
            min = val;
        if(max < val)
            max = val;
    }

    printf("%d tane deger girildi\n",count);
    printf("Max : %d\n",max);
    printf("Min : %d\n",min);
    printf("Ortalama : %lf\n",(double)sum / count);
}

void Goldbach(const int val)
{
    for(int i = 0;i < val ;++i){
        for(int k = 0;k < val;++k){
            if(val == i + k && isPrime(i) && isPrime(k)) {
                printf("%d + %d\n", k, i);
                return;
            }
        }
    }
}
void GoldbachTest()
{
    printf("Bir sayi giriniz?\n");
    int val;
    scanf("%d",&val);
    Goldbach(val);
}

void printFactors(int val)
{
    int factor = 2;

    while(val){
        if(val % factor == 0) {
            val /= factor;
            printf("%d ",factor);
        } else{
            factor++;
        }
    }
}






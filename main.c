#include <stdio.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1024

int main() {
    //str  和 numberArray的长度一定要10000
    // 小于的话测试点6会过不去
    char str[10000];
    int strIndex = 0;
    int numberArray[10000];
    int zfArray[4];
    //数字下标
    int numberIndex = 0;
    //指数下标
    int zfIndex = 0;
    //大小标记位 0右移 1左移
    int bigTag = 0;
    //指数标记位
    int zsTag = 0;
    //指数数字
    int zsResult = 0;
    scanf("%s", &str);
    //计算一下有多长
    while (str[strIndex] != '\0') {
        strIndex++;
    }
    //for循环 从1 开始
    //0 是 +/-  不是数字
    for (int i = 1; i < strIndex; i++) {
        if (str[i] == '.') {
            //是小数点的时候就直接下一个循环
            continue;
        } else if (str[i] != 'E' && zsTag == 0) {
            //接收纯数字
            numberArray[numberIndex++] = str[i];
        } else if (zsTag == 1) {
            //是指数了
            //改变对应的指数正负标志位
            if (str[i] == '-') {
                bigTag = 1;
            } else if (str[i] == '+') {
                bigTag = 0;
            } else {
                //指数的数字数组
                zfArray[zfIndex++] = str[i];
            }
        } else {
            //这里是E触发的 且只会触发这一次
            //+2就直接到数字了
            i + 2;
            //改变标志位，该指数了
            zsTag = 1;
        }
    }
    //如果是负数就输出-
    if (str[0] == '-') {
        printf("-");
    }
    //计算指数的这个数字是多少 循环要用到
    for (int k = 0; k < zfIndex; ++k) {
        int num = zfArray[k] - '0';
        zsResult = zsResult * 10 + num;
    }
    //指数为0就原样输出
    if (zsResult == 0) {
        for (int j = 0; j < numberIndex; ++j) {
            printf("%c", numberArray[j]);
        }
        return 0;
    }
    //指数为-
    if (bigTag) {
        //左移
        //先输出0
        for (int i = 0; i < zsResult; i++) {
            if (i == 0) {
                printf("0.");
            } else {
                printf("0");
            }
        }
        //然后输出数
        for (int j = 0; j < numberIndex; j++) {
            printf("%c", numberArray[j]);
        }
    } else {
        //指数为+
        //这是往右移动小数点
        //这里对指数循环
        //不需要打小数点
        //这个判断是因为 判断一下是否需要小数点，
        //意思就是指数的数字 是否大于数字的长度，是的话就不需要小数点了
        //不是的话 就要输出小数点，
        //numberIndex-是因为，计算的时候只需要计算小数点后的数字
        //不需要计算小数点之前的数字 所以-1
        if (zsResult >= numberIndex - 1) {
            for (int j = 0; j < numberIndex; ++j) {
                printf("%c", numberArray[j]);
            }
            for (int i = 0; i < zsResult - numberIndex + 1; ++i) {
                printf("0");
            }
        } else {
            //需要打小数点
            for (int j = 0; j < numberIndex; j++) {
                printf("%c", numberArray[j]);
                if (j == zsResult) {
                    printf(".");
                }
            }
        }
    }
    return 0;
}

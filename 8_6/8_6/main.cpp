#include <stdio.h>
/*【問題】
メモリ確保を使用し、
1000個の配列を確保して、
その配列に0～999を設定するプログラムを作成してください。
newとdeleteで配列を確保する処理を、
クラスにしてデストラクタで自動でdeleteが呼ばれるようにしてください。
*/
class Array
{
    //
public:
    Array() {}
    //配列確保
    void Create(int num)
    {
        newArray = new int[num];
    };

    void Set(int num, int num1)
    {
        //配列のサイズ確認
        if (num > miniSize && num < maxSize)
        {
            newArray[num] = num1;
        }
        else
        {
            printf("例外\n");
        }
    };

    int Get(int num)
    {
        if (num > miniSize && num < maxSize)
        {
            return newArray[num];
        }
        else
        {
            printf("例外\n");
        }
    };

    ~Array()
    {
        delete[] newArray;
        newArray = nullptr;
    }

private:
    int* newArray = nullptr;
    int miniSize = -1;//サイズ確認
    int maxSize = 1000;
};

int main() 
{
    //配列に0～999を設定する
    Array array;
    array.Create(1000);

    for (int i = 0; i < 1000; ++i)
    {
        array.Set(i, i);
    }

    for (int i = 0; i < 1000; ++i)
    {
        printf("num = %d\n", array.Get(i));
    }

    //0かｒ999以外 配列外参照のチェック
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}
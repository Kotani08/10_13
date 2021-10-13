#include <stdio.h>
/*�y���z
�������m�ۂ��g�p���A
1000�̔z����m�ۂ��āA
���̔z���0�`999��ݒ肷��v���O�������쐬���Ă��������B
new��delete�Ŕz����m�ۂ��鏈�����A
�N���X�ɂ��ăf�X�g���N�^�Ŏ�����delete���Ă΂��悤�ɂ��Ă��������B
*/
class Array
{
    //
public:
    Array() {}
    //�z��m��
    void Create(int num)
    {
        newArray = new int[num];
    };

    void Set(int num, int num1)
    {
        //�z��̃T�C�Y�m�F
        if (num > miniSize && num < maxSize)
        {
            newArray[num] = num1;
        }
        else
        {
            printf("��O\n");
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
            printf("��O\n");
        }
    };

    ~Array()
    {
        delete[] newArray;
        newArray = nullptr;
    }

private:
    int* newArray = nullptr;
    int miniSize = -1;//�T�C�Y�m�F
    int maxSize = 1000;
};

int main() 
{
    //�z���0�`999��ݒ肷��
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

    //0����999�ȊO �z��O�Q�Ƃ̃`�F�b�N
    printf("num = %d\n", array.Get(-1));
    printf("num = %d\n", array.Get(1000));
}
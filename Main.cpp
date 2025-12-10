#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion += count;
    *p_MPPotion += count;
}

int main() {
    int status[4] = { };//HP,MP,공격력,방어력
    int num;
    int HPpotion = 0;
    int MPpotion = 0;
    int level = 1;
    int exp = 1;
    bool isContinue = true;
    while (isContinue)
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];
        if (status[0] <= 50 || status[1] <= 50) {
            cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
        }
        else {
            isContinue = false;
        }
    }
    isContinue = true;
    cout << "공격력과 방어력을 입력해주세요: ";
    cin >> status[2] >> status[3];
    setPotion(5, &HPpotion, &MPpotion);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 현재 능력치\n6. Level Up\n0. 나가기" << endl;
    while (isContinue) {
        cout << "번호를 선택해주세요: ";
        cin >> num;
        switch (num)
        {
        case 1:
            if (HPpotion <= 0) {
                cout << "포션이 부족합니다." << endl;
            }
            else {
                status[0] += 20;
                HPpotion -= 1;
                cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 HP : " << status[0] << endl;
                cout << "남은 포션 수: " << HPpotion << endl;
            }
            break;
        case 2:
            if (MPpotion <= 0) {
                cout << "포션이 부족합니다." << endl;
            }
            else {
                status[1] += 20;
                MPpotion -= 1;
                cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 MP : " << status[1] << endl;
                cout << "남은 포션 수: " << MPpotion << endl;
            }
            break;
        case 3:
            status[2] *= 2;
            cout << "* 공격력이 2배로 증가되었습니다." << endl;
            cout << "현재 공격력: " << status[2] << endl;
            break;
        case 4:
            status[3] *= 2;
            cout << "* 방어력 2배로 증가되었습니다." << endl;
            cout << "현재 방어력: " << status[3] << endl;
            break;
        case 5:
            cout << "* HP : " << status[0] << ", MP : " << status[1] << ", 공격력 : " << status[2] << ", 방어력 : " << status[3] << ", 레벨: " << level << endl;
            cout << "남은 HP/MP 포션 수 : " << HPpotion << "/" << MPpotion << endl;
            break;
        case 6:
            exp++;
            if (exp >= 6) {
                exp = 1;
                level += 1;
                setPotion(1, &HPpotion, &MPpotion);
                cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
                cout << "남은 HP/MP 포션 수 : " << HPpotion << "/" << MPpotion << endl;
            }
            else {
                cout << "*다음 레벨까지 : " << exp << "/6" << endl;
            }

            break;
        case 0:
            cout << "프로그램을 종료합니다." << endl;
            isContinue = false;
            break;
        default:
            break;
        }

    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerHealth = 200;// 자신의 초기 체력 설정
	 
    int enemyHealth;
    int ch, damage, heal;
    int enemiesDefeated;
    srand(time(NULL)); // 랜덤 시드 설정

    printf("인생 한방 전투\n");
    printf("   0 |      | 0    \n");
    printf("  /|\\+      +/|\\   \n");
    printf("  / \\        / \\   \n");

    while (playerHealth > 0) {
        enemyHealth = 200; // 적의 초기 체력 설정

        while (enemyHealth > 0) {
            printf("\n당신의 턴입니다.\n");
            printf("1. 강력한 공격 (1d100 데미지)\n");
            printf("2. 회복 (1d200 회복)\n");
            printf("공격이나 회복을 할것: ");
            scanf("%d", &ch);

            if (ch == 1) {
                damage = (rand() % 100) + 1; // 1~100 사이의 랜덤 데미지
                enemyHealth -= damage;
                printf("당신이 적에게 %d의 데미지를 입혔습니다. (적의 체력: %d)\n", damage, enemyHealth);
            } else if (ch == 2) {
                heal = (rand() % 150) + 1; // 1~150 사이의 랜덤 회복
                playerHealth += heal;
                if (playerHealth > 500) {
                    playerHealth = 500; // 최대 체력 500으로 제한
                }
                printf("당신이 %d만큼 회복했습니다. (당신의 체력: %d)\n", heal, playerHealth);
            } else {
                printf("잘못된 선택이다\n");
                continue;
            }

            if (enemyHealth <= 0) {
                printf("적을 죽였다\n");
                enemiesDefeated++;
                break;
            }

            printf("\n적의 턴입니다.\n");
            if (rand() % 2 == 0) {
                // 적의 공격
                damage = (rand() % 100) + 1; // 1~100 사이의 랜덤 데미지
                playerHealth -= damage;
                printf("적이 당신에게 %d의 데미지를 입혔습니다. (당신의 체력: %d)\n", damage, playerHealth);
            } else {
                // 적의 회복
                heal = (rand() % 100) + 1; // 1~100 회복 
                enemyHealth += heal;
                if (enemyHealth > 500) {
                    enemyHealth = 500; // 적의 체력을 500으로 제한
                }
                printf("적이 %d만큼 회복했습니다. (적의 체력: %d)\n", heal, enemyHealth);
            }

            if (playerHealth <= 0) {
                printf("패배\n");
                printf("당신이 죽인 적의 수: %d\n", enemiesDefeated);
                break;
            }
        }
    }

    return 0;
}


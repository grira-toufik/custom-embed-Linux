#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    double uptime;

    printf("=========================================\n");
    printf("  Embedded Linux System Monitor (ARM)    \n");
    printf("=========================================\n");

    // قراءة مدة تشغيل النظام من النواة مباشرة
    fp = fopen("/proc/uptime", "r");
    if (fp != NULL) {
        if (fscanf(fp, "%lf", &uptime) == 1) {
            printf("[+] System Uptime: %.2f seconds\n", uptime);
        }
        fclose(fp);
    } else {
        perror("Error reading uptime");
    }

    printf("[+] Status: Running natively on Target!\n");
    return 0;
}

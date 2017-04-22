#include <stdio.h>
#include <windows.h>
#include <wininet.h>
#define MAXBLOCKSIZE 1024
#pragma comment(lib, "wininet.lib")

void download(const char *Url, const char *save_as) {
    /*��Urlָ��ĵ�ַ���ļ����ص�save_asָ��ı����ļ�*/
    byte Temp[MAXBLOCKSIZE];
    ULONG Number = 1;

    FILE *stream;
    HINTERNET hSession =
        InternetOpen("RookIE/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (hSession != NULL) {
        HINTERNET handle2 = InternetOpenUrl(hSession, Url, NULL, 0,
                                            INTERNET_FLAG_DONT_CACHE, 0);
        if (handle2 != NULL) {
            if ((stream = fopen(save_as, "wb")) != NULL) {
                while (Number > 0) {
                    InternetReadFile(handle2, Temp, MAXBLOCKSIZE - 1, &Number);
                    fwrite(Temp, sizeof(char), Number, stream);
                }
                fclose(stream);
            }
            InternetCloseHandle(handle2);
            handle2 = NULL;
        }
        InternetCloseHandle(hSession);
        hSession = NULL;
    }
}

void lf2crlf(const char *file_in, const char *file_out) {
    FILE *in, *out;
    if ((in = fopen(file_in, "rb")) != NULL &&
        (out = fopen(file_out, "wb")) != NULL) {
        char c;
        while ((c = fgetc(in)) != EOF) {
            if (c == '\n') {
                fputc('\r', out);
            }
            fputc(c, out);
        }
        fclose(in);
        fclose(out);
    }
}

int main(int argc, char *argv[]) {
    printf("���������� hosts �ļ�...\n");
    download("https://raw.githubusercontent.com/racaljk/hosts/master/hosts",
             ".\\hosts.temp");
    printf("hosts �ļ��������.\n");

    printf("��ʼת�� hosts �ļ�...\n");
    lf2crlf(".\\hosts.temp", ".\\hosts");
    printf("hosts �ļ����.\n");

    printf("ɾ����ʱ�ļ�...\n");
    system("del hosts.temp");
    printf("ɾ�����...\n");

    printf("���ֶ��ƶ���ϵͳĿ¼.\n");
    system("explorer.exe /select,.\\");
    system("explorer.exe /select,%SystemRoot%\\System32\\drivers\\etc\\hosts");

    
    return 0;
}
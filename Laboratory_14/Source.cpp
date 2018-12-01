#define CURL_STATICLIB 
#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <iostream> 

#ifdef _WIN64 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#elif _WIN32 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#endif 

/*
https://github.com/curl/curl.git https://github.com/curl/curl
1. ��������� �� ������ ������ ������� ������������ VS (x64 Native tools)
2. � ������� CD /D <����> ������� � ����� curl
3. ��������� buildconf.bat (������� buildconf) - ��������������� ��������� ���������� ����� � ��������� ����������� ������
4. ������� � ������� CD � winbuild
5. ��������� ������ �� ����� ������� BUILD.WINDOWS.txt
*/

static int writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size *nmemb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	CURL *curl = nullptr;
	std::string buffer;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.sberbank.ru/ru/person");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	int c = buffer.find("<div class=\"kit - heading kit - heading_s pr - currency__header\">USD<\/div>");
	for (int i = c; i <= c + 10; i++)
		std::cout << buffer[i];
	getchar();
	return 0;
}
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
1. Запустить от учётки админа консоль разработчика VS (x64 Native tools)
2. С помощью CD /D <путь> перейти в папку curl
3. Выполнить buildconf.bat (команда buildconf) - предварительные настройки переменных среды и генерация необходимых файлов
4. Перейти с помощью CD в winbuild
5. Выполнить строку из файла справки BUILD.WINDOWS.txt
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
	CURL *curl = nullptr;
	std::string buffer;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.sravni.ru/bank/sberbank-rossii/valjuty/moskva/");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	std::cout << buffer << std::endl;
	getchar();
	return 0;
}
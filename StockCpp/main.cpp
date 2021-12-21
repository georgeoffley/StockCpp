#include <string>
#include <iostream>

#include <curl/curl.h>

using std::cout;
using std::cin;
using std::string;

//https://curl.se/libcurl/c/altsvc.html

int main()
{
	CURL* curl = curl_easy_init();

	struct curl_slist* list = NULL;

	string API_KEY;
	string SECRET_KEY;

	cout << "Enter API Key" << '\n';
	cin >> API_KEY;

	cout << "Enter Secret Key" << '\n';
	cin >> SECRET_KEY;

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://paper-api.alpaca.markets/v2/account");

		list = curl_slist_append(list, std::printf("APCA-API-KEY-ID: %s", API_KEY));
		list = curl_slist_append(list, std::printf("APCA-API-SECRET-KEY: %s", SECRET_KEY));

		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

		curl_easy_perform(curl);

		curl_slist_free_all(list);
	}
}
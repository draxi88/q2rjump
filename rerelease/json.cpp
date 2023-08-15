//if include <json/value.h> line fails (latest kernels), try also:
//  #include <jsoncpp/json/json.h>
#include "json/json.h"
#include "json/config.h"
#include <fstream>

static Json::Value parseJson(const char* jsonString)
{
	Json::CharReaderBuilder reader;
	reader["allowSpecialFloats"] = true;
	Json::Value		  json;
	JSONCPP_STRING	  errs;
	std::stringstream ss(jsonString, std::ios_base::in | std::ios_base::binary);

	if (!Json::parseFromStream(reader, ss, &json, &errs))
		gi.Com_ErrorFmt("Couldn't decode JSON: {}", errs.c_str());

	if (!json.isObject())
		gi.Com_Error("expected object at root");

	return json;
}

void ReadJsonTest() {
	std::ifstream people_file("people.json", std::ifstream::binary);
	Json::Value people;
	people_file >> people;
}
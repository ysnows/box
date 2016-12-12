//
//  NetUtils.h
//  box
//
//  Created by 咸光金 on 2016/12/12.
//
//

#ifndef NetUtils_h
#define NetUtils_h

#include <stdio.h>
using namespace std;

#include "network/HttpClient.h"
using namespace cocos2d::network;

#include "json/rapidjson.h"
#include "json/document.h"

using namespace rapidjson;

#define BASE_URL "http://123.57.237.129/public/api/"

#define OK 200 
#define FAIL 201

void hGet(string url,const ccHttpRequestCallback &callback);

void hPost(string url,string post_data,const ccHttpRequestCallback &callback);



#endif /* NetUtils_*/

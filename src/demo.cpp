#include "speech.h"
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
#include "image_classify.h"

using namespace std;

//解析json
void parseJson(const std::string& json_str) {
    Json::Reader reader;
    Json::Value root;
    bool parsingSuccessful = reader.parse(json_str, root);
    if (!parsingSuccessful) {
        // 解析失败，输出错误信息
        std::cerr << "Failed to parse JSON: " << reader.getFormattedErrorMessages() << std::endl;
        return;
    }

    // 访问和输出数据
    if (root.isMember("log_id")) {
        std::cout << "log_id: " << root["log_id"].asInt64() << std::endl;
    }
    if (root.isMember("result_num")) {
        std::cout << "result_num: " << root["result_num"].asInt() << std::endl;
    }

    // 访问result数组（如果有的话）
    if (root.isMember("result") && root["result"].isArray()) {
        const Json::Value& resultArray = root["result"];
        for (const auto& resultObj : resultArray) {
            if (resultObj.isMember("has_calorie")) {
                std::cout << "has_calorie: " << resultObj["has_calorie"].asBool() << std::endl;
            }
            if (resultObj.isMember("name")) {
                std::cout << "name: " << resultObj["name"].asString().c_str() << std::endl;
            }
            if (resultObj.isMember("score")) {
                std::cout << "score: " << resultObj["score"].asString() << std::endl;
            }
        }
    }
}

int main() {

    std::string app_id = "";
    std::string api_key = "";
    std::string secret_key = "";

    aip::Imageclassify client(app_id, api_key, secret_key);

    Json::Value result;
    //1.创建工厂对象
    Json::CharReaderBuilder ReaderBuilder;
    ReaderBuilder["emitUTF8"] = true;//utf8支持,不加这句,utf8的中文字符会编程\uxxx

    std::string image;
    aip::get_file_content("../img/img_2.png", &image);

// 调用菜品识别
    result = client.animal_detect(image, aip::null);

    cout << result.toStyledString()<< endl;

        //解析json
    parseJson(result.toStyledString());

// 如果有可选参数
    std::map<std::string, std::string> options;
    options["top_num"] = "3";
    options["filter_threshold"] = "0.7";
    options["baike_num"] = "5";





}



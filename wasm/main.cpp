#include <emscripten.h>
#include <iostream>

extern "C" {
// 定义用于获取 WiFi 信息的函数
EMSCRIPTEN_KEEPALIVE
const char* getWifiInfo() {
    // 在实际应用中，您可以使用浏览器的 Web API 或其他库来获取 WiFi 信息
    // 这里我们简单地返回一个示例信息
    return "Connected to WiFi: MyWiFiNetwork";
}

// 示例函数，用于执行其他任务
EMSCRIPTEN_KEEPALIVE
void performTask() {
    // 在这里可以执行其他任务
    std::cout << "Task performed!" << std::endl;
}
}
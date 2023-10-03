#include <iostream>
#include <fstream>

struct WifiInfo {
    std::string ssid;
    int numOfConnectedDevices;
};

extern "C" {
WifiInfo getWifiInfo() {
    // 获取WiFi信息的逻辑
    std::ifstream wifiInfoFile("/proc/net/wireless");
    std::string wifiInfo;
    if (wifiInfoFile.is_open()) {
        std::getline(wifiInfoFile, wifiInfo);
        wifiInfoFile.close();
    }

    // 获取已连接设备数量的逻辑
    int numOfConnectedDevices = 0;
    // 在这里实现设备数量的获取逻辑

    WifiInfo result;
    result.ssid = wifiInfo;
    result.numOfConnectedDevices = numOfConnectedDevices;
    return result;
}
}
